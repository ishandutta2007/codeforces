#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
struct Node
{
	int min = INF;
	int max = -INF;
};

Node tree[900000];
vector<int> mass;

void build(int now, int l, int r)
{
	if(l == r)
	{
		tree[now].max = mass[l];
		tree[now].min = mass[l];
		return;
	}
	int mid = (l + r) / 2;
	build(now * 2, l, mid);
	build(now * 2 + 1, mid + 1, r);
	tree[now].max = max(tree[now * 2].max, tree[now * 2 + 1].max);
	tree[now].min = min(tree[now * 2].min, tree[now * 2 + 1].min);
}

int get_min(int now, int l, int r, int l1, int r1)
{
	if(l > r1 || l1 > r)
	{
		return INF;
	}
	if(l >= l1 && r <= r1)
	{
		return tree[now].min;
	}
	int mid = (l + r) / 2;
	return min(get_min(now * 2, l, mid, l1, r1), get_min(now * 2 + 1, mid + 1, r, l1, r1));
}
int get_max(int now, int l, int r, int l1, int r1)
{
	if(l > r1 || l1 > r)
	{
		return -INF;
	}
	if(l >= l1 && r <= r1)
	{
		return tree[now].max;
	}
	int mid = (l + r) / 2;
	return max(get_max(now * 2, l, mid, l1, r1), get_max(now * 2 + 1, mid + 1, r, l1, r1));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--)
    {
    	int n, m;
    	cin >> n >> m;
    	string s;
    	cin >> s;
    	mass.resize(n);
    	if(s[0] == '-')
    	{
    		mass[0] = -1;
    	}
    	else
    	{
    		mass[0] = 1;
    	}
    	for(int i = 1; i < n; i++)
    	{
    		mass[i] = mass[i - 1];
    		if(s[i] == '-')
    		{
    			mass[i]--;
    		}
    		else
    		{
    			mass[i]++;
    		}
    	}
    	build(1, 0, n - 1);
    	for(int i = 0; i < m; i++)
    	{
    		int l, r;
    		cin >> l >> r;
    		--l;
    		--r;
    		if(l == 0 && r == n - 1)
    		{
    			cout << "1\n";
    			continue;
    		}
    		int lmin = INF, lmax = -INF, rmin = INF, rmax = -INF;
    		if(l > 0)
    		{
    			lmax = get_max(1, 0, n - 1, 0, l - 1);
    			lmin = get_min(1, 0, n - 1, 0, l - 1);
    		}
    		if(r < n - 1)
    		{
    			rmax = get_max(1, 0, n - 1, r + 1, n - 1) - mass[r];
    			rmin = get_min(1, 0, n - 1, r + 1, n - 1) - mass[r];
    			if(l > 0)
    			{
    				rmax += mass[l - 1];
    				rmin += mass[l - 1];
    			}
    		}
    		int max1 = max(rmax, lmax);
    		int min1 = min(lmin, rmin);
    		int ans = max1 - min1 + 1;
    		if(0 > max1 || 0 < min1)
    		{
    			++ans;
    		}
    		cout << ans << '\n';
    	}
    }
}