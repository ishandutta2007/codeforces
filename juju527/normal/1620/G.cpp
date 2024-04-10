#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn=25,maxs=(1<<23)+5,maxl=2e4+5,mod=998244353;
char s[maxl];
int cnt[26][maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int f[maxs];
ll g[maxs];
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
pair<int,int> p[maxn];
int rk[26][maxn];
void FWT(int lim,int *f){
	for(int mid=1;mid<lim;mid<<=1)
		for(int j=0;j<lim;j+=(mid<<1))
			for(int k=0;k<mid;k++)
				f[j+k+mid]=add(f[j+k+mid]+f[j+k]);
	return ;
}
int t[maxs],pre[maxs];
int main(){
    int n;
	n=read();
	for(int i=0;i<n;i++){
		scanf("%s",s);
		int len=strlen(s);
		for(int j=0;j<len;j++)cnt[s[j]-'a'][i]++;
	}
	int S=(1<<n)-1;
	for(int c=0;c<26;c++){
		for(int i=0;i<n;i++)p[i]=make_pair(cnt[c][i],i);
		sort(p,p+n);
		for(int i=0;i<n;i++)rk[c][i]=p[i].se;
	}
	g[S]=1;
	for(int c=0;c<26;c++){
		for(int s=1;s<=S;s++)t[s]=0,pre[s]=-1,f[s]=g[s]%mod,g[s]=0;
		for(int i=0;i<n;i++){
			int x=rk[c][i],lim1=(1<<n-x-1),lim2=(1<<x+1),cur=cnt[c][x];
			for(int s1=0;s1<lim1;s1++){
				for(int s2=(1<<x);s2<lim2;s2++){
					int s=(s1<<x+1)|s2,st=s^t[s];
					if(!f[s])continue;
					g[st]+=1ll*f[s]*(cur-pre[s]);
					t[s]|=(1<<x);pre[s]=cur;
				}
			}
		}
	}
	for(int s=1;s<=S;s++)f[s]=g[s]%mod;
	FWT(S,f);
	ll res=0;
	for(int s=0;s<=S;s++){
		int v=0,num=0;
		for(int i=0;i<n;i++)if((s>>i)&1)v+=(i+1),num++;
		v=v*num;
		res^=1ll*v*sub(f[S]-f[S^s]);
	}
	printf("%lld\n",res);
    return 0;
}