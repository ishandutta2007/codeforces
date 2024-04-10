#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll _d,n,k;

ll findpos(ll Id){// the Id'th range [k*k+1;
	if(Id==0)return k*(k+1)/2;
	ll pos2 = findpos(Id/k);
	ll fore = pos2-1, back = k*k+1-pos2;
	ll A = Id%k, B=k-Id%k;
	if(fore/k >= Id%k+1)return k*(k+1)/2-Id%k;
	if(back/k >= B)return k*(k+1)/2+B;
	return k*(k+1)/2-A+back%k;
}

int main()
{
	int T;cin >> T;
	while(T--){
		scanf("%lld%lld",&n,&k);
		_d=k*k+1;
		ll id = (n-1)/_d;
		ll p = findpos(id);
		ll rest = (n-1)%_d+1;
		if((n-1)%_d+1==p)printf("%lld\n", (id+1)*(k+1));
		else{
			ll ans1 = id*k*(k+1);
			ll ans2 = rest-(rest>=p);
			ans2 = ((ans2-1)/k)*(k+1)+(ans2-1)%k+1;
			printf("%lld\n",ans1+ans2);
		}
	}
}