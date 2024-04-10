#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 100500;
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define all(x) (x).begin(), (x).end()
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;
typedef double ld;
const ld eps = 1e-10;
#define le(x, y) ((x)<(y)+eps)
#define eq(x, y) (abs((x)-(y))<eps)
#define lt(x, y) ((x)<(y)-eps)
const int mod = 1e9+7;
int madd (int x, int y) {return ((x+y)%mod+mod)%mod;}
int mmul (int x, int y) {return (((i64)x*y%mod)+mod)%mod;}
int mpow(int x, int k)
{
	if (k == 0) return 1;
	int t = mpow(x, k/2);
	t = mmul(t, t);
	if (k%2) t = mmul(t, x);
	return t;
}

int n, l, v1, v2;
ld T;
int a[maxn];
ld res[maxn];

vector<ld> in, out;

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> n >> l >> v1 >> v2;
	forn(i, n) cin >> a[i];
	
	T = (ld)v2*l / (ld)(v1+v2);
	//cout << "T = " << T << endl;
	
	forn(I, 2) forn(i, n)
	{
		out.pb(a[i] + 2.*l*I);
		in.pb(a[i] + 2.*l*I - T);
	}
	forn(i, in.size())
		if (le(in[i],0))
			in[i] = 1e40;
	out.pb(2.*l);
	sort(all(in));
	sort(all(out));
	in.erase(lower_bound(in.begin(), in.end(), 1e40), in.end());
	
	ld t1 = 0, t2 = 0; // t1 + t = t2
	ld pos1 = 0, pos2 = 0; // positions in in/out arrays
	int cnt = 0;
	
	// advance open pointer
	while (le(out[pos2], T))
		++cnt, pos2++;
	pos2 = 0;
	
	//cout << "cnt = " << cnt << endl;
		
	//forn(i, out.size()) cout << out[i] << " ";cout<<endl;
	//forn(i, in.size()) cout << in[i] << " ";cout<<endl;
		
	while (lt(t1, 2.*l) && (pos1 < (int)out.size() || pos2 < (int)in.size()))
	{
		//cout << "pos1 = " << pos1 << ", pos2 = " << pos2 << endl;
		//cout << "t1 = " << t1 << endl;
		if (pos1 < (int)out.size() && out[pos1] < in[pos2])
		{
			ld adv = out[pos1] - t1;
			//cout << "adv = " << adv << ", cnt = " << cnt << endl;
			res[cnt] += adv;
			--cnt;
			t1 = out[pos1++];
			//cout << "decrease cnt before " << t1 << endl;
			//cout << "cnt = " << cnt << endl;
		}
		else
		{
			ld adv = in[pos2] - t1;
			res[cnt] += adv;
			//cout << "adv = " << adv << ", cnt = " << cnt << endl;
			++cnt;
			t1 = in[pos2++];
			//cout << "increase cnt before " << t1 << endl;
			//cout << "cnt = " << cnt << endl;
		}
		//cout << endl;
	}
	
	cout.precision(20);
	forn(i, n+1)
		cout << fixed << res[i] / (2.*l) << "\n";
		
	return 0;
}