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

pii v[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	int yl=-1;

	for(int i=0;i<n;i++){
		int y;
		cin>>y;
		while(y%2==0)y/=2;
		while(y%3==0)y/=3;
		if(yl==-1)yl=y;
		else if(yl!=y){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";

	return 0;
}