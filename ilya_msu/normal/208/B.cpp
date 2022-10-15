#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
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

using std::pair;
using std::stringstream;
using std::next_permutation;
using std::sqrt;
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::set;
using std::swap;
using std::random_shuffle;
using std::queue;
using std::sin;
using std::cos;
using std::make_pair;
using std::cos;
using std::cerr;
using std::map;

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  

bool ans = false;
map<vector<string>,int> m;
vector<string> a;
int n;

void rec(vector<string>a){
	if (m[a])
		return;
	m[a] = 1;
	int x = a.size();
	if (x == 1)
		ans = true;
	if (x > 1 && (a[x - 1][0] == a[x - 2][0] || a[x - 1][1] == a[x - 2][1])){
		vector<string>b = a;
		b[x - 2] = b[x - 1];
		b.erase(b.end() - 1);
		rec(b);
	}
	if (x > 3 &&(a[x - 1][0] == a[x - 4][0] || a[x - 1][1] == a[x - 4][1])){
		vector<string> b = a;
		b[x - 4] = b[x - 1];
		b.erase(b.end() - 1);
		rec(b);
	}
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	rec(a);
	if (ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}