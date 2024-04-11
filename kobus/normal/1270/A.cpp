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

	int t;
	cin>>t;
	while(t--){
		int n,k1,k2;
		cin>>n>>k1>>k2;
		int num1=0,num2=0;
		for(int i=0;i<k1;i++){
			int x;
			cin>>x;
			num1=max(num1,x);
		}
		for(int i=0;i<k2;i++){
			int x;
			cin>>x;
			num2=max(num2,x);
		}
		if(num1>num2)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}