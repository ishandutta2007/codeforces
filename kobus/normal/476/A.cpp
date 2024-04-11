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

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin>>n>>m;

	int one=(n%2==1);

	for(int two=n/2;two>=0;two--){
		if((one+two)%m==0){
			cout<<(one+two)<<endl;
			return 0;
		}
		one+=2;
	}

	cout<<"-1"<<endl;


	return 0;
}