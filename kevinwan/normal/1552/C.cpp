#include <bits/stdc++.h>
using namespace std;
 
mt19937_64 rng(time(0));
const long double eps = 1e-15;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
const int mn=1e5+10;
const ll mod=1e9+7;

int a[mn],b[mn];
int p[mn],dep[mn];
bool u[mn];
bitset<300> msk[300];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	while(tc--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<k;i++){
			cin>>a[i]>>b[i];
			if(a[i]>b[i])swap(a[i],b[i]);
		}
		for(int i=1;i<=2*n;i++)u[i]=1;
		for(int i=0;i<k;i++)u[a[i]]=u[b[i]]=0;
		vi v;
		for(int i=1;i<=2*n;i++)if(u[i])v.push_back(i);
		for(int i=0;i<n-k;i++){
			a[k+i]=v[i];
			b[k+i]=v[i+(n-k)];
		}
		for(int i=0;i<n;i++)p[a[i]]=p[b[i]]=i;
		for(int i=1;i<=2*n;i++){
			msk[i]=msk[i-1];
			msk[i][p[i]]=msk[i][p[i]]^1;
		}
		int num=0;
		for(int i=0;i<n;i++){
			bitset<300> m = msk[b[i]]^msk[a[i]-1];
			num+=m.count();
		}
		printf("%d\n",num/2);
	}
}