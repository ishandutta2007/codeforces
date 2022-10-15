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

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  



int main() {
	//freopen("input.txt", "r", stdin);
	int n, d, s;
	ll sum = 0;
	int add = 0;
	cin >> n >> d >> s;
	vector<pii> can, ne;
	for (int i = 0; i < n; ++i) {
		int c, l, f;
		cin >> c >> f >> l;
		sum += c;
		pii p(f, c);
		if (l < d) {
			ne.push_back(p);
			if (c)
				++add;
		}
		else
			can.push_back(p);
	}
	sort(can.begin(), can.end());
	int mr = 0;
	ll fuel = 0;
	while ((mr < can.size()) && (fuel + can[mr].first <= s)) {
		fuel += can[mr].first;
		++mr;
	}
	vector<pii> cacan, necan;
	for (int i = 0; i < can.size(); ++i) {
		if (can[i].second)
			cacan.push_back(can[i]);
		else
			necan.push_back(can[i]);
	}
	vector<ll> cacans(cacan.size());
	for (int i = 0; i < cacan.size(); ++i) {
		if (i)
			cacans[i] = cacans[i - 1] + cacan[i].first;
		else
			cacans[i] = cacan[i].first;
	}
	for (int k = 1; k <= cacan.size(); ++k) {
		ll free = sum - (int)(cacan.size()) + k - add;
		ll fu = cacans[k - 1];
		if (fu > s)
			continue;
		int num = necan.size() + ne.size() - add;
		if (num <= free) {
			if (mr < n) {
				mr = n;
				fuel = fu;
			}
			else
				if (mr == n) {
					if (fuel > fu)
						fuel = fu;
				}
			continue;
		}
		num -= free;
		int mmr = n - num;
		for (int i = 0; i < min(num, (int)necan.size()); ++i) {
			if (fu + necan[i].first <= s) {
				++mmr;
				fu += necan[i].first;
			}
			else
				break;
		}
		if (mmr > mr) {
			mr = mmr;
			fuel = fu;
		}
		else
			if (mmr == mr)
				if (fuel > fu)
					fuel = fu;
	}
	cout << mr << " " << fuel << endl;
	return 0;
}