#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;
 
    string s;
    cin >> s;
    ll n = s.size();
    ll wait=0;
    ll i=0;
    ll t=0, brr=0;
    while(i < n && s[i] == 'F') i++;
    for(; i<n; i++){
        if(s[i] == 'F'){
           t = brr+wait;
           wait++;
        }
        else{
            wait--;
            brr++;
        }
        wait = max(0LL, wait);
    }
    cout << t;
    return 0;
}