#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll N=2e6+10,mo=1e9+7;
struct dot{ll x,y;}a[N];
ll cross(dot a,dot b){
	return a.x*b.y-a.y*b.x;
}
ll sx[N],sy[N],n,S;
unsigned long long sq[N];
void Mod(ll &a){
	a=(a%mo+mo)%mo;
}
ll qsum(int l,int r){
	return (ll)(sq[r]-sq[l]+cross(a[l],a[r]))-cross(a[l],a[r]);
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		scanf("%I64d%I64d",&a[i].x,&a[i].y);
	for (int i=1;i<=2*n;i++)a[i+n]=a[i];
	for (int i=1;i<=3*n;i++){
		sx[i]=(sx[i-1]+a[i].x+mo)%mo;
		sy[i]=(sy[i-1]+a[i].y+mo)%mo;
		sq[i]=sq[i-1]+cross(a[i],a[i-1]);
	}
	S=sq[n+1];
	int p=2;
	ll S1=0,S2=0,sum=0;
	for (int i=2;i<=n;i++){
		S1=(S1+qsum(i,n))%mo;
	}
	for (int i=n;i<p+n;i++){
		S2=(S2+qsum(n,i))%mo;
	}
	for (int i=n+1;i<=n+n;i++){
		S1+=cross(a[i],a[i-1])%mo*(i-p);
		S2-=cross(a[i],a[i-1])%mo*(p+n-i);
		Mod(S1),Mod(S2);
		while ((sq[i]-sq[p]+cross(a[p],a[i])*1ull)>S/2){
			S1-=qsum(p,i);
			S2+=qsum(i,p+n);
			Mod(S1),Mod(S2);
			p++;
		}
		sum+=S1+S2;
		sum+=(sx[i]-sx[p-1])*a[i].y-(sy[i]-sy[p-1])*a[i].x;
		sum-=(sx[p+n-1]-sx[i])*a[i].y-(sy[p+n-1]-sy[i])*a[i].x;
		Mod(sum);		
	}
	S%=mo;
	sum=(((n-3)*n/2)%mo*S-sum);
	Mod(sum);
	cout<<sum<<endl;
}