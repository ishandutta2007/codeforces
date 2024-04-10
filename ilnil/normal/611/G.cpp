#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ll long long
using namespace std;
const int N=1e6+5,mo=1e9+7;
int n;
ll ans,all,all2,sum,tot,su[N],su2[N];
struct P{
	int x,y;
	P(int _x=0,int _y=0){x=_x;y=_y;}
	P operator+(const P a){return P((x+a.x)%mo,(y+a.y)%mo);}
	P operator-(const P a){return P(x-a.x,y-a.y);}
}a[N],pre[N];
int cro(P x,P y){return ((ll)x.x*y.y-(ll)x.y*y.x)%mo;}
ll cro2(P x,P y){return (ll)x.x*y.y-(ll)x.y*y.x;}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	fo(i,1,n)cin>>a[i].x>>a[i].y;
	reverse(a+1,a+n+1);
	fo(i,1,n)a[n+i]=a[i];
	fo(i,1,n*2){
		pre[i]=a[i]+pre[i-1];
		int v=cro(a[i],a[i+1]);
		su[i]=(su[i-1]+v)%mo;
		su2[i]=(su2[i-1]+(ll)v*i)%mo;
	}
	fo(i,2,n-1)all+=cro2(a[i]-a[1],a[i+1]-a[1]);
	all2=all%mo;
	int k=1;
	fo(i,1,n){
		for(;;){
			ll dt=cro2(a[k]-a[i],a[k+1]-a[i]);
			if(sum+dt>all/2)break;
			sum+=dt;++k;
		}
		ans=(ans+all2*((k-i)-(i+n-1-k)))%mo;
		tot=((su[k-1]-su[i-1])*k-(su2[k-1]-su2[i-1])+cro(pre[k]-pre[i],a[i]))%mo;
		ans=(ans+tot*-2)%mo;
		tot=((su[k-1]-su[i-1])*(i+n-1-k)+(su[i+n-1-1]-su[k-1])*(i+n-1)-(su2[i+n-1-1]-su2[k-1])+cro(pre[i+n-1]-pre[k],a[i]))%mo;
		ans=(ans+tot*2-all2*2)%mo;
		sum-=cro2(a[i+1]-a[i],a[k]-a[i]);
	}
	cout<<(ans*(mo+1>>1)%mo+mo)%mo;
}