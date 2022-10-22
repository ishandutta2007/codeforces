#include <bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int maxn=1e5+5,mod=998244353;
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
vector<int> st[2];
int f[2][maxn];
int main(){
	int T;
	T=read();
	while(T--){
		int n,res=0;
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=0;i<st[0].size();i++)f[0][st[0][i]]=0;
		for(int i=0;i<st[1].size();i++)f[1][st[1][i]]=0;
		st[0].clear();st[1].clear();
		for(int i=n;i>=1;i--){
			int now=i&1,pre=now^1;
			st[now].eb(a[i]);
			f[now][a[i]]=1;
			int lst=a[i];
			for(int j=0;j<st[pre].size();j++){
				int x=st[pre][j];
				int v=a[i]/x+(a[i]%x>0);
				res=add(res+1ll*f[pre][x]*(v-1)*i%mod);
				f[now][a[i]/v]+=f[pre][x];f[pre][x]=0;
				if((a[i]/v)^lst)st[now].eb(a[i]/v),lst=a[i]/v;
			}
			st[pre].clear();
		}
		printf("%d\n",res);
	}
    return 0;
}