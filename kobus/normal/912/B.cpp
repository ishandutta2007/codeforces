#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 3123
#define INF LLONG_MAX
#define MOD 1000000007


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k,n;
	cin>>n>>k;

	if(k==1){
		cout<<n<<endl;
		return 0;
	}

	int num=1;

	while(n>=num)num=num*2;

	cout<<num-1<<endl;


  	return 0;

}