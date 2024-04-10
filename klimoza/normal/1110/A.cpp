#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")												
#pragma GCC optimize("rename-registers")									
#pragma GCC optimize("move-loop-invariants")								
#pragma GCC optimize("unswitch-loops")											
#pragma GCC optimize("function-sections")										
#pragma GCC optimize("data-sections")										
#pragma GCC optimize("branch-target-load-optimize")							
#pragma GCC optimize("branch-target-load-optimize2") 						
#pragma GCC optimize("btr-bb-exclusive")
#pragma comment(linker, "/stack:200000000")


#include <iostream>
#include <vector>	
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 998244353;
double eps = 1e-7;


int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int b, k;
	cin >> b >> k;
	vector<int> a(k);
	for (int i = 0; i < k; i++) cin >> a[i];
	if (b % 2 == 0) {
		if (a[k - 1] % 2 == 0) {
			cout << "even\n";
		}
		else {
			cout << "odd\n";
		}
	}
	else {
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			if (a[i] % 2 == 1) cnt++;
		}
		if (cnt % 2 == 0) {
			cout << "even\n";
		}
		else {
			cout << "odd\n";
		}
	}
	//system("pause");
	/*
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> b(m);
	for(int i = 0; i < m; i++) cin >> b[i];
	if(k >= n){
		cout << n << endl;
		return 0;
	} else{
		vector<int> f(m - 1);
		for(int i = 0; i < m - 1; i++){
			f[i] = b[i + 1] - b[i];
		}
	}
	*/
	return 0;
}