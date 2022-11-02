#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ap
{
	int a, b, i;
	ap(int a, int b, int i) : a(a), b(b), i(i) {};
	ap() : a(0), b(0), i(i) {};
	bool operator<(const ap &r) const {
		return b > r.b;
	}
};

vector<ap> v, tv;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;	
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		if (a < b) v.push_back(ap(a, b, i));
		else tv.push_back(ap(a, b, i));
	}
	bool f = false;
	if (v.size() < tv.size()) {
		v = tv;
		f = true;
	}
	sort(v.begin(), v.end());
	if (f) reverse(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i].i << " ";
	cout << '\n';
	return 0;
}