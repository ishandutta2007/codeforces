#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int maxn=1e5+5;
int n,m,k,p;
int h[maxn],a[maxn],c[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
struct node{
	int day,id;
	bool operator <(node i)const{
		return day>i.day;
	}
};
priority_queue<node>q;
bool check(int H){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)c[i]=0;
	for(int i=1;i<=n;i++)if(H-m*a[i]<h[i])q.push((node){H/a[i],i});
	for(int i=1;!q.empty()&&i<=m;i++){
		for(int j=1;!q.empty()&&j<=k;j++){
			int id=q.top().id;
			if(q.top().day<i)return 0;
			q.pop();
			c[id]++;
			if(H+c[id]*p-m*a[id]<h[id])q.push((node){(H+c[id]*p)/a[id],id});
		}
	}
	return q.empty();
}
signed main(){
	ll mx=0;
	n=read();m=read();k=read();p=read();
	for(int i=1;i<=n;i++)h[i]=read(),a[i]=read(),mx=max(mx,1ll*m*a[i]+h[i]);
	ll l=-1,r=mx,mid;
	while(l+1<r){
		mid=l+((r-l)>>1);
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%lld\n",r);
	return 0;
}