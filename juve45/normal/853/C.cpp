#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 200010
#define MMAX 1
#define y1 y11
using namespace std;

int n, x, k, x1, y1, x2, y2, r[10];

struct nod{
	nod * l = 0,  * r = 0;
	int val;
} * rev[NMAX];

nod * updPers(nod * rad, int val, int pos, int low, int high)
{
	nod * ret = new nod;
	if(!rad) rad = new nod;
	
	if(low == high)
	{
		//dbg(low);
		//dbg(high);
		//dbg(val);
		ret->val = val;
		return ret;
	}

	int mid = (low + high)/2;
	//dbg(pos);
	//dbg(mid);
	if(pos <= mid)
	{
		//if(!rad->l) rad->l = new nod;
		ret->l = updPers(rad->l, val, pos, low, mid);
		ret->r = rad->r;
	}
	else
	{
		ret->r = updPers(rad->r, val, pos, mid+1, high);
		ret->l = rad->l;
	}
	ret->val = 0;
	if(ret->l)
		ret->val += ret->l->val;
	if(ret->r)
		ret->val += ret->r->val;
	//dbg(low);
	//dbg(high);
	//dbg(ret->val);
	return ret;
}

void upd(nod * rad, int val, int pos, int low, int high)
{
	if(low == high)
	{
		rad->val = val;
		return;
	}
	int mid = (low + high)/2;
	if(pos <= mid)
	{
		if(!rad->l) rad->l = new nod;
		upd(rad->l, val, pos, low, mid);
	}
	else 
	{
		if(!rad->r) rad->r = new nod;
		upd(rad->r, val, pos, mid+1, high);
	}
	if(rad->l)
		rad->val = rad->l->val;
	if(rad->r)
		rad->val += rad->r->val; 
}

int que(nod * rad, int x, int y, int low, int high)
{
	if(rad == NULL) return 0;
	if(low >= x && high <= y)
		return rad->val;

	int mid = (low + high)/2;
	int ans = 0;
	if(x <= mid) ans += que(rad->l, x, y, low, mid);
	if(y >= mid) ans += que(rad->r, x, y, mid+1, high);
	return ans;
}

int get(int x1, int y1, int x2, int y2)
{
	if(x1 > x2) return 0;
	if(y1 > y2) return 0;
	return que(rev[x2], y1, y2, 1, NMAX) - que(rev[x1-1], y1, y2, 1, NMAX);
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int revCount = 0;
	rev[0] = new nod;

	//cout << que(rev[0], 57, 57, 1, 100);

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &x);
		rev[i] = updPers(rev[i-1], 1, x, 1, NMAX);
	}
/*
	cout << que(rev[2], 2, 2, 1, NMAX) << '\n';

	cout << get(2, 2, 3, 3) << '\n';
	cout << get(1, 1, 3, 3) << '\n';
	cout << get(1, 1, 3, 2) << '\n';
*/
//cout << que(rev[4], 1, 4, 1, NMAX) << '\n';
//cout << que(rev[3], 1, 4, 1, NMAX) << '\n';
	for(int i = 1; i <= k; i++)
	{
		//cin >> x1 >> y1 >> x2 >> y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		long long ans = 0LL;
		r[2] = get(x1, 1, x2, y1 - 1);
		r[3] = get(x2 + 1, 1, n, y1 - 1);
		r[4] = get(x2 + 1, y1, n, y2);
		r[5] = get(x2 + 1, y2 + 1, n, n);
		r[6] = get(x1, y2 + 1, x2, n);
		r[7] = get(1, y2 + 1, x1 - 1, n);
		r[8] = get(1, y1, x1 - 1, y2);
		r[1] = get(1, 1, x1 - 1, y1 - 1);
		int x = n - r[1] - r[2] - r[3] - r[4] - r[5] - r[6] - r[7] - r[8];

		ans += 1LL * r[1] * (1LL * x + r[4] + r[5] + r[6]);
		ans += 1LL * r[2] * (1LL * x + r[4] + r[5] + r[6] + r[7] + r[8]);
		ans += 1LL * r[3] * (1LL * x + r[6] + r[7] + r[8]);
		ans += 1LL * r[4] * (1LL * x + r[1] + r[2] + r[6] + r[7] + r[8]);
		ans += 1LL * r[5] * (1LL * x + r[1] + r[2] + r[8]);
		ans += 1LL * r[6] * (1LL * x + r[1] + r[2] + r[3] + r[4] + r[8]);
		ans += 1LL * r[7] * (1LL * x + r[4] + r[3] + r[2]);
		ans += 1LL * r[8] * (1LL * x + r[4] + r[5] + r[6] + r[2] + r[3]);
		ans += 1LL * x * (n-x);
/*
		ans += get(x1, 1, x2, y1 - 1) * get(1, y1, n, n);
		ans += get(x2 + 1, 1, n, y1 - 1) * get(1, y1, x2, n);
		ans += get(x2 + 1, y1, n, y2) * get(1, 1, x2, n);
		ans += get(x2 + 1, y2 + 1, n, n) * get(1, 1, x2, y2);
		ans += get(x1, y2 + 1, x2, n) * get(1, 1, n, y2);
		ans += get(1, y2 + 1, x1 - 1, n) * get(x1, 1, n, y2);
		ans += get(1, y1, x1 - 1, y2) * get(x1, 1, n, n);
		ans += get(1, 1, x1 - 1, y1 - 1) * get(x1, y1, n, n);
		
		1 2 3
		8		4
		7 6	5

		int x = get(x1, y1, x2, y2);
		
		ans += x * (n-x);
*/		
		ans /= 2LL;
		//dbg(x);
		ans += 1LL * x * (x-1)/2;
		//
		//cout << ans << '\n';
		printf("%lld\n", ans);
	}

}