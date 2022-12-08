#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF LLONG_MAX;
#define MOD 1000000

map<int,int> mx;
map<int,int> my;

map<pair<int,int>,int> m;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	int resp=0;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		resp+=mx[a];
		resp+=my[b];
		mx[a]++;my[b]++;
		resp-=m[mp(a,b)];
		m[mp(a,b)]++;
	}
	cout<<resp<<endl;

	return 0;
}