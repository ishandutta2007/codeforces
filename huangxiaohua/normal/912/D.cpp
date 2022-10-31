#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,r,x,y;
ll a[100500],b[100500];
double res;
map<int,bool> vis[100500];

struct sb{
	int x,y;
	ll w;
	bool operator<(const sb a)const{return w<a.w;}
}s;

priority_queue<sb> q;

int main(){
	cin>>n>>m>>r>>k;
	for(i=1;i<=n;i++){
		x=max(1,i-r+1);
		y=min(n,i+r-1);
		a[i]=y-x-r+2;
		//printf("a%d %d %d %d\n",i,x,y,a[i]);
	}
	for(i=1;i<=m;i++){
		x=max(1,i-r+1);
		y=min(m,i+r-1);
		b[i]=y-x-r+2;
		//printf("b%d %d %d %d\n",i,x,y,b[i]);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	q.push({n,m,a[n]*b[m]});
	while(k--){
		s=q.top();q.pop();
		res+=s.w;
		if(!vis[s.x-1][s.y]){
			vis[s.x-1][s.y]=1;
			q.push({s.x-1,s.y,a[s.x-1]*b[s.y]});
		}
		if(!vis[s.x][s.y-1]){
			vis[s.x][s.y-1]=1;
			q.push({s.x,s.y-1,a[s.x]*b[s.y-1]});
		}
	}
	res/=(n-r+1);
	res/=(m-r+1);
	//cout<<res;
	printf("%.20lf",res);
}