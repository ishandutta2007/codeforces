#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int C2(int x){return x*(x-1);}
const int N=2005;
struct node{
	ll x,y;
	inline node(){}
	inline node(ll x,ll y):x(x),y(y){}
	inline node operator-(const node &a)const{
		return node(x-a.x,y-a.y);
	}
}a[N],x[N];
struct node2{
	ll x,y;int t,f;
	inline node2(){}
	inline node2(ll x,ll y,int f):x(x),y(y),t(x>0ll||(x==0ll&&y>0ll)),f(f){}
	inline bool operator<(const node2 &a)const{
		return t>a.t||(t==a.t&&x*a.y<y*a.x);
	}
}y[N<<1];
int main(){
//	freopen("2.in","r",stdin);
	int n,m,k,t,c,i,j;ll ans=0ll;
	scanf("%d",&n);k=n-2;
	for(i=1;i<=n;++i)scanf("%I64d%I64d",&a[i].x,&a[i].y);
	for(j=1;j<=n;++j){
		m=0;t=0;c=0;
		for(i=1;i<=n;++i)if(i!=j)x[++m]=a[i]-a[j];
		for(i=1;i<=m;++i){
			y[++t]=node2( x[i].x, x[i].y,0);
			y[++t]=node2(-x[i].x,-x[i].y,1);
		}
		sort(y+1,y+t+1);
		for(i=1;i<=t;++i)if(y[i].t==1&&y[i].f==0)++c;
		for(i=1;i<=t;++i){
			if(y[i].f==1)++c;
			else{--c;ans+=((ll)C2(c))*C2(k-c);}
		}
	}
	printf("%I64d",ans>>3);
	return 0;
}