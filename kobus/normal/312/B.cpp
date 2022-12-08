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

  	int a,b,c,d;
  	cin>>a>>b>>c>>d;

  	ld p1=(1.*a)/(1.*b);
  	ld p2=(1.*c)/(1.*d);

  	ld p=p1/(1-(1-p1)*(1-p2));

  	cout<<p<<endl;


	return 0;
}