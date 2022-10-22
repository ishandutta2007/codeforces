//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<ll>
#define eb emplace_back
using namespace std;
const int maxn=2e5+5,maxd=15;
bool ban[maxn];
int a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int d[maxd];
vec sum[maxd];
multiset<ll> mx;
inline ll Mx(){return *mx.rbegin();}
int main(){
    int T;
	T=read();
	while(T--){
		int n,q,len=0;
		n=read();q=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=2;i<=n;i++)for(int j=i+i;j<=n;j+=i)ban[j]=1;
		for(int i=2;i<=n;i++){
			if(n%i||ban[i])continue;
			d[++len]=n/i;
		}
		mx.clear();
		for(int i=1;i<=len;i++){
			sum[i].clear();
			for(int x=1;x<=d[i];x++){
				ll cur=0;
				for(int v=x;v<=n;v+=d[i])cur+=a[v];
				sum[i].eb(cur);
				mx.insert(cur*d[i]);
			}
		}
		printf("%lld\n",Mx());
		while(q--){
			int p,x;
			p=read();x=read();
			for(int i=1;i<=len;i++){
				int id=(p-1)%d[i];
				mx.erase(mx.find(sum[i][id]*d[i]));
				sum[i][id]-=a[p]-x;
				mx.insert(sum[i][id]*d[i]);
			}
			a[p]=x;
			printf("%lld\n",Mx());
		}
	}
    return 0;
}