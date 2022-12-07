#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define rep(i,a,b) for(int i=a;i<b;++i)


int main(){
	int n;
	cin >> n;
	vi a(n , 0);
	rep(i,0,n) cin >> a[i];
	sort(a.begin() , a.end());
	rep(i,0,n) cout << a[i] << " \n"[i+1==n];
	double t1 = clock();
	while((clock() - t1) / CLOCKS_PER_SEC <= 1.5);
	return 0;
}