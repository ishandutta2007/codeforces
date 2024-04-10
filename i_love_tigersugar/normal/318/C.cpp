#include<cstdio>
typedef long long ll;
ll x,y,m;
ll f[100];
ll max(ll x,ll y) {
	if (x>y) return (x); else return (y);
}
int n;
void init(void) {
	f[0]=0;
	f[1]=1;
	f[2]=1;
	f[3]=2;
	n=3;
	while (f[n]>f[n-1]) {
		n++;
		f[n]=f[n-1]+f[n-2];
	}
}
ll res(ll x,ll y) {
	if (max(x,y)>=m) return (0);
	if (x>y) return (res(y,x));
	if (y<0) {
		if (max(x,y)>=m) return (0);
		else return (-1);
	}
	if ((x==0) && (y==0)) {
		if (m<=0) return (0);
		else return (-1);
	}
	if (x>=0) {	
		int i;
		if (y>=m) return (0);
		for (i=1;i<=n;i=i+1) {
			if (f[i+1]*y+f[i]*x<f[i]*y+f[i-1]*x) return (i);
			if (f[i+1]*y+f[i]*x>=m) return (i);
		}			
	}
	if (y==0) {
		if (m<=0) return (0);
		else return (-1);
	}
	ll k;
	if (x%y==0) k=(-x)/y;
	else k=(-x)/y+1;
	return (res(x+k*y,y)+k);
}
int main(void) {
	init();	
	scanf("%I64d",&x);
	scanf("%I64d",&y);
	scanf("%I64d",&m);
	printf("%I64d",res(x,y));
	return 0;
}