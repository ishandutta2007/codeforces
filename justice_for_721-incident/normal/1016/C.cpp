#include<iostream>
using namespace std;
typedef long long ll;
ll ans=0;
ll sum=0;
ll pass=0;
int n;
ll a[300001],b[300001],c[300001],d[300001];
ll pa[300001],pb[300001],pc[300001],pd[300001];
ll p2a[300001],p2b[300001],p2c[300001],p2d[300001];
ll cal1(int seed,int pos){
	ll s=pa[n]-pa[pos-1];
	return p2a[n]-p2a[pos-1]+(seed-pos)*s;
}
ll cal2(int seed,int pos){
	ll s=pb[n]-pb[pos-1];
	return p2b[n]-p2b[pos-1]+(seed-pos)*s;
}
ll cal3(int seed,int pos){
	ll s=pc[n+1-pos];
	return p2c[n+1-pos]+(seed-1)*s;
}
ll cal4(int seed,int pos){
	ll s=pd[n+1-pos];
	return p2d[n+1-pos]+(seed-1)*s;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		pa[i]=pa[i-1]+a[i];
		p2a[i]=p2a[i-1]+i*a[i];
		c[n+1-i]=a[i];
	}
	for(int i=1; i<=n ;i++){
		cin >> b[i];
		pb[i]=pb[i-1]+b[i];
		p2b[i]=p2b[i-1]+i*b[i];
		d[n+1-i]=b[i];
	}
	for(int i=1; i<=n ;i++){
		pc[i]=pc[i-1]+c[i];
		p2c[i]=p2c[i-1]+i*c[i];
		pd[i]=pd[i-1]+d[i];
		p2d[i]=p2d[i-1]+i*d[i];
	}
	for(int i=1; i<=n ;i++){
		if(i%2==1){
			ans=max(ans,sum+cal1(pass,i)+cal4(n+i-1,i));
			sum+=pass*a[i];
			pass++;
			sum+=pass*b[i];
			pass++;
		}
		else{
			ans=max(ans,sum+cal2(pass,i)+cal3(n+i-1,i));
			sum+=pass*b[i];
			pass++;
			sum+=pass*a[i];
			pass++;
		}
		
	}
	ans=max(ans,sum);
	cout << ans << endl;
}