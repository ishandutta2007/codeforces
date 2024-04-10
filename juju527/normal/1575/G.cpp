#include <bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int maxn=1e5+5,mod=1e9+7;
int n,w;
int a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
bool bj[maxn];
int len,p[maxn],phi[maxn];
void pre(){
	int lim=max(w,n);
	phi[1]=1;
	for(int i=2;i<=lim;i++){
		if(!bj[i])p[++len]=i,phi[i]=i-1;
		for(int j=1;1ll*p[j]*i<=lim&&j<=len;j++){
			bj[i*p[j]]=1;
			if(i%p[j]==0){phi[i*p[j]]=phi[i]*p[j];break;}
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
	return ;
}
int cnt[maxn];
vector<int> d[maxn],G;
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),w=max(w,a[i]);
    pre();
	for(int i=1;i<=w;++i)for(int j=i;j<=w;j+=i)d[j].eb(i);
	int res=0;
	for(int i=1;i<=n;++i){
		int sum=0;
		G.clear();
		for(int j=i;j<=n;j+=i){
			for(size_t k=0;k<d[a[j]].size();++k){
				int g=d[a[j]][k];
				if(!cnt[g])G.eb(g);
				cnt[g]++;
			}
		}
		for(size_t j=0;j<G.size();++j){
			int g=G[j];
			sum=add(sum+1ll*phi[g]*cnt[g]*cnt[g]%mod);
			cnt[g]=0;
		}
		res=add(res+1ll*sum*phi[i]%mod);
	}
	printf("%d\n",res);
	return 0;
}