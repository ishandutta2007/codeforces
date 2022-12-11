#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

struct data
{
	int val, id, cnt;
	bool operator<(const data& other) const
	{
		if (val != other.val) {
			return val < other.val;
		}
		return cnt > other.cnt;
	}
};

int main()
{

	//freopen("input.txt", "r", stdin);
	//ifstream cin("input.txt");

	int n, m;
	scanf("%d%d", &n, &m);

	vector<int> a(n), b(m);
	vector<int> ans(n, -1);

	multiset<pii> alive;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		alive.insert({a[i], i});
	}
	multiset<data> s;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
		s.insert({b[i], i, 0});
	}

	int cnt = 0, spent = 0;
	vector<int> v(m);

	while (!s.empty() && !alive.empty()) {
		multiset<data>::iterator socket = s.end();
		--socket;
		multiset<pii>::iterator computer = alive.end();
		--computer;
		if ((*computer).first == (*socket).val) {
			ans[(*computer).second] = (*socket).id;
			v[(*socket).id] = (*socket).cnt;
			++cnt;
			spent += (*socket).cnt;
			s.erase(socket);
			alive.erase(computer);
			continue;
		}
		if ((*computer).first > (*socket).val) {
			alive.erase(computer);
			continue;
		}
		data p = *socket;
		p.val = (p.val + 1) >> 1;
		++p.cnt;
		s.erase(socket);
		s.insert(p);
	}

	printf("%d %d\n", cnt, spent);
	for (int i = 0; i < m; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");

	for (int i = 0; i < n; ++i) {
		printf("%d ", ans[i] + 1);
	}
	printf("\n");

}