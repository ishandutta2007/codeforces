#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 5123
#define INF INT_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define double long double 
#define int long long

//price,grade
multiset<pair<int,int>> s;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,r,avg;
	cin>>n>>r>>avg;

	int ravg=avg*n;
	int pontos=0;
	int custo=0;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		pontos+=a;
		s.insert(mp(b,a));
	}
	while(pontos<ravg){
		auto at=*s.begin();
		s.erase(s.begin());
		int dapraaumentar=r-at.s;
		if(pontos+dapraaumentar>=ravg){
			int precisa=ravg-pontos;
			custo+=precisa*at.f;
			break;
		}
		else{
			custo+=dapraaumentar*at.f;
			pontos+=dapraaumentar;
		}
	}

	cout<<custo<<endl;



	return 0;
}