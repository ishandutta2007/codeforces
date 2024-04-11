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

int v[MAXN];
int r[MAXN];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(11);
  	cout.setf(ios::fixed);

  	int n,q;
  	cin>>n>>q;

  	for(int i=0;i<n;i++)cin>>v[i];
  	set<int> s;
  	for(int i=n-1;i>=0;i--){
  		s.insert(v[i]);
  		r[i]=s.size();
  	}
  	for(int i=0;i<q;i++){
  		int qu;
  		cin>>qu;
  		cout<<r[qu-1]<<endl;
  	}


	return 0;
}