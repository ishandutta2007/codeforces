#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long

int q,n;
char s[100001],t[100001];
int c[1000001];
void update(int ind,int num){
	for(;ind<=n;ind+=ind&-ind)c[ind]+=num;
}
int query(int ind){
	int tot=0;
	for(;ind;ind-=ind&-ind)tot+=c[ind];
	return tot;
}
std::vector<int>pos[26];
signed main(){
	scanf("%lld",&q);
	for(int fd=1;fd<=q;++fd){
		scanf("%lld",&n);
		scanf("%s%s",s+1,t+1);
		for(int i=0;i<=n;++i)c[i]=0;
		for(int i=1;i<=n;++i)update(i,1);
		for(int i=0;i<26;++i)pos[i].clear();
		for(int i=n;i;--i)pos[s[i]-'a'].push_back(i);
		int ans=1e18;
		int now=0;
		for(int i=1;i<=n;++i){
			int tem=1e18;
			for(int j=0;j<26;++j)
				if(j<t[i]-'a'&&!pos[j].empty())tem=std::min(tem,query(pos[j].back()-1));
			ans=std::min(ans,now+tem);
			if(pos[t[i]-'a'].empty())break;
			now+=query(pos[t[i]-'a'].back()-1);
			update(pos[t[i]-'a'].back(),-1);
			pos[t[i]-'a'].pop_back();
		}
		if(ans==1e18)puts("-1");
		else printf("%lld\n",ans);
	}
}