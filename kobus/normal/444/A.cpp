#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define mp make_pair

int v[1123456];


int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout<<setprecision(11)<<fixed;

	int n,m;
	cin>>n>>m;
	long double ans=0;
	for(int i=0;i<n;i++)cin>>v[i];
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		ans=max(ans,((long double)v[a]+v[b])/c);
	}
	cout<<ans<<endl;
	

    return 0;
}