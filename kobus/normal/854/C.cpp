#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000007

int finor[612345];
pii price[312345];
int priceor[312345];

int rev(pii a,pii b){
	return a>b;
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,d;
	cin>>n>>d;

	for(int i=0;i<n;i++){
		cin>>price[i].f;
		priceor[i]=price[i].f;
		price[i].s=i+1;
	}
	set<int>s;
	for(int i=d+1;i<=d+n;i++){
		s.insert(i);
	}

	sort(price,price+n,rev);


	for(int i=0;i<n;i++){
		finor[price[i].s]=*s.lower_bound(price[i].s);
		s.erase(s.lower_bound(price[i].s));
	}

	ll resp=0;

	for(int i=1;i<=n;i++){
		resp+=1ll*(finor[i]-i)*priceor[i-1];
	}

	cout<<resp<<endl;

	for(int i=1;i<=n;i++){
		cout<<finor[i]<<" ";
	}
	cout<<endl;

	

	return 0;
}