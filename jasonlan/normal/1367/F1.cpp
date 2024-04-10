#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=201000;
int n;
int a[maxn],rk[maxn];
vector <int> v[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void proc(){
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=rk[i]=read();
	sort(rk+1,rk+1+n);
	int m=unique(rk+1,rk+1+n)-rk-1;
	for(int i=1;i<=m;++i)
		v[i].clear();
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(rk+1,rk+1+m,a[i])-rk;
		v[a[i]].push_back(i);
	}
	int ans=n,pos=0,cnt=0;
	for(int i=1,sz;i<=m;++i){
		sz=v[i].size();
		if(v[i][0]<pos){
			cnt+=v[i].end()-lower_bound(v[i].begin(),v[i].end(),pos);
			ans=min(ans,n-cnt);
			cnt=upper_bound(v[i-1].begin(),v[i-1].end(),v[i][0])-v[i-1].begin();
		}
		cnt+=sz;
		pos=v[i][sz-1]+1;
	}
	ans=min(ans,n-cnt);
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while(T--)proc();
	return 0;
}