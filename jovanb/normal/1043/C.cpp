#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int change[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    string s;
    cin >> s;
    int n = s.size();
    char mn = s[0];
    for(int i=1; i<n; i++){
        if(s[i] <= mn){
            mn = s[i];
        }
        else{
            change[i-1] = 1^change[i-1];
            change[i] = 1;
        }
    }
    change[n-1] = 1^change[n-1];
    for(int i=0; i<n; i++) cout << change[i] << " ";
    return 0;
}