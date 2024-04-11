#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 11234
#define INF LLONG_MAX
#define MOD (1ll<<(32)) 
#define pii pair<int,int> 

 
int32_t main(){

	int n;
	cin>>n;
	int nxt=1;
	int i=2;
	while(n>=nxt){
		n-=nxt;
		nxt+=i;
		i++;
	}
	cout<<i-2<<endl;

	return 0;
}