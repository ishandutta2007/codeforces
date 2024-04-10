//Code by juju527.
#include<bits/stdc++.h>
#define int long long
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=3e5+5;
int x[maxn],d[maxn];
int buf[maxn],id[maxn];
int ans[maxn];
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
bool cmp(int i,int j){return x[i]<x[j];}
signed main(){
    int n,l;ll t;
	n=read();l=read();t=read();
	for(int i=0;i<n;i++){
		x[i]=read()-1;
		char ch;
		scanf("%c",&ch);
		if(ch=='R')d[i]=1;else d[i]=2;
		buf[i]=(x[i]+((d[i]==1)?t%l:-(t%l))+l)%l;
		id[i]=i;
	}
	sort(id,id+n,cmp);sort(buf,buf+n);
	int pos=0;
	for(int i=0;i<n;i++){
		if(d[i]==1)pos+=((x[i]+t)/l)%n,pos%=n;
		else pos+=((x[i]-t)/l-(t>=x[i])+((x[i]-t)%l==0))%n+n,pos%=n;
	}
	for(int i=pos,c=0;c<n;c++,i++,i%=n)ans[id[c]]=buf[i]+1;
	for(int i=0;i<n;i++)printf("%lld ",ans[i]);
	puts("");
    return 0;
}