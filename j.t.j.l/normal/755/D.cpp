#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int main(){
	cin>>n>>m;
	if(m>n/2)m=n-m;
	ll ans=1,nowp=1,sum=1;
	for(int i=1;i<=n;i++){
		nowp+=m;
		if(nowp<=n)ans+=sum;
		else ans+=((sum+=2)-1-(i==n)),nowp-=n;
		printf("%lld%c",ans," \n"[i==n]);
	}
	return 0;
}