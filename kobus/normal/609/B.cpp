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
#define INF INT_MAX/2
#define MOD 1000000

int v[212345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;i++)cin>>v[i];

	int par=(n*(n-1))/2;
	sort(v,v+n);

	for(int i=0;i<n;i++){
		int com=i;
		while(i+1<n && v[i+1]==v[i])i++;
		int fim=i;
		int dif=fim-com+1;
		par-=(dif*(dif-1))/2;
	}
	cout<<par<<endl;
	

	return 0;
}