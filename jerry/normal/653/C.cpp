#include <bits/stdc++.h>
using namespace std;

vector<int> v;
set<int> can;
int arr[150005];
int ans;
int n;

bool ok(int i)
{
	if (i > 0)
	{
		if (i%2 == 0)
		{
			if (arr[i] >= arr[i-1]) return false;
		} else if (arr[i] <= arr[i-1]) return false;
	}
	if (i+1 < n)
	{
		if (i%2 == 0)
		{
			if (arr[i] >= arr[i+1]) return false;
		} else if (arr[i] <= arr[i+1]) return false;
	}
	return true;
}

bool ok()
{
	for (int i = 0;i < n-1;i++)
		if (i%2 == 0)
		{
			if (arr[i] >= arr[i+1]) return false;
		} else
		{
			if (arr[i] <= arr[i+1]) return false;
		}
	return true;
}

void foo(int a, int b)
{
	swap(arr[a], arr[b]);
	if (ok()) ans++;
	swap(arr[a], arr[b]);
}

void foo(int a)
{
	for (int i = 0;i < n;i++) if (i != a)
	{
		swap(arr[i], arr[a]);
		if (ok(i) && ok(a))
			ans++;
		swap(arr[i], arr[a]);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", arr+i);
	for (int i = 0;i < n-1;i++)
		if (i%2 == 0)
		{
			if (arr[i] >= arr[i+1])
				can.insert(i);
		} else
		{
			if (arr[i] <= arr[i+1])
				can.insert(i);
		}
	for (int u: can) v.push_back(u);
	if (v.size() == 1)
	{
		foo(v[0]);
		foo(v[0]+1);
		swap(arr[v[0]], arr[v[0]+1]);
		if (ok()) ans--;
	} else if (v.size() == 2)
	{
		if (v[0]+1 != v[1])
		{
			foo(v[0], v[1]);
			foo(v[0]+1, v[1]);
			foo(v[0], v[1]+1);
			foo(v[0]+1, v[1]+1);
		} else
		{
			foo(v[0], v[1]+1);
			foo(v[1]);
		}
	} else if (v.size() == 3)
	{
		if (v[0]+1 == v[1] && v[1]+1 == v[2])
		{
			foo(v[0], v[2]);
			foo(v[1], v[2]);
			foo(v[1], v[2]+1);
		} else if (v[0]+1 == v[1])
		{
			foo(v[1], v[2]);
			foo(v[1], v[2]+1);
		} else if (v[1]+1 == v[2])
		{
			foo(v[0], v[2]);
			foo(v[0]+1, v[2]);
		}
	} else if (v.size() == 4)
	{
		if (v[0]+1 == v[1] && v[2]+1 == v[3])
		{
			foo(v[1], v[3]);
		}
	}
	printf("%d\n", ans);
	return 0;
}