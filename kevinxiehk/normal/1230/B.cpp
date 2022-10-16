#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;
    int n,k;
    cin>>n>>k>>s;
    if(n==1&&k==1){cout<<"0"<<endl;return 0;}
    int t=0;
    while(k&&t<n){
        if(t==0){
            if(s[t]!='1')k--;
            s[t]='1';
        }
        else {
            if(s[t]!='0')k--;
            s[t]='0';
        }
        t++;
    }
    cout<<s<<endl;
	return 0;
}