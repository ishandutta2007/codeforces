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
#include<ctime>
 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-8;
const ll INF = 777777777777 + 1;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<ll> data(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
	}
	vector<ll> b;
	b.push_back(1);
	b.push_back(4);
	for (int i = 1; i < b.size(); ++i) {
		ll x = b[i];
		if (x < 881918)
			b.push_back(x * x);
		if (x < 1000)
			b.push_back((x - 1) * (x - 1) * (x - 1) * (x - 1) + 1);
	}
	b.push_back(INF);
	sort(b.begin(), b.end());
	vector<int> nim(b.size() - 1);
	nim[0] = 0;
	for (int i = 1; i < nim.size(); ++i) {
		int down = sqrt(sqrt(double(b[i]))) + 0.9999999;
		int up = sqrt((double)(b[i + 1] - 1));
		vector<int> used(20, false);
		for (int j = 0; j < i; ++j) {
			if ((((b[j] <= up) && (b[j] >= down)) || ((b[j + 1] - 1 <= up) && (b[j + 1] - 1 >= down))) || ((b[j] <= down) && (b[j + 1] - 1 >= up)))
				used[nim[j]] = true;
		}
		for (int j = 0; j < 20; ++j) {
			if (!used[j]) {
				nim[i] = j;
				break;
			}
		}
	}
	vector<int> nimber(n);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j + 1 < b.size(); ++j)
			if ((data[i] >= b[j]) && (data[i] <= b[j + 1] - 1))
				nimber[i] = nim[j];
		res = res ^ nimber[i];
	}
	if (res == 0)
		cout << "Rublo" << endl;
	else
		cout << "Furlo" << endl;
	return 0;
}