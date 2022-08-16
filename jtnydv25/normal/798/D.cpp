#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define vll vector<ll >
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define endl "\n"
const int N = 100005;
int A[N], B[N];
static unsigned generate_key() {
	static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned t = x ^ x<<11;
	x = y; y = z; z = w;
	return w = w ^ w>>19 ^ t ^ t>>8;
}
void shuffle(vector<int> &vec){
	int n = vec.size();
	for(int i = 0; i < n; i++){
		int p = i + (generate_key() % (n - i));
		swap(vec[i], vec[p]);
	}
}
vector<int> vec;
int main(){
	int t = 1, n;
	sd(n);
	ll X = 0, Y = 0;
	for(int i = 1; i <= n; i++) sd(A[i]), X += A[i];
	for(int i = 1; i <= n; i++) sd(B[i]), vec.pb(i), Y += B[i];
		int sz = (n / 2) + 1;
	srand(time(NULL));
	while(1){
		ll x = 0, y = 0;
		for(int i = 0; i < sz; i++) x += A[vec[i]], y += B[vec[i]];
		if(2 * x > X && 2 * y > Y){
			pd(sz);
			for(int i = 0; i < sz; i++) printf("%d ", vec[i]);
			return 0;
		}
		// random_shuffle(vec.begin(), vec.end());
		shuffle(vec);
	}
}