#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it,l;
ll a[1005000],res[1005000],d[1005000],mx;

struct sb{
	ll x,id;
	bool operator<(const sb a)const{return x<a.x;}
}s;
priority_queue<sb> q;

int main(){
	scanf("%d%d",&t,&n);
	while(t--){
		scanf("%d",&m);
		mx=0;
		for(i=1;i<=m;i++){
			scanf("%lld",&a[i]);
			mx=max(mx,a[i]);
		}
		while(!q.empty()){q.pop();}
		l=n-m;
		q.push({0,0});
		if(m+m>=n){
			for(i=1;i<=n;i++){
				if(i>m){q.push({0,i});}
				else{q.push({a[i],i});}
				while(q.top().id<i-l){q.pop();}
				res[i]+=q.top().x;
			}
		}
		else{
			d[m+1]+=mx;
			d[n-m+1]-=mx;
			for(i=1;i<=m;i++){
				q.push({a[i],i});
				res[i]+=q.top().x;
			}
			while(!q.empty()){q.pop();}
			q.push({0,0});
			for(i=m;i>=1;i--){
				q.push({a[i],i});
				res[n-m+i]+=q.top().x;
			}
		}
	}
	mx=0;
	for(i=1;i<=n;i++){
		mx+=d[i];
		printf("%lld ",res[i]+mx);
	}
}