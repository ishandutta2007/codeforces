#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 100002;
const int mod = 1000000007;
const double eps = 1e-8;

int c[maxn];
bool capit[maxn];
vector<int> cap;

int main()
{
	int n,k;
	cin >> n >> k;
	ll ans = 0;
	ll sum = 0;
	for(int i=0;i<n;i++){
		cin >> c[i];
		sum += c[i]*2;
	}
	int a;
	cap.clear();
	for(int i=0;i<k;i++){
		cin >> a;
		a--;
		cap.push_back(a);
		capit[a] = true;
		sum -= c[a];
	}
	for(int i=0;i<n;i++){
		ans += c[i]*c[(i+1)%n]*2;
	}
	for(size_t i=0;i<cap.size();i++){
		ans += c[cap[i]]*(sum-c[cap[i]]);
		if(capit[(cap[i]+1)%n]){
			ans -= c[cap[i]]*c[(cap[i]+1)%n];
		}else{
			ans -= c[cap[i]]*c[(cap[i]+1)%n]*2;
		}
		if(capit[(cap[i]+n-1)%n]){
			ans -= c[cap[i]]*c[(cap[i]+n-1)%n];
		}else{
			ans -= c[cap[i]]*c[(cap[i]+n-1)%n]*2;
		}
	}
	cout << ans/2;
}