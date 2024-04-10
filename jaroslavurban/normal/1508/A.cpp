#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		string s[3];
		for(int i=0;i<3;++i)cin>>s[i];
		string res;
		bool done=false;
		for(int i=0;!done&&i<2;++i){
			for(int j=0;!done&&j<3;++j)
				for(int k=j+1;!done&&k<3;++k){
					int cnt[2]={count(s[j].begin(),s[j].end(),'0'+i),
											count(s[k].begin(),s[k].end(),'0'+i)};
					if(cnt[0]>=n&&cnt[1]>=n){
						int u=0,v=0;
						while(u+v<4*n){
							if(u==2*n){
								while(v<2*n){
									res+=s[k][v];
									++v;
								}
							}
							else if(v==2*n){
								while(u<2*n){
									res+=s[j][u];
									++u;
								}
							}
							else if(s[j][u]==i+'0'&&s[k][v]==i+'0'){
								res+=i+'0';
								++u;++v;
							}else{
								while(u<2*n&&v<2*n&&s[j][u]!=i+'0'){
									res+=s[j][u];++u;
								}
								while(u<2*n&&v<2*n&&s[k][v]!=i+'0'){
									res+=s[k][v];++v;
								}
							}
						}
						done=true;
					}
				}
		}
		assert(res.size()<=3*n);
		cout<<res<<endl;
	}
}