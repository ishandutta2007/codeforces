#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a,int b){
	int x=a,y=b;
	if(x<y){
		x+=y;
		y=x-y;
		x-=y;
	}
	while(x%y!=0){
		x %= y;
		x+=y;
		y=x-y;
		x-=y;
	}
	return y;
}

int main()
{
   int n,a,b,p,q;
   ll ans;
   cin >> n >> a >> b >> p >> q;
   ll c = a*1LL*b;
   c /= gcd(a,b);
   ans = (n/a)*1LL*p+(n/b)*1LL*q-(n/c)*1LL*min(p,q);
   cout << ans;
}