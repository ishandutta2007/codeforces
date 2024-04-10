#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> tree;


string s;
int k;

int get_id(int l, int r)
{
	int now = 2;
	int here = 0;
	while(r - l + 1 > now)
	{
		here = here + (1 << k) / now;
		now *= 2;
	}
	here += l / (r - l + 1);
	return here;
}

void build(int now, int l, int r)
{
	if(l == r)
	{
		tree[now] = 1;
		return;
	}
	int mid = (l + r) / 2;
	build(now * 2, l, mid);
	build(now * 2 + 1, mid + 1, r);
	int id1 = get_id(l, r);
	if(s[id1] == '0')
	{
		tree[now] = tree[now * 2];
	}
	else if(s[id1] == '1')
	{
		tree[now] = tree[now * 2 + 1];
	}
	else
	{
		tree[now] = tree[now * 2 + 1] + tree[now * 2];
	}
}

pair<int, int> get_otr(int id1)
{
	int now = 0;
	int here = 1 << (k - 1);
	while(id1 >= now + here)
	{
		now += here;
		here /= 2;
	}
	int l = (id1 - now) * ((1 << k) / here);
	int r = l + ((1 << k) / here) - 1;
	return {l, r};
}

void update(int now, int l, int r, int l1, int r1)
{
	if(l1 != l || r1 != r)
	{
		int mid = (l + r) / 2;
		if(mid >= r1)
		{
			update(now * 2, l, mid, l1, r1);
		}
		else
		{
			update(now * 2 + 1, mid + 1, r, l1, r1);
		}
	}
	int id1 = get_id(l, r);
	if(s[id1] == '0')
	{
		tree[now] = tree[now * 2];
	}
	else if(s[id1] == '1')
	{
		tree[now] = tree[now * 2 + 1];
	}
	else
	{
		tree[now] = tree[now * 2 + 1] + tree[now * 2];
	}
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
    cin >> k;
    cin >> s;
    tree.resize((1 << (k + 2)) + 2);
    build(1, 0, (1 << k) - 1);
    int q;
    cin >> q;
    for(int _ = 0; _ < q; _++)
    {
    	int p;
    	char c;
    	cin >> p >> c;
    	--p;
    	s[p] = c;
    	auto pair1 = get_otr(p);
    	update(1, 0, (1 << k) - 1, pair1.first, pair1.second);
    	cout << tree[1] << '\n';
    }
}