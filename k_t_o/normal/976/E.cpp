#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int n,a,b,g;
long long ans_,ans,ss,dd;
struct node {
	int x, y;
	
	node() {
		x=0; y=0;
	}
	
	bool operator < (const node & a) const{
		return x-y>a.x-a.y;
	}
}p[200005];

int main()
{
	n=read(); a=read(); b=read();
	for(int i=1; i<=n; ++i){
		p[i].x=read(); p[i].y=read();
	}
	sort(p+1,p+n+1);
	for(int i=1; i<=b; ++i){
		if(p[i].x<=p[i].y)break;
		g=i;
	}
	
	if(g==b) {
		
		for(int i=1; i<=b; ++i)ans+=p[i].x;
		for(int i=b+1; i<=n; ++i)ans+=p[i].y;
		
		if(b==0){
			cout<<ans; return 0;
		}
		
		ans_=ans;
		
		for(int i=1; i<=b; ++i) {
			ss=ans_-p[i].x;
			dd=(1ll<<a)*p[i].x;
			ss+=dd;
			ans=max(ans,ss);
		}
		
		for(int i=b+1; i<=n; ++i) {
			ss=ans_-p[i].y-p[b].x+p[b].y;  //x
			dd=(1ll<<a)*p[i].x;
			ss+=dd;
			ans=max(ans,ss);
		}
		
		cout<<ans;
		return 0;
		
	}
	
	for(int i=1; i<=g; ++i)ans+=p[i].x;
	for(int i=g+1; i<=n; ++i)ans+=p[i].y;
	ans_=ans;
		for(int i=1; i<=g; ++i) {
			ss=ans_-p[i].x;
			dd=(1ll<<a)*p[i].x;
			ss+=dd;
			ans=max(ans,ss);
		}
		
		for(int i=g+1; i<=n; ++i) {
			ss=ans_-p[i].y;
			dd=(1ll<<a)*p[i].x;
			ss+=dd;
			ans=max(ans,ss);
		}
		
		cout<<ans;
	
	
}
/*

1 1 1
3 4


*/