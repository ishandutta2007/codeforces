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
//#define int long long

int v[312345];


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n;i++)cin>>v[i];

	sort(v,v+n);

	ll resp=0;
	for(int i=0;i<n;i++){
		resp+=abs(i+1-v[i]);
	}
	cout<<resp<<endl;


	return 0;
}