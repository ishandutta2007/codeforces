#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		string s;cin>>s;
		int cnt=count(s.begin(),s.end(),'0');
		if(cnt==0)cout<<"DRAW\n";
		else{
			if(n&1){
				if(s[n/2]=='0'){
					if(cnt==1)cout<<"BOB\n";
					else cout<<"ALICE\n";
				}else{
					cout<<"BOB\n";
				}
			}
			else{
				cout<<"BOB\n";
			}
		}
	}
}