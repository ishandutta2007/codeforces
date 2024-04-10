/*
A reign, invincible
Sitting right at the top
A domination
Something you just can't stop

Face the opponent
Take em down one by one
Take no prisoners
Game over before it's won

Downright dominate
Downright dominate
Must annihilate
Downright dominate

Feel the rush
The adrenaline kicking in
Resolution
A fight to the death, begin

Breathing power
Gotta unleash the beast
It's time to devour
And you are the feast

Forcing the action, bring on the attack
Everything now in position
Showing no mercy, treasure the moment
Beating you into submission

Resistance is futile, dealing the pain
Over and over again
Fall to your knees, you can beg if you please
Now you are facing the end

Beaten, conquered
Never the end in doubt
Defend the crown
The king has cast you out
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

//const int N = 1200031;

vector<int> v1,v2;

int N = (1<<19);
int n,x,ar[1<<19],s[1<<19];
int v[1<<19];


int base;

string st;

//typedef complex<double> base;

#define pw(x) (1LL<<(x))
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)

	const int maxBase = 19;
	const int maxN = 1 << maxBase;

	struct num
	{
		ldouble x, y;
		num(){}
		num(ldouble xx, ldouble yy): x(xx), y(yy) {}
		num(ldouble alp): x(cos(alp)), y(sin(alp)) {}
	};

	inline num operator + (num a, num b) { return num(a.x + b.x, a.y + b.y); }
	inline num operator - (num a, num b) { return num(a.x - b.x, a.y - b.y); }
	inline num operator * (num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
	inline num conj(num a) { return num(a.x, -a.y); }

	const ldouble PI = acos(-1);

	num root[maxN];
	int rev[maxN];
	bool rootsPrepared = false;

	void prepRoots()
	{
		if (rootsPrepared) return;
		rootsPrepared = true;
		root[1] = num(1, 0);
		for (int k = 1; k < maxBase; ++k)
		{
			num x(2 * PI / pw(k + 1));
			for (int i = pw(k - 1); i < pw(k); ++i)
			{
				root[2 * i] = root[i];
				root[2 * i + 1] = root[i] * x;
			}
		}
	}

	int lastRevN = -1;
	void prepRev()
	{
		if (lastRevN == N) return;
		lastRevN = N;
		forn(i, N) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (base - 1));
	}

	void fft(num *a, num *f)
	{
		forn(i, N) f[i] = a[rev[i]];
		for (int k = 1; k < N; k <<= 1) for (int i = 0; i < N; i += 2 * k) forn(j, k)
		{
			num z = f[i + j + k] * root[j + k];
			f[i + j + k] = f[i + j] - z;
			f[i + j] = f[i + j] + z;
		}
	}

	num a[maxN], b[maxN], f[maxN], g[maxN];
	long long A[maxN], B[maxN], C[maxN];


	void _multMod(int mod)
	{
		forn(i, N)
		{
			int x = A[i] % mod;
			a[i] = num(x & (pw(15) - 1), x >> 15);
		}
		forn(i, N)
		{
			int x = B[i] % mod;
			b[i] = num(x & (pw(15) - 1), x >> 15);
		}
		fft(a, f);
		fft(b, g);

		forn(i, N)
		{
			int j = (N - i) & (N - 1);
			num a1 = (f[i] + conj(f[j])) * num(0.5, 0);
			num a2 = (f[i] - conj(f[j])) * num(0, -0.5);
			num b1 = (g[i] + conj(g[j])) * num(0.5 / N, 0);
			num b2 = (g[i] - conj(g[j])) * num(0, -0.5 / N);
			a[j] = a1 * b1 + a2 * b2 * num(0, 1);
			b[j] = a1 * b2 + a2 * b1;
		}

		fft(a, f);
		fft(b, g);

		forn(i, N)
		{
			long long aa = f[i].x + 0.5;
			long long bb = g[i].x + 0.5;
			long long cc = f[i].y + 0.5;
			C[i] = (aa + bb % mod * pw(15) + cc % mod * pw(30)) % mod;
		}
	}

	void prepAB(int n1, int n2)
	{
		base = 1;
		N = 2;
		while (N < n1 + n2) base++, N <<= 1;

		for (int i = n1; i < N; ++i) A[i] = 0;
		for (int i = n2; i < N; ++i) B[i] = 0;

		prepRoots();
		prepRev();
	}


	void mult(int n1, int n2)
	{
		prepAB(n1, n2);
		forn(i, N) a[i] = num(A[i], B[i]);
		fft(a, f);
		forn(i, N)
		{
			int j = (N - i)  & (N - 1);
			a[i] = (f[j] * f[j] - conj(f[i] * f[i])) * num(0, -0.25 / N);
		}
		fft(a, f);
		forn(i, N) C[i] = (long long)round(f[i].x);
	}

	void multMod(int n1, int n2, int mod)
	{
		prepAB(n1, n2);
		_multMod(mod);
	}

	int D[maxN];

	void multLL(int n1, int n2)
	{
		prepAB(n1, n2);

		int mod1 = 1.5e9;
		int mod2 = mod1 + 1;

		_multMod(mod1);

		forn(i, N) D[i] = C[i];

		_multMod(mod2);

		forn(i, N)
		{
			C[i] = D[i] + (C[i] - D[i] + (long long)mod2) * (long long)mod1 % mod2 * mod1;
		}
	}
	// HOW TO USE ::
	// -- set correct maxBase
	// -- use mult(n1, n2), multMod(n1, n2, mod) and multLL(n1, n2)
	// -- input  : A[], B[]
	// -- output : C[]

	long long ans[1<<19];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>x;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
		if (ar[i]<x)
			ar[i]=1;
		else
			ar[i]=0;
	}

	for (int i=1;i<=n;i++){
		s[i]=s[i-1]+ar[i];
	}

	for (int i=0;i<=n;i++){
		v[s[i]]++;
	}

	for (int i=0;i<=n;i++){
		v1.push_back(v[i]);
	}
	v2=v1;

	reverse(v2.begin(),v2.end());

	for (int i=0;i<v1.size();i++){
		A[i]=v1[i];
		B[i]=v2[i];
	}

	mult((int)v1.size()+5,(int)v2.size()+5);

	for (int i=n+1;i<=n*2;i++){
		ans[i-n]=C[i];
	}

	int L=0;
	for (int i=1;i<=n;i++){
		if (s[i]!=s[i-1])
			L=i;
		ans[0]+=i-L;
	}

	for (int i=0;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

/*	for (int i=0;i<=n*2;i++){
		cout<<C[i]<<" ";
	}
	cout<<endl;
*/

//	cin.get(); cin.get();
	return 0;
}