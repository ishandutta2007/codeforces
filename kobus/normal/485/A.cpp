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

int vis[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a,m;
	cin>>a>>m;

	while(vis[a]!=1){
		//cout<<a;
		vis[a]=1;
		a+=a;
		a%=m;
		//cout<<" - "<<a<<endl;
	}

	if(vis[0])cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}