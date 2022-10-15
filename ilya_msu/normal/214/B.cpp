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

void print(const vector<int>& data) {
	for (int i = 0; i < data.size(); ++i)
		cout << data[i];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int c = 0;
	vector<int> data(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
		sum += data[i];
		if ((data[i] == 3) || (data[i] == 6) || (data[i] == 9))
			++c;
	}
	if (sum == 0) {
		cout << 0 << endl;
		return 0;
	}
	sum = sum % 3;
	sort(data.begin(), data.end());
	reverse(data.begin(), data.end());
	if (data.back() > 0) {
		cout << -1 << endl;
		return 0;
	}
	if (sum == 0) {
		print(data);
		cout << endl;
		return 0;
	}
	int i = (int)data.size() - 1;
	while(i >= 0) {
		if (data[i] % 3 == sum)
			break;
		--i;
	}
	if (i >= 0) {
		if (data[1] > 0) {
		print(vector<int> (data.begin(), data.begin() + i));
		print(vector<int> (data.begin() + i + 1, data.end()));
		cout << endl;
		}
		else
			cout << 0 << endl;
		return 0;
	}
	int i1 = (int)data.size() - 1;
	while(i1 >= 0) {
		if (data[i1] % 3 > 0)
			break;
		--i1;
	}
	int i2 = i1 - 1;
	while(i2 >= 0) {
		if (data[i2] % 3 > 0)
			break;
		--i2;
	}
	if ((i2 == 0) && (c == 0)) {
		cout << 0 << endl;
		return 0;
	}
	
	print(vector<int> (data.begin(), data.begin() + i2));
	print(vector<int> (data.begin() + i2 + 1, data.begin() + i1));
	print(vector<int> (data.begin() + i1 + 1, data.end()));
	cout << endl;

	return 0;
}