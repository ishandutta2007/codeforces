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

int v[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,s;
	cin>>n>>s;

	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v,v+n);
	for(int i=n-1;i>=0;i--){
		s-=v[i];
		if(s<=0){
			cout<<n-i<<endl;
			return 0;
		}
	}

	

	return 0;
}