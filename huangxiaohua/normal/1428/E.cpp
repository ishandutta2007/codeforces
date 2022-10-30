#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,n,k,t;
 
ll x,tmp,res;
 
struct sb{
	ll a,b,c;
}p,p1;
bool operator < (const sb& aa, const sb& bb) {
	return aa.c < bb.c;
}
 
priority_queue <sb> q;
 
inline ll f(ll a,ll b){
	ll x=a/b,y=a%b;
	return x*x*(b-y)+(x+1)*(x+1)*y;
}
 
int main(){
	scanf("%d%d",&n,&k);k-=n;
	for(i=1;i<=n;i++){
		scanf("%lld",&x);res+=x*x;
		p.a=x;p.b=1;p.c=f(p.a,1)-f(p.a,2);
		q.push(p);
	}
	while(k--){
		p=q.top();q.pop();
		res-=p.c;p.b++;p.c=f(p.a,p.b)-f(p.a,p.b+1);
		q.push(p);
	}
	printf("%lld\n",res);
}