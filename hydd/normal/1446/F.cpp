#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> pii;
typedef long long ll;
const double eps=1e-7;
const double pi=acos(-1);
int n,x[110000],y[110000],tree[210000]; ll k;
int cnt,tot; double num[210000]; pii p[210000];
void add(int x,int y){
	for (;x<=tot;x+=x&-x) tree[x]+=y;
}
int query(int x){
	int res=0;
	for (;x;x-=x&-x) res+=tree[x];
	return res;
}
double norm(double angle){
	if (angle<0) angle+=2*pi;
	if (angle>2*pi) angle-=2*pi;
	return angle;
}
ll calc(double r){
	double theta,delta,theta1,theta2;
	cnt=0; tot=0;
	for (int i=1;i<=n;i++){
		double d=sqrt(x[i]*x[i]+y[i]*y[i]);
		if (d<r) continue;
		theta=atan2(y[i],x[i]); delta=acos(r/d);
		theta1=norm(theta-delta); theta2=norm(theta+delta);
		if (theta1>theta2) swap(theta1,theta2);
		p[++cnt]=pii(theta1,theta2);
		num[++tot]=theta1; num[++tot]=theta2;
	}
	sort(num+1,num+tot+1); sort(p+1,p+cnt+1);
	for (int i=1;i<=tot;i++) tree[i]=0;
	ll ans=1ll*n*(n-1)/2;
	for (int i=1;i<=cnt;i++){
		int u=lower_bound(num+1,num+tot+1,p[i].first)-num,
			v=lower_bound(num+1,num+tot+1,p[i].second)-num;
		ans-=query(v)-query(u); add(v,1);
	}
	return ans;
}
int main(){
	scanf("%d%lld",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	
	double l=0,r=20000;
	while (r>l+eps&&r>l*(1+eps)){
		double mid=(l+r)/2;
		if (calc(mid)<k) l=mid;
		else r=mid;
	}
	printf("%.8lf\n",l);
	return 0;
}