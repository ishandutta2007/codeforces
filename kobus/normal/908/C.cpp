#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
typedef long double ld;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007

int n;
ld r;
ld v[112345];
//forma x y
pair<long double,long double> c[112345];

long double ch(int i,int j){
	ld dis=v[i]-c[j].f;
	if(dis>2*r)return 0;
	dis=dis*dis;
	ld disc=4*r*r;
	return c[j].s+sqrtl(disc-dis);
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(11);
  	cout.setf(ios::fixed);

	cin>>n>>r;

	for(int i=0;i<n;i++){
		cin>>v[i];
		ld height=1.*r;
		for(int j=0;j<i;j++){
			height=max(height,ch(i,j));
		}
		c[i].f=v[i];
		c[i].s=height;
	}

	for(int i=0;i<n;i++){
		cout<<c[i].s<<endl;
	}



	return 0;
}