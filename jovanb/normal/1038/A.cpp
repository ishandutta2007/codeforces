#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int br[1000];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(auto c : s){
        br[c-'A']++;
    }
    int mn = n;
    for(int i=0; i<k; i++) mn = min(mn, br[i]);
    cout << mn*k;
    return 0;
}