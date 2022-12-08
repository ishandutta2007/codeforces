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
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(11);
  	cout.setf(ios::fixed);

  	int n;
  	cin>>n;

  	cout<<(n*n+1)/2<<endl;

  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			if(i%2==j%2)cout<<"C";
  			else cout<<".";
  		}
  		cout<<endl;
  	}

	return 0;
}