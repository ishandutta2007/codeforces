//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1e5+5,mod=998244353;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
inline void add(int &x,int y){x=add(x+y);return ;}
inline int sub(int x){return (x<0)?x+mod:x;}
inline int power(int x,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return res;
}
int fc[maxn],ifc[maxn];
inline int binom(int n,int m){
	if(n<m||m<0)return 0;
	return 1ll*fc[n]*ifc[m]%mod*ifc[n-m]%mod;
}
int a[maxn];
ll s[maxn],s2[maxn];
map<ll,int> mp;
void init(int n){
	mp.clear();
	fc[0]=1;for(int i=1;i<=n;i++)fc[i]=1ll*fc[i-1]*i%mod;
	ifc[n]=power(fc[n],mod-2);for(int i=n-1;i>=0;i--)ifc[i]=1ll*ifc[i+1]*(i+1)%mod;
	return ;
}
int main(){
	int T;
	T=read();
	while(T--){
		int n;int S=0,res=0;
		n=read();init(n);
		for(int i=1;i<=n;i++)a[i]=read(),s[i]=s[i-1]+a[i];
		for(int i=n;i>=1;i--){s2[i]=s[n]-s[i-1];if(a[i])mp[s2[i]]=i;}
		if(!s[n]){printf("%d\n",power(2,n-1));continue;}
		int p1=0,p2=n+1;
		while(!a[p1+1])p1++;while(!a[p2-1])p2--;
		for(int i=1;i<=n;i++){
			int w1=(p1==0&&i==1)?1:binom(p1,i-1);
			int w2=(p2==n+1&&i==1)?1:binom(n-p2+1,i-1);
			add(S,1ll*w1*w2%mod);
		}
		res=S;
		for(int i=1;i<=n;i++){
			if(!mp[s[i]]||!a[i])continue;
			if(2ll*s[i]>s[n])break;
			p1=i,p2=mp[s[i]];
			int c1=0,c2=0;
			while(p1<n&&!a[p1+1])p1++,c1++;
			while(p2>1&&!a[p2-1])p2--,c2++;
			if(p1>=p2){add(res,1ll*S*sub(power(2,c1+1)-1)%mod);continue;}
			int aux=0;
			for(int j=1;j<=c1+1&&j<=c2+1;j++)add(aux,1ll*binom(c1+1,j)*binom(c2+1,j)%mod);
			add(res,1ll*aux*S%mod);add(S,1ll*aux*S%mod);
		}
		printf("%d\n",res);
	}
    return 0;
}