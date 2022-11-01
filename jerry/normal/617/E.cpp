#include <bits/stdc++.h>
using namespace std;

struct query
{
	int l, r, id; long long ans;
	bool operator< (const query& oth) const
	{
		if (l/300 != oth.l/300) return (l/300 < oth.l/300);
		return (r < oth.r);
	}
} qu[100005];

int _h[1100000], _l, _r; long long _a;

int arr[100005];
int n, m, k;

void _h_add(int _val)
{
	_a += _h[k^_val];
	++_h[_val];
}

void _h_rem(int _val)
{
	--_h[_val];
	_a -= _h[k^_val];
}

bool cmp(const query& a, const query& b)
{
	return (a.id < b.id);
}

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++) cin >> arr[i];
	for (int i = 1;i <= n;i++) arr[i] ^= arr[i-1];
	for (int i = 0;i < m;i++)
	{
		cin >> qu[i].l >> qu[i].r;
		qu[i].l--;
		qu[i].id = i;
	}
	sort(qu, qu+m);
	_h_add(arr[0]);
	for (int i = 0;i < m;i++)
	{
		while (_l > qu[i].l) _h_add(arr[--_l]);
		while (_r < qu[i].r) _h_add(arr[++_r]);
		while (_r > qu[i].r) _h_rem(arr[_r--]);
		while (_l < qu[i].l) _h_rem(arr[_l++]);
		qu[i].ans = _a;
	}
	sort(qu, qu+m, cmp);
	for (int i = 0;i < m;i++)
		cout << qu[i].ans << "\n";
	return 0;
}