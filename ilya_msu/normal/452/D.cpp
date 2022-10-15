#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
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

 
using namespace std; 
#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
//const int N = 1000 * 1000 * 1000 + 10;
const int mod = 1000 * 1000 * 1000 + 7;


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k, n1, n2, n3, t1, t2, t3;
	cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
	queue<int> q1, q2, q3;
	int t = 0;
	for (int i = 0; i < k; ++i) {
		if (q1.size() == n1) {
			t = max(t, q1.front());
			q1.pop();
		}
		if (q2.size() == n2) {
			t = max(t, q2.front() - t1);
			q2.pop();
		}
		if (q3.size() == n3) {
			t = max(t, q3.front() - t1 - t2);
			q3.pop();
		}
		q1.push(t + t1);
		q2.push(t + t1 + t2);
		q3.push(t + t1 + t2 + t3);
	}
	cout << q3.back() << endl;

	
    return 0;
}