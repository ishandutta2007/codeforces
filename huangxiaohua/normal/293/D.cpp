#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 1000005
int l[2005000],r[2005000],x[100500],y[100500],i,j,k,n,m,t,l1,r1,d[2005000];
double sum,f[2005000],num[2005000],pre[2005000],pre2[2005000],pre3[2005000],res;
double k0;
struct sb{
	bool vis;
	int x,y;
	double k;
}sl[2005000],sr[2005000],s1;
double g(sb s,ll x){return s.k*(x-N-s.y)+s.x;}
void chk(int x,sb s1,sb *s,int ty){
	double f1,f2;
	if(!s[x].vis){s[x]=s1;return;}
	f1=g(s[x],x);
	f2=g(s1,x);
	if(!ty){if(f2<=f1)s[x]=s1;}
	else{if(f2>=f1)s[x]=s1;}
}
void get(){
	pre[i]=pre[i-1]+num[i];
	pre2[i]=pre[i-1]*2+pre2[i-1]+num[i];
	pre3[i]=pre3[i-1]+pre2[i];
	res+=1.0*pre3[i-1]*num[i];
}
int main(){
	s1.vis=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	x[n+1]=x[1];y[n+1]=y[1];
	for(i=1;i<=n;i++){
		s1.x=x[i];s1.y=y[i];
		if(y[i+1]==y[i])continue;
		s1.k=1.0*(x[i+1]-x[i])/(y[i+1]-y[i]);
		l1=min(y[i],y[i+1]);
		r1=max(y[i],y[i+1]);
		for(j=l1+N;j<=r1+N;j++){
			chk(j,s1,sl,0);
			chk(j,s1,sr,1);
		}
	}
	for(i=-1e6+N;i<=1e6+N;i++){
		if(!sl[i].vis)continue;
		double f1,f2;
		f1=g(sl[i],i);
		f2=g(sr[i],i);
		l[i]=ceil(f1);r[i]=floor(f2);
		d[l[i]+N]+=1;
		d[r[i]+N+1]+=-1;
		sum+=r[i]-l[i]+1;
		num[i]=r[i]-l[i]+1;
		get();
	}
	ll cur=0;
	for(i=-1e6+N;i<=1e6+N;i++){
		cur+=d[i];
		num[i]=cur;
		get();
	}
	res/=(sum*sum-sum);
	printf("%.20lf",res);
}