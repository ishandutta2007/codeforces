//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
typedef double db;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
#define R q.size()-1
using namespace std;
const int maxn=1e5+5,maxm=1e5+5,maxp=1e2+5;
const db eps=1e-9;
int pos[maxn];
pii a[maxm];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
ll suf[maxm];
ll f[maxm],g[maxm];
deque<int> q;
db slope(int i,int j){return 1.0*(g[j]-suf[j+1]-g[i]+suf[i+1])/(j-i);}
int main(){
    int n,m,p;
	n=read();m=read();p=read();
	for(int i=2;i<=n;i++)pos[i]=pos[i-1]+read();
	for(int i=1;i<=m;i++){
		int h,t;
		h=read();t=read();
		a[i]=pii(t-pos[h],i);
	}
	sort(a+1,a+m+1);
	for(int i=m;i>=1;i--)suf[i]=suf[i+1]+a[i].fi;
	for(int i=1;i<=m;i++)g[i]=1e18;
    for(int c=1;c<=p;c++){
		while(q.size())q.pop_back();
		q.push_back(0);f[0]=0;
		for(int i=1;i<=m;i++){
			int x=a[i].fi;
			while(q.size()>=2&&x-slope(q[0],q[1])>=eps)q.pop_front();
			int j=q[0];
			f[i]=g[j]-suf[j+1]+suf[i+1]+1ll*(i-j)*x;
			while(q.size()>=2&&slope(q[R-1],q[R])-slope(q[R],i)>=eps)q.pop_back();
			q.push_back(i);
		}
		for(int i=0;i<=m;i++)g[i]=f[i];
	}
	printf("%lld\n",f[m]);
	return 0;
}