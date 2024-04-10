#include <iostream>
#include <cmath>
using namespace std;

#define int long long

struct Node
{
	int L, R;
	int result;
	int update;
	Node *ls, *rs;
	Node()
	{
		L = 0, R = 0, result = 0, update = 0;
		ls = nullptr;
		rs = nullptr;
	}
};

int n, m, k;
int hh[300000];

struct SparceTable1
{
	int a[300000];
	int ans[300000][20];
	int ReqSegment(int l, int r)
	{
	    r--;
	    int h = hh[r - l];
	    return min(ans[r - (1 << h) + 1][h], ans[l][h]);
	}
	void build()
	{
	    for (int i = 0; i < 2 * n; i++)
	    {
	        ans[i][0] = a[i];
	    }
	    for (int j = 1; j < 20; j++)
	    {
	        for (int i = 0; i + (1 << j) <= 2 * n; i++)
	        {
	            ans[i][j] = ReqSegment(i, i + (1 << j));
	        }
	    }
	}
};

SparceTable1 S;

struct SegmentTree2
{
	int sz;
	Node *root;
	int get(Node *nd)
	{
	    //cout << "get " << nd->L << " " << nd->R << endl;
	    if (nd->ls == nullptr)
	    {
	        //cout << "Inf" << endl;
	        return 2999999999;
	    }
	    else
	    {
	        //cout << nd->ls->L << " " << nd->ls->R << " " << nd->ls->result << " " << nd->rs->result << endl;
	        return min(nd->ls->result, nd->rs->result);
	    }
	}
	void Modify(Node *nd)
	{
		int L = nd->L;
		int R = nd->R;
		int M = (L + R) / 2;
		if (nd->ls == nullptr)
		{
			Node *left = new Node();
			(left)->L = L;
			(left)->R = M;
			if (M % n > L % n)
			    (left)->result = S.ReqSegment(L % n, M % n);
			else
			    (left)->result = S.ReqSegment(L % n, M % n + n);
			if (M == L)
			    (left)->result = 2999999999;
			nd->ls = left;
		}
		if (nd->rs == nullptr)
		{
			Node *right = new Node();
			(right)->L = M;
			(right)->R = R;
			if (R % n > M % n)
			    (right)->result = S.ReqSegment(M % n, R % n);
			else
			    (right)->result = S.ReqSegment(M % n, R % n + n);
			if (M == R)
			    (right)->result = 2999999999;
			nd->rs = right;
		}
		if (nd->update != 0)
		{
			nd->result = nd->update;
			nd->ls->update = nd->update;
			nd->ls->result = nd->ls->update;
			nd->rs->update = nd->update;
			nd->rs->result = nd->rs->update;
			nd->update = 0;
		}
		nd->result = get(nd);
		//cout << "Mf : " << L << " " << R << " " << nd->result << endl;
	}
	void Update(int x, int l, int r, Node *nd)
	{
		int L = nd->L;
		int R = nd->R;
		if (l <= L && R <= r)
		{
			Modify(nd);
			nd->update = x;
			nd->result = x;
			return;
		}
		if (R <= l || r <= L)
		{
			return;
		}
		Modify(nd);
		Update(x, l, r, nd->ls);
		Update(x, l, r, nd->rs);
		nd->result = get(nd);
	}
	int ReqSegment(int l, int r, Node *nd)
	{
	    int L = nd->L;
	    int R = nd->R;
  	    if (l <= L && R <= r)
	    {
  	        Modify(nd);
  	        //cout << "here " << L << " " << R << " " << nd->result << endl;
  	        return nd->result;
  	    }
        if (R <= l || r <= L)
        {
      	    return 2999999999;
        }
        Modify(nd);
        return min(ReqSegment(l, r, nd->ls), ReqSegment(l, r, nd->rs));
    }
};

SegmentTree2 S_big;

signed main()
{
    hh[1] = 0;
    hh[2] = 1;
    for (int i = 3; i <= 200000; i++)
    {
        hh[i] = hh[i / 2] + 1;
    }
	cin >> n >> k;
	S_big.sz = n * k;
	Node *Rt2 = new Node();
	Rt2->L = 0;
	Rt2->R = n * k;
	S_big.root = Rt2;
	for (int i = 0; i < n; i++)
	{
	    int t;
	    scanf("%lld", &t);
	    S.a[i] = t;
	    S.a[i + n] = t;
	}
	S.build();
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int l, r, x;
			scanf("%lld %lld %lld", &l, &r, &x);
			l--;
			S_big.Update(x, l, r, S_big.root);
		}
		if (t == 2)
		{
			int l, r;
			scanf("%lld %lld", &l, &r);
			l--;
			//cout << S.ReqSegment(l, r, S.root) << endl;
			printf("%lld\n", S_big.ReqSegment(l, r, S_big.root));
		}
		//cout << endl;
	}
}