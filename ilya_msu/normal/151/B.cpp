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
	vector<string> taxi, pizza, girls;
	int mtaxi, mpizza, mgirls;
	mtaxi = mpizza = mgirls = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int s;
		string name;
		cin >> s >> name;
		int ntaxi, npizza, ngirls;
		ntaxi = npizza = ngirls = 0;
		for (int j = 0; j < s; ++j) {
			string number;
			cin >> number;
			string nomer = number.substr(0, 2);
			nomer += number.substr(3, 2);
			nomer += number.substr(6, 2);
			bool t = true;
			for (int k = 1; k < 6; ++k)
				t = t && (nomer[k] == nomer[0]);
			if (t) {
				++ntaxi;
				continue;
			}
			bool p = true;
			for (int k = 1; k < 6; ++k)
				p = p && (nomer[k] < nomer[k - 1]);
			if (p)
				++npizza;
			else
				++ngirls;
		}
		if (ntaxi == mtaxi) {
			taxi.push_back(name);
		}
		if (ntaxi > mtaxi) {
			mtaxi = ntaxi;
			taxi.resize(0);
			taxi.push_back(name);
		}
		if (npizza == mpizza) {
			pizza.push_back(name);
		}
		if (npizza > mpizza) {
			mpizza = npizza;
			pizza.resize(0);
			pizza.push_back(name);
		}
		if (ngirls == mgirls) {
			girls.push_back(name);
		}
		if (ngirls > mgirls) {
			mgirls = ngirls;
			girls.resize(0);
			girls.push_back(name);
		}
	}
	cout << "If you want to call a taxi, you should call:";
	for (int i = 0; i < taxi.size() - 1; ++i)
		cout << " " << taxi[i] << ",";
	cout << " " << taxi.back() << "." << endl;
	cout << "If you want to order a pizza, you should call:";
	for (int i = 0; i < pizza.size() - 1; ++i)
		cout << " " << pizza[i] << ",";
	cout << " " << pizza.back() << "." << endl;
	cout << "If you want to go to a cafe with a wonderful girl, you should call:";
	for (int i = 0; i < girls.size() - 1; ++i)
		cout << " " << girls[i] << ",";
	cout << " " << girls.back() << "." << endl;
 	return 0;
}