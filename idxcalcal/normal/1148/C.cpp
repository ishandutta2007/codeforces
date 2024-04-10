#include<bits/stdc++.h>
#define ri register int
using namespace std;
inline int read(){
	#define gc getchar
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
	#undef gc
}
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=3e5+5;
int n,a[N],pos[N];
vector<pii>ans;
inline void Swap(int x,int y){
	if(x==y)return;
	ans.push_back(pii(x,y));
	pos[a[x]]=y;
	pos[a[y]]=x;
	swap(a[x],a[y]);
}
int main(){
	n=read();
	for(ri i=1;i<=n;++i)a[i]=read(),pos[a[i]]=i;
	for(ri i=1;i<=n/2;++i){
		if(pos[i]!=i){
			if(pos[i]<=n/2)Swap(pos[i],n);
			else{
				if(pos[i]!=n){
					int t=pos[i];
					Swap(1,pos[i]);
					Swap(1,n);
					Swap(1,t);				
				}
			}
			Swap(i,pos[i]);
		}
	}
	for(ri i=n/2+1;i<=n;++i){
		if(pos[i]!=i){
			int t=pos[i];
			Swap(1,pos[i]);
			Swap(1,i);
			Swap(1,t);
		}
	}
	cout<<ans.size()<<'\n';
	for(ri i=0;i<ans.size();++i)cout<<ans[i].fi<<' '<<ans[i].se<<'\n';
	return 0;
}