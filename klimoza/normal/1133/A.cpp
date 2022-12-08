#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	string s1, s2;
	cin >> s1 >> s2;
	int h1, m1, h2, m2;
	h1 = (s1[0] - '0') * 10 + s1[1] - '0';
	m1 = (s1[3] - '0') * 10 + s1[4] - '0';
	h2 = (s2[0] - '0') * 10 + s2[1] - '0';
	m2 = (s2[3] - '0') * 10 + s2[4] - '0';
	int to1 = h1 * 60 + m1;
	int to2 = h2 * 60 + m2;
	int av = (to1 + to2) / 2;
	if (av / 60 < 10) cout << "0";
	cout << av / 60 << ":";
	if (av % 60 < 10) cout << "0";
	cout << av % 60 << endl;
	//system("pause");
	return 0;
}