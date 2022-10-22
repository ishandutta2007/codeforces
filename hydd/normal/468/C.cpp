#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll lim=1e18;
ll a;
int main(){
	//\sum_{i=0}^{10^18-1} f(i)=81*10^18
	//\sum_{i=x}^{10^18+x-1} f(i)=81*10^18+x
	cin>>a;
	//81*10^18+x=a,x=a-81*10^18
	ll x=a-lim%a*9%a*9%a;
	printf("%lld %lld\n",x,x+lim-1);
	return 0;
}