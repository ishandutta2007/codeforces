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
		bool pal=true;
		int cnt=count(s.begin(),s.end(),'0');
		for(int i=0;i<n/2;++i)if(s[i]!=s[n-i-1])pal=false;
		if(pal){
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
		else if(n&1&&cnt==2&&s[n/2]=='0')cout<<"DRAW\n";
		else cout<<"ALICE\n";
	}
}