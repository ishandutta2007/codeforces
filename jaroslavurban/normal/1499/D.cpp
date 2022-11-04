#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=20000100;
int c,d,x;
// prime[i] = highest prime factor of i
vector<int>prime;
vector<int>erat(int n){ // exclusive
	prime.resize(n);prime[0]=prime[1]=1;
	vector<int>res;
	for(int i=2;i<n;++i)if(!prime[i]){
		res.push_back(i);
		for(int j=i;j<n;j+=i)prime[j]=i;
	}
	return res;
}
int factorize(int val){
	int res=1;
	int prevp=-1;
	while(val!=1){
		if(prime[val]!=prevp){
			res*=2;
			prevp=prime[val];
		}
		val/=prime[val];
	}
	return res;
}

int i,j,k;
int solvefor(int div){
//	cerr<<i<<" "<<k<<" "<<div<<'\n';
	int val=k/div+j;
	if(val%i||val<=0)return 0;
	val/=i;
	return factorize(val);
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	erat(N);
	int tc;cin>>tc;
	while(tc--){
		cin>>c>>d>>x;
		int gcd=__gcd(c,d);
		i=c/gcd;
		j=d/gcd;
		if(x%gcd){cout<<"0\n";continue;}
		k=x/gcd;
		ll res=0;
		for(int i=1;i*i<=k;++i){
			if(k%i==0){
				res+=solvefor(i);
				if(k/i!=i)res+=solvefor(k/i);
			}
		}
		cout<<res<<"\n";
	}
}