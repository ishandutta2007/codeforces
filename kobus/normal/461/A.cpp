#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567
#define INF INT_MAX/2
#define MOD 1000000007
#define int long long

int v[312345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	sort(v,v+n);
	long long resp=0;
	for(int i=0;i<n;i++){
		resp+=(i+2)*v[i];
	}
	resp-=v[n-1];

	cout<<resp<<endl;

	return 0;
}