//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
const int maxw=3e5+5,w=3e5;
int lowbit[maxw];
struct BIT{
	ll t[maxw];
	void update(int x,int v){while(x<=w)t[x]+=v,x+=lowbit[x];return ;}
	ll query(int x){ll res=0;while(x)res+=t[x],x-=lowbit[x];return res;}
}T1,T2;
int main(){
    int n;
	n=read();
	for(int i=1;i<=w;i++)lowbit[i]=i&-i;
	ll res=0,sum=0;
	for(int i=1;i<=n;i++){
		int x;
		x=read();
		res+=sum+1ll*(i-1)*x-T2.query(x);
		ll aux=0;
		int lst=T1.query(x-1);
		for(int j=x;j<=w;j+=x){
			int v=T1.query(min(j+x-1,w));
			aux+=1ll*(v-lst)*j;lst=v;
			T2.update(j,x);
		}
		res-=aux;
		printf("%lld ",res);
		T1.update(x,1);
		sum+=x;
	}
	puts("");
    return 0;
}