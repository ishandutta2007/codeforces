#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;
    int b0 = 0, b1 = 0;
    for(auto c : s){
        if(c == 'z') b0++;
        if(c == 'n') b1++;
    }
    while(b1--) cout << 1 << " ";
    while(b0--) cout << 0 << " ";
    return 0;
}