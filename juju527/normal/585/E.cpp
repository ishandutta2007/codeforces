//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=5e5+5,maxw=1e7+5,w=1e7,mod=1e9+7;
int cnt[maxw],s[maxw];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
inline int sub(int x){return (x<0)?x+mod:x;}
int pw[maxn];
bool bj[maxw];
int len,p[maxw],mu[maxw];
void init(){
	mu[1]=1;
	for(int i=2;i<=w;i++){
		if(!bj[i])p[++len]=i,mu[i]=-1;
		for(int j=1;1ll*p[j]*i<=w&&j<=len;j++){
			bj[i*p[j]]=1;
			if(i%p[j]==0){mu[i*p[j]]=0;break;}
			mu[i*p[j]]=-mu[i];
		}
	}
	return ;
}
int v[maxw],f[maxw];
int main(){
    int n;
	n=read();
	for(int i=1;i<=n;i++)cnt[read()]++;
	pw[0]=1;for(int i=1;i<=n;i++)pw[i]=add(pw[i-1]+pw[i-1]);
	init();
	for(int i=1;i<=w;i++)for(int j=i;j<=w;j+=i)s[i]+=cnt[j];
	for(int i=1;i<=w;i++){
		if(mu[i]==0)continue;
		int val=s[i];
		if(mu[i]==-1)val=sub(-val);
		if(val==0)continue;
		for(int j=i;j<=w;j+=i)v[j]=add(v[j]+val);
	}
	for(int i=w;i>=1;i--){
		int cur=1;
		for(int j=i+i;j<=w;j+=i)cur=add(cur+f[j]);
		f[i]=sub(pw[s[i]]-cur);
	}
	int res=0;
	for(int d=2;d<=w;d++)
		res=add(res+1ll*v[d]*f[d]%mod);
	printf("%d\n",res);
    return 0;
}