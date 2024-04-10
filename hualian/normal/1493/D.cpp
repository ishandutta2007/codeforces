#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+9;
const int mod=1e9+7;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,q;
int p[N],len,vis[N],del[N];
void init(){
	for(int i=2;i<N;i++){
		if(!vis[i])p[++len]=i,del[i]=len;
		for(int j=1;j<=len&&p[j]*i<N;j++){
			vis[p[j]*i]=1;
			del[p[j]*i]=j;
			if(i%p[j]==0)break;
		}
	}
}
int ans=1;
int a[N];
map<int,int>cnt[N];
map<int,int>had[N];
int mn[N];
signed main(){
	init();
	n=read(),q=read();
	for(int i=1;i<=len;i++)cnt[i][0]=n;
	for(int i=1;i<=n;i++){
		int x=read();
		while(x!=1){
			int j=del[x];
			int now=had[i][j];// 
			cnt[j][had[i][j]]--;//jprime 
			had[i][j]++;//prime 
			cnt[j][had[i][j]]++;//jprime 
			if(mn[j]==now){// 
				while(cnt[j][mn[j]]==0)mn[j]++,ans=ans*p[j]%mod;
			}
			x/=p[j];
		}
	}
	while(q--){
		int i=read(),x=read();
		while(x!=1){
			int j=del[x];
			int now=had[i][j];
			cnt[j][had[i][j]]--; 
			had[i][j]++;
			cnt[j][had[i][j]]++; 
			if(mn[j]==now){
				while(cnt[j][mn[j]]==0)mn[j]++,ans=ans*p[j]%mod;
			}
			x/=p[j];
		}
		printf("%lld\n",ans);
	}
	return 0;
}