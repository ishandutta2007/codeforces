#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

ll A, B;

struct Node
{
	ll cost = A, cnt = 0;

	Node *left = nullptr, *right = nullptr;
};

typedef Node* pNode;

pNode root = nullptr;

ll getcnt(pNode v)
{
	return (v != nullptr ? v->cnt : 0);
}

ll getcost(pNode v)
{
	return (v != nullptr ? v->cost : A);
}

void segtree_inc(pNode& root, ll tl, ll tr, ll pos)
{
	if(root == nullptr)
		root = new Node;

	if(tl == tr)
	{
		++(root->cnt);
		root->cost = B * (root->cnt);
		return;
	}

	ll tm = (tl + tr) / 2;

	if(pos <= tm)
		segtree_inc(root->left, tl, tm, pos);
	else
		segtree_inc(root->right, tm + 1, tr, pos);

	root->cnt = getcnt(root->left) + getcnt(root->right);
	root->cost = min(B * (tr - tl + 1) * root->cnt, getcost(root->left) + getcost(root->right));
}

void solve()
{
	ll n;
	int k;

	cin >> n >> k >> A >> B;

	for(int i = 0; i < k; ++i)
	{
		ll pos;
		cin >> pos;

		segtree_inc(root, 1, (1LL << n), pos);
	}
	
	cout << getcost(root) << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}