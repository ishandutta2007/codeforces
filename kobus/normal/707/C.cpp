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

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	if(n==1 || n==2){
		cout<<-1<<endl;
		return 0;
	}
	if(n%2==1){
		cout<<(n*n+1)/2<<" "<<(n*n-1)/2<<endl;
		return 0;
	}
	n=(n*n)/4;
	cout<<n+1<<" "<<n-1<<endl;

	
	return 0;
}