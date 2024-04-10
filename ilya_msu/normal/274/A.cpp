#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:128000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<unordered_map>

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
//const int N = 100 * 1000 + 1;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	vector<pii> data(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &data[i].first);
		data[i].second = 0;
		if (k > 1) {
		while(data[i].first % k == 0) {
			data[i].first /= k;
			++data[i].second;
		}	
		}
	}
	if (k == 1) {
		cout << n << endl;
		return 0;
	}
	sort(data.begin(), data.end());
	int res = 1;
	bool c = true;
	for (int i = 1; i < n; ++i) {
		if (data[i].first > data[i - 1].first) {
			++res;
			c = true;
		}
		else {
			++res;
			if ((c) && (data[i].second <= data[i - 1].second + 1)) {
				c = false;
				--res;
			}
			else
				c = true;
		}
	}
	cout << res << endl;
	return 0;
}