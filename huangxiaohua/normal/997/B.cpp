#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
int i,j,k,n,m,t;
ll res[105];
bitset<50050> b;

int main() {
	cin>>n;
	b[0]=1;
	for(i=1;i<=100;i++){
		int tmp=b.count();
		b=((b<<1)|(b<<5)|(b<<10)|(b<<50));
		res[i]=b.count();
	}
	if(n<=100){
		cout<<res[n];
	}
	else{
		cout<<(res[100]+1ll*(n-100)*49);
	}
}