#include <bits/stdc++.h>
using namespace std;

struct data
{
	int a, b, x;
	bool operator< (const data& oth) const
	{
		return (a > oth.a);
	}
} arr[200005];
map<int, int> hv;
int ans[200005];
int n, m;

int bit[400005];
int qu(int x)
{
	int a = 0; for (;x;x-=x&-x) a += bit[x];
	return a;
}
void upd(int x)
{
	for (;x<400005;x+=x&-x) bit[x]++;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d%d", &arr[i].a, &arr[i].b);
		arr[i].x = i;
		hv[arr[i].a], hv[arr[i].b];
	}
	for (auto it = hv.begin();it != hv.end();it++)
		it->second = ++m;
	for (int i = 0;i < n;i++)
		arr[i].a = hv[arr[i].a], arr[i].b = hv[arr[i].b];
	sort(arr, arr+n);
	for (int i = 0;i < n;i++)
	{
		ans[arr[i].x] = qu(arr[i].b);
		upd(arr[i].b);
	}
	for (int i = 0;i < n;i++) printf("%d\n", ans[i]);
	return 0;
}