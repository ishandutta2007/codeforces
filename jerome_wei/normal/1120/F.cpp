#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n;ll c,d;
char s[3];
ll t[N];int type[N];


int main()
{
	scanf("%d%lld%lld",&n,&c,&d);
	for(int i=0;i < n;i++){
		scanf("%lld%s",&t[i],s+1);
		type[i]=s[1]=='P'? 1:0;
	}
	scanf("%lld",&t[n]);
	type[n] = -1;
	int last = 0; ll s = 0;
	ll ans = 1000000000000000000;
	for(int i=n;~i;i--){
		if(type[i] == type[i+1]){
			s += min(d, (last - t[i+1]) *c);
		} else {
			last = t[i + 1];
		}
		ans = min(ans, c * ( t[n] - t[i]) + s + d * i );
	}
	cout << ans << endl;
}