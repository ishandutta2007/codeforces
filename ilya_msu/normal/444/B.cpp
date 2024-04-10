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

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)
 
using namespace std;  
 
typedef long long ll; 
typedef unsigned long long ull; 

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 2 * 1000 * 1000 * 1000 + 10;
const ll LLINF = (ll)4 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int N = 1000 * 1000 * 1000 + 100;
const int mod = 1000 * 1000 * 1000 + 7;

ll x;
int n, d;
vector<int> a, b;

ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB() {
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for (int i = 0; i < n; ++i) {
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for (int i = 0; i < n; ++i){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> d >> x;
	a.assign(n, 0);
	b.assign(n, 0);
	initAB();
	vector<int> ed;
	for (int i = 0; i < n; ++i)
		if (b[i])
			ed.push_back(i);
	vector<int> ind(n + 1);
	for (int i = 0; i < n; ++i)
		ind[a[i]] = i;
	vector<int> c(n, 0);
	int s = 30;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < s; ++j) {
			int x = ind[n - j];
			if ((i - x >= 0) && (b[i - x])) {
				c[i] = n - j;
				break;
			}
		}
		if (c[i])
			continue;
		for (int j = 0; j < ed.size(); ++j) {
			if (ed[j] > i)
				break;
			c[i] = max(c[i], a[i - ed[j]]);
		}
	}
	for (int i = 0; i < n; ++i)
		cout << c[i] << "\n";	
    return 0;
}