#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long bit[100010];
int p = 1, mod = 1000000007;

long long sum(int i)
{
     long long s = 0;

     while (i > 0) {
	  s += bit[i];
	  s %= mod;

	  i -= i & -i;
     }

     return s;
}

void add(int i, long long x)
{
     if (i <= 0) return;

     while (i <= p) {
	  bit[i] += x;
	  bit[i] %= mod;

	  i += i & -i;
     }
}

int main()
{
     int n, m, i, j;
     vector <pair<int, int> > v;
     map <int, int> mp;
     map <int, int>::iterator it;

     scanf("%d %d", &n, &m);

     for (i = 0; i < m; i++) {
	  int s, t;

	  scanf("%d %d", &s, &t);

	  v.push_back(make_pair(t, s));

	  mp[t] = 1;
     }

     mp[0] = 1;

     for (it = mp.begin(); it != mp.end(); it++) {
	  it->second = p++;
     }

     p--;

     sort(v.begin(), v.end());

     add(1, 1);

     for (i = 0; i < v.size(); i++) {
	  it = mp.lower_bound(v[i].second);

	  add(mp[v[i].first], (sum(mp[v[i].first] - 1) - sum(it->second - 1) + mod) % mod);
     }

     if (mp[n] == 0) {
	  puts("0");
     } else {
	  printf("%I64d\n", (sum(mp[n]) - sum(mp[n] - 1) + mod) % mod);
     }

     return 0;
}