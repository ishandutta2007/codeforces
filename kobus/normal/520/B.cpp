#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 5123
#define INF INT_MAX
#define MOD (1ll<<(32)) 
#define pii pair<int,int>
#define double long double 

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<setprecision(11)<<fixed;

	int n,m;
	cin>>n>>m;
	int resp=0;
	while(m>n){
		if(m%2==0)m=m/2;
		else m++;
		resp++;
	}
	while(m<n){
		m++;
		resp++;
	}
	cout<<resp<<endl;




	return 0;
}