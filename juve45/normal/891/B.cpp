#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 23
#define NMAX 1
#define MMAX 1

using namespace std;

int n, k, x, a[DMAX], b[DMAX];
unordered_map <int, int> pos;

long long calc(int mask)
{
	int i = 1;
	long long ans = 0;
	while(mask)
	{
		if(mask % 2)
			ans += a[i];
		mask /= 2;
		i++;
	}
	return ans;
}

void solve(int k)
{

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], pos[a[i]] = i;

	sort(a + 1, a + n + 1);

	b[pos[a[1]]] = a[n];
	for(int i = 2; i <= n; i++)
	{
		b[pos[a[i]]] = a[i - 1];
	}
	for(int i = 1; i <= n; i++)
		cout << b[i] << ' ';
}