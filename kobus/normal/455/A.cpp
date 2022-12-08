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
#define INF INT_MAX;
#define MOD 1000000

int v[112345];

int memo[112345][2];

int pd(int cara, bool pegou){
	if(cara==112345)return 0;
	if(memo[cara][pegou]==-1){
		memo[cara][pegou]=pd(cara+1,0);
		if(!pegou){
			memo[cara][pegou]=max(memo[cara][pegou],cara*v[cara]+pd(cara+1,1));
		}
	}
	return memo[cara][pegou];
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int y;cin>>y;
		v[y]++;
	}

	for(int i=0;i<112345;i++){
		memo[i][0]=-1;
		memo[i][1]=-1;
	}

	cout<<pd(0 ,0)<<endl;

	return 0;
}