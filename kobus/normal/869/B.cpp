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
#define INF LLONG_MAX/4
#define MOD 1000000007

int v1[2123];
int v2[2123];


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;

	if(m-n>=10){
		cout<<0<<endl;
		return 0;
	}
	int resp=1;
	for(int i=n+1;i<=m;i++){
		int num=i%10;
		resp=resp*num;
		resp=resp%10;
	}

	cout<<resp<<endl;





	return 0;
}