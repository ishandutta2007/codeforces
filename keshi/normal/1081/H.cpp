//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 200111;
const int base1 = 1231332;
const int mod1 = 1e9+7;
const int base2 = 13211332;
const int mod2 = 1e9+9;
const int abase = 23333333;
int pwb1[maxn], pwb2[maxn];
struct hashing
{
	ll a, b;
	hashing(ll A=0, ll B=0) {a=A; b=B;}
	hashing next(int k)
	{
		return hashing(a*pwb1[k]%mod1, b*pwb2[k]%mod2);
	}
	hashing operator + (const char c)
	{
		return hashing((a+c)%mod1, (b+c)%mod2);
	}
	hashing operator + (const hashing t)
	{
		return hashing((a+t.a)%mod1, (b+t.b)%mod2);
	}
	hashing operator - (const hashing t)
	{
		return hashing((a-t.a+mod1)%mod1, (b-t.b+mod2)%mod2);
	}
	ll get() {return a*mod2+b;}
};
struct PalindromicTree
{
	unordered_map<ll,int> mxlen;
	unordered_map<ll,int> hsmp;
	hashing hs[maxn], hs_r[maxn];
	char s[maxn];
	int n, tot, go[maxn][26], fail[maxn], diff[maxn], slink[maxn], len[maxn];
	int mnp[maxn];
	ll phs[maxn], phs_r[maxn];
	pair<int,int> seg[maxn];
	int append(int n, int p)
	{
		int c = s[n]-'a';
		while (s[n-1-len[p]]!=s[n]) p = fail[p];
		if (go[p][c]) return go[p][c];
		int q = ++tot;
		len[q] = len[p]+2;
		seg[q] = MP(n-len[q]+1, n);
		int f = fail[p];
		while (s[n-1-len[f]]!=s[n]) f = fail[f];
		fail[q] = go[f][c];
		go[p][c] = q;
		diff[q] = len[q] - len[fail[q]];
		slink[q] = diff[q]==diff[fail[q]]? slink[fail[q]]: fail[q];
		return q;
	}
	int st[maxn];
	ll geths2(int l, int r, int l2, int r2)
	{
		return ((hs[r]-hs[l-1].next(r-l+1)).next(r2-l2+1)+hs[r2]-hs[l2-1].next(r2-l2+1)).get();
	}
	ll geths(int l, int r)
	{
		return (hs[r]-hs[l-1].next(r-l+1)).get();
	}
	ll geths_r(int l, int r)
	{
		return (hs_r[l]-hs_r[r+1].next(r-l+1)).get();
	}
	void construct(int _n, char _s[])
	{
		n = _n;
		hs[0] = hashing(0, 0);
		for (int i=1; i<=n; i++)
		{
			s[i] = _s[i];
			hs[i] = hs[i-1].next(1)+s[i];
		}
		hs[n+1] = hashing(0,0);
		for (int i=n; i>=1; i--) hs_r[i] = hs_r[i+1].next(1)+s[i];
		int p = 0;
		fail[0] = 1; len[0] = 0; seg[0] = MP(1, 0);
		fail[1] = 0; len[1] = -1; seg[1] = MP(1, 0);
		tot = 1;
		st[0] = p;
		for (int i=1; i<=n; i++)
		{
			p = append(i, p);
			assert(fail[p]!=1);
			st[i] = p;
		}
		for (int i=2; i<=tot; i++)
		{
			hsmp[geths(seg[i].FF, seg[i].SS)] = 1;
			mnp[i] = len[i]-len[fail[i]];
			phs[i] = geths(seg[i].FF, seg[i].FF+mnp[i]-1);
			phs_r[i] = geths_r(seg[i].FF, seg[i].FF+mnp[i]-1);
			assert(mnp[i]>0);
			if (len[i]>=mnp[i]*2) mxlen[phs[i]] = max(mxlen[phs[i]], len[i]/mnp[i]-1);
		}
	}
	int query_mxpal(int p, int b) //len = b
	{
		if (b>len[p]) return len[p];
		while (true)
		{
			int l = len[slink[p]];
			int d = diff[p];
			if (b>=l)
			{
				return ((b-l)/d)*d+l;
			}
			p = slink[p];
		}
	}
}T1, T2, T1R, T2R;
 
char A[maxn], B[maxn];
int n, m;
ll ANS;
void prework()
{
	T1.construct(n, A);
	T2.construct(m, B);
	ANS = 1ll*(T1.tot-1)*(T2.tot-1);
	reverse(A+1, A+n+1);
	T1R.construct(n, A);
	reverse(A+1, A+n+1);
	reverse(B+1, B+m+1);
	T2R.construct(m, B);
	reverse(B+1, B+m+1);
}
bool is_palindrome(int l, int r)
{
	return T1.query_mxpal(T1.st[r], r-l+1)==r-l+1;
}
void check_palindrome_decomposition(int l, int r)
{
	int p;
	p = T1.query_mxpal(T1.st[r], r-l+1);
	if (l<=r-p&&r-p+1<=r&&is_palindrome(l, r-p))
	{
		ANS -= T2.hsmp[T1.geths2(l, r, l, r-p)];
		return;
	}
	p = T1R.query_mxpal(T1R.st[n-(l)+1], r-l+1);
	if (l<=l+p-1&&l+p<=r&&is_palindrome(l+p, r))
	{
		ANS -= T2.hsmp[T1.geths2(l, r, l, l+p-1)];
		return;
	}
}
unordered_map<ll, int> mp;
void calc(int t)
{
	for (int i=2; i<=T1.tot; i++)
	{
		int p = T1.mnp[i];
		if (T1.len[i]<=p) continue;
		int mxb = T2.mxlen[T1.phs_r[i]];
		ANS -= mxb;
		check_palindrome_decomposition(T1.seg[i].SS-p+1, T1.seg[i].SS);
		if (t==0) mp[T1.phs[i]]++;
		else
		{
			ANS += mp[T1.phs_r[i]];
		}
	}
}
int main()
{
	pwb1[0] = 1;
	for (int i=1; i<maxn; i++) pwb1[i] = 1ll*pwb1[i-1]*base1%mod1;
	pwb2[0] = 1;
	for (int i=1; i<maxn; i++) pwb2[i] = 1ll*pwb2[i-1]*base2%mod2;
	scanf("%s", A+1);
	n = strlen(A+1);
	scanf("%s", B+1);
	m = strlen(B+1);
	prework();
	calc(0);
	swap(A, B);
	swap(n, m);
	swap(T1, T2);
	swap(T1R, T2R);
	calc(1);
	cout<<ANS<<endl;
	return 0;
}