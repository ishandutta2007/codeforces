#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d", &(x))
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, iknt>
#define F first
#define S second

const int maxn = 2e5 + 10;
const int N = 5e6 + 10;

int root[maxn];

int lft[N],rgt[N],val[N], cnt = 0;
void push(int s, int e, int x, int pos1, int pos2)
{
    val[pos1] = val[pos2]+1;
    if(s==e)
        return;
    int mid = (s+e)/2;
    if(x<= mid)
    {
        rgt[pos1] = rgt[pos2];
        lft[pos1] = ++cnt;
        pos2 = lft[pos2];
        pos1 = cnt;
        push(s,mid,x,pos1,pos2);
    }
    else
    {
        lft[pos1] = lft[pos2];
        rgt[pos1] = ++cnt;
        pos2 = rgt[pos2];
        pos1 = cnt;
        push(mid+1,e,x,pos1,pos2);
    }
}

int n;
inline int get(int s, int e, int pos, int l, int r){
	if(l > r) return 0;
	if(!pos) return 0;
	if(l > e ||s > r) return 0;
	if(s >= l && e <= r) return val[pos];
	int mid = (s + e) / 2;
	return get(s, mid, lft[pos], l, r) + get(mid + 1, e, rgt[pos], l, r);
}

inline int get(int i, int j, int l, int r){
	if(i > j) return 0;
	return get(1, n, root[j], l, r) - ((i <= 0) ? 0 : get(1, n, root[i - 1], l, r));
}

inline ll C(int k){
	return (k * 1ll * (k - 1)) / 2;
}
inline ll inside(int l, int r, int d, int u){
	return C(get(l, r, d, u));
}

inline ll answer(int l, int r, int d, int u){
	ll ret = C(n);
	ret -= inside(1, n, 1, d - 1);
	ret -= inside(1, l - 1, 1, n);
	ret -= inside(r + 1, n, 1, n);
	ret -= inside(1, n, u + 1, n);
	ret += inside(1, l - 1, 1, d - 1);
	ret += inside(r + 1, n, 1, d - 1);
	ret += inside(1, l - 1, u + 1, n);
	ret += inside(r + 1, n, u + 1, n);
	return ret;
}
int row[maxn];
int main(){
	int q, l, d, r, u;
	sd(n); sd(q);
	for(int i = 1; i <= n; i++){
		sd(row[i]);
		root[i] = ++cnt;
		push(1, n, row[i], root[i], root[i - 1]);
	}
	for(int i = 1; i <= q; i++){
		sd(l); sd(d); sd(r); sd(u);
		printf("%lld\n", answer(l, r, d, u));
	}
}