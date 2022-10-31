#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

ll l,r=3e12,md,res=1e18,a[200500],b[200500];

struct sb{
	ll x,y;
	double t;
	bool operator<(const sb a)const{return t>a.t;}
}s;

bool chk(ll sb){
	priority_queue<struct sb> q;
	int i,j,k;
	ll tmp;
	for(i=1;i<=n;i++){
		s.x=a[i];
		s.y=b[i];
		s.t=s.x*1.0/s.y;
		q.push(s);
	}
	for(i=0;i<m;i++){
		s=q.top();q.pop();
		tmp=s.x/s.y;
		if(tmp<i){return 0;}
		s.x+=sb;
		s.t=s.x*1.0/s.y;
		q.push(s);
	}
	return 1;
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	while(l<=r){
		md=(l+r)/2;
		if(chk(md)){res=min(res,md);r=md-1;}
		else{l=md+1;}
	}
	if(res==1e18){
		puts("-1");return 0;
	}
	printf("%lld",res);
}