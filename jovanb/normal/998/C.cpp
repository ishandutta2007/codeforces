#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    string s;
    ll n, a, b;
    cin >> n >> a >> b;
    cin >> s;
    ll brk=0;
    if(s[0] == '0') brk++;
    for(int i=1; i<n; i++){
        if(s[i] == '0' && s[i-1] != '0') brk++;
    }
    if(brk == 0){cout << 0; return 0;}
    cout << min(brk*b, (brk-1)*a+b);
    return 0;
}