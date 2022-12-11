#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

struct pt
{
	int x, y;
	pt(int x, int y) : x(x), y(y) {}
	pt() {}
	pt operator-(const pt& other) const
	{
		return {x - other.x, y - other.y};
	}
	pt operator+(const pt& other) const
	{
		return {x + other.x, y + other.y};
	}
	bool operator<(const pt& other) const
	{
		if (x != other.x) {
			return x < other.x;
		}
		return y < other.y;
	}
};

int main()
{

	//ifstream cin("input.txt");

	//freopen("input.txt", "r", stdin);

	pt a, b, c;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;

	set<pt> s;
	pt v = b - a;
	s.insert(c + v);
	s.insert(c - v);

	v = c - a;
	s.insert(b + v);
	s.insert(b - v);

	cout << sz(s) << "\n";
	for (pt p : s) {
		cout << p.x << " " << p.y << "\n";
	}

}