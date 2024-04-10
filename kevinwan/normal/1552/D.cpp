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

int a[mn];
int p3[11];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	p3[0]=1;
	for(int i=1;i<=10;i++)p3[i]=p3[i-1]*3;
	int tc;
	cin>>tc;
	while(tc--){
		bool suc=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<p3[n];i++){
			bool pos = 0, neg = 0;
			int sum=0;
			for(int j=0;j<n;j++){
				int ch=i/p3[j]%3;
				if(ch==0)neg=1,sum-=a[j];
				if(ch==2)pos=1,sum+=a[j];
			}
			if((pos||neg)&&sum==0){
				suc = 1;
				break;
			}
		}
		for(int i=0;i<n;i++)if(a[i]==0)suc=1;
		printf("%s\n",suc?"YES":"NO");
	}
}