#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-15;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

int num=0;
int a[100010];

int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)scanf("%d",a+i),num+=a[i];
	while(q--){
		int t,v;
		scanf("%d%d",&t,&v);
		if(t==1){
			num-=a[v-1];
			a[v-1]=1-a[v-1];
			num+=a[v-1];
		}
		else{
			//cerr<<(num>=v) <<endl;
			printf("%d\n",(num>=v)?1:0);
		}
	}
}