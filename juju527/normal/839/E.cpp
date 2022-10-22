#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=45;
int n;
ll N[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int popcnt(ll x){return __builtin_popcountll(x);}
int mx=0;
void BK(ll r,ll p,ll x){
	if(!p&&!x){mx=max(mx,popcnt(r));return ;}
	int z=n+1,u=-1;
	ll st=p|x;
	for(int i=0;i<n;i++){
		if(!((st>>i)&1))continue;
		int w=popcnt(p&N[i]);
		if(w<z)z=w,u=i;
	}
	st=p&N[u];
	for(int i=0;i<n;i++){
		if(!((st>>i)&1))continue;
		BK(r|(1ll<<i),p^(p&N[i]),x^(x&N[i]));
		p^=(1ll<<i),x|=(1ll<<i);
	}
	return ;
}
int main(){
    int k;
	n=read();k=read();
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)N[i]|=((1ll*(read()^1))<<j);
	BK(0,(1ll<<n)-1,0);
	printf("%.8lf\n",0.5*k*k*(mx-1)/mx);
    return 0;
}