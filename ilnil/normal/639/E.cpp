#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define db double
#define ll long long
using namespace std;
const int N=1.5e5+5;
const db eps=1e-8;
int n,w[N],nx[N];
struct nod{int p,t,b;}a[N];
ll T,su[N];
db an,vmx[N],vmi[N];
bool cmp(nod a,nod b){
	if((ll)a.p*b.t!=(ll)b.p*a.t)
		return (ll)a.p*b.t>(ll)b.p*a.t;
	return a.p<b.p;
}
bool cmp2(int x,int y){
	return a[x].p<a[y].p;
}
bool cmp3(nod x,nod y){return x.b<y.b;}
bool ck(db mi){
	ll x=0;
	fo(i,1,n){
		fo(j,i,nx[i])vmx[j]=(1-mi*(x+a[j].t)/T)*a[j].p,vmi[j]=(1-mi*(x+su[i])/T)*a[j].p;
		x+=su[i];i=nx[i];
	}
	fo(i,1,n){
		int j=i;
		for(;j<n&&a[w[j+1]].p==a[w[i]].p;)++j;
		fo(k,i,j)
			vmi[w[i]]=min(vmi[w[i]],vmi[w[k]]),
			vmx[w[j]]=max(vmx[w[j]],vmx[w[k]]);
		if(i>1&&vmx[w[i-1]]>vmi[w[i]])return 0;
		i=j;
	}
	return 1;
}
int main(){
	cin>>n;
	fo(i,1,n)scanf("%d",&a[i].p);
	fo(i,1,n)scanf("%d",&a[i].t),T+=a[i].t;
	sort(a+1,a+n+1,cmp);
	fo(i,1,n)w[i]=i;
	sort(w+1,w+n+1,cmp2);
	ll x=0;
	fo(i,1,n){
		int j=i;
		for(;j<n&&(ll)a[i].p*a[j+1].t==(ll)a[j+1].p*a[i].t;)++j;
		fo(k,i,j)su[i]+=a[k].t;
		nx[i]=j;i=j;
	}
	an=0;
	for(db l=0,r=1,mi;mi=(l+r)/2,l+eps<=r;)
		if(ck(mi))an=l=mi;else r=mi;
	printf("%.10lf\n",an);
}