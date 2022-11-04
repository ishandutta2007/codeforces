#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct Card{
	int s[2],idx,sr[2];
};

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	vector<Card>srt[2];
	srt[0].resize(n);
	for(int i=0;i<n;++i){
		cin>>srt[0][i].s[0]>>srt[0][i].s[1];
		srt[0][i].idx=i;
		srt[0][i].sr[1]=max(srt[0][i].s[0],srt[0][i].s[1]);
		srt[0][i].sr[0]=min(srt[0][i].s[0],srt[0][i].s[1]);
	}
	int mxmn=0;
	for(int i=0;i<n;++i)mxmn=max(mxmn,srt[0][i].sr[0]);
	for(int i=0;i<n;++i)if(srt[0][i].sr[1]<mxmn){cout<<-1<<endl;return 0;}
	for(int i=0;i<n;++i){
		for(int j=0;j<2;++j)if(srt[0][i].s[j]==srt[0][i].sr[0])srt[0][i].s[j]-=mxmn;
		srt[0][i].sr[0]-=mxmn;
	}
	srt[1]=srt[0];
	for(int i=0;i<2;++i)
		sort(srt[i].begin(),srt[i].end(),[&](auto x,auto y){
			return abs(x.sr[i])>abs(y.sr[i]);
		});
	int res=0;
	vector<int>dead(n);
	int bounds[2][2]={{0,0},{0,0}};
	while(srt[0].size()){
		auto cbtm=srt[0].back();srt[0].pop_back();
		for(int i=0;i<2;++i)bounds[0][i]=cbtm.sr[i];
		dead[cbtm.idx]=1;
		int cnt[2]={1,0},f[2]={cbtm.sr[1]==cbtm.s[0],0},done=1;
//		cerr<<"init "<<cbtm.s[0]<<" "<<cbtm.s[1]<<endl;
		while(done){
			done=0;
			for(int i=0;i<2;++i){
				while(srt[i].size()&&(dead[srt[i].back().idx]||(abs(srt[i].back().sr[i])<abs(bounds[!i][i])))){
					if(!dead[srt[i].back().idx]){
//						cerr<<"bcs "<<srt[i].back().sr[i]<<" "<<bounds[!i][i]<<endl;
//						cerr<<"putting to "<<i<<" "<<srt[i].back().s[0]<<" "<<srt[i].back().s[1]<<endl;
						if(abs(srt[i].back().sr[!i])<abs(bounds[i][!i])){cout<<-1<<endl;return 0;}
						bounds[i][!i]=srt[i].back().sr[!i];
						++cnt[i];f[i]+=srt[i].back().sr[1]==srt[i].back().s[0];
						done=1;
					}
					dead[srt[i].back().idx]=1;srt[i].pop_back();
				}
			}
		}
//		cerr<<cnt[0]<<" "<<cnt[1]<<endl;
//		cerr<<f[0]<<" "<<f[1]<<endl;
		res+=min(cnt[0]-f[0]+f[1],f[0]+cnt[1]-f[1]);
		while(srt[0].size()&&dead[srt[0].back().idx])srt[0].pop_back();
	}
	cout<<res<<endl;
}