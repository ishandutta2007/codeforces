#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000007
//#define int long long


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a,b;
	cin>>a>>b;

	if(a<=2*b && b<=2*a){
		cout<<(a+b)/3<<endl;
	}
	else{
		cout<<min(a,b)<<endl;
	}

	return 0;
}