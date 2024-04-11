#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 1123
#define INF INT_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define double long double 

int p[MAXN];
int resp[MAXN];


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	resp[1]=0;
	for(int i=2;i<=n+1;i++){
		resp[i]=(((2*resp[i-1]+2-resp[p[i-1]])%MOD)+MOD)%MOD;
	}
	cout<<resp[n+1]<<endl;


	return 0;
}