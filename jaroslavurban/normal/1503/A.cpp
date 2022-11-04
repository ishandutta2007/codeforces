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
		int zeros=count(s.begin(),s.end(),'0');
		int ones=n-zeros;
		if(zeros&1){cout<<"NO\n";continue;}
		int open=0;
		int cnt[2]={0,0};
		string res[2]={string(n,')'),string(n,')')};
		bool pos=true;
		int done1=0;
		for(int i=0;i<n;++i){
			if(s[i]=='1'){
				if(done1<ones/2){
					++done1;
					res[0][i]=res[1][i]='(';
					++cnt[0];++cnt[1];
				}else{
					res[0][i]=res[1][i]=')';
					--cnt[0];--cnt[1];
				}
			}
			else{
				if(cnt[0]>=cnt[1]){
					--cnt[0];++cnt[1];
					res[0][i]=')';
					res[1][i]='(';
				}
				else{
					--cnt[1];++cnt[0];
					res[1][i]=')';
					res[0][i]='(';
				}
			}
			if(cnt[0]<0||cnt[1]<0)pos=false;
		}
		if(cnt[0]!=0||cnt[1]!=0)pos=false;
		if(pos)cout<<"YES\n"<<res[0]<<"\n"<<res[1]<<"\n";
		else cout<<"NO\n";
	}
}