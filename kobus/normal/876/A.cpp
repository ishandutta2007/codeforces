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

int v[3];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	int a,b,c;
	cin>>a>>b>>c;

	if(n==1){
		cout<<0<<endl;
		return 0;
	}

	cout<<min(a,b)+(n-2)*min(min(a,b),c)<<endl;


	return 0;
}