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

pii v[11234];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>v[i].f>>v[i].s;
	}
	sort(v,v+n);

	int t=0;
	for(int i=0;i<n;i++){
		if(v[i].s>=t)t=v[i].s;
		else t=v[i].f;
	}

	cout<<t<<endl;





	return 0;
}