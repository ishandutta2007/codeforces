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



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int nxt=-INF;
	int n;
	cin>>n;

	//fim,com
	vector<pii> v;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v.pb(mp(a+b,a-b));
	}
	sort(v.begin(),v.end());
	int resp=0;
	for(int i=0;i<n;i++){
		if(v[i].s>=nxt){
			resp++;
			nxt=v[i].f;
		}
	}

	cout<<resp<<endl;



	return 0;
}