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
#define INF INT_MAX/2
#define MOD 1000000007

int n,m;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(11);
  	cout.setf(ios::fixed);

  	cin>>n>>m;

  	if(n>40){
  		cout<<m<<endl;
  		return 0;
  	}
  	int resp=0;
  	for(int i=0;i<n;i++){
  		if((m>>i)%2==1){
  			resp+=(1<<i);
  		}
  	}
  	cout<<resp<<endl;


  	


}