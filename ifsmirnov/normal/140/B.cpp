#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 310;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double ld;
const int inf = 1e9+100500;
typedef long long i64;
const ld eps = 1e-9;

int n;
int pr[maxn][maxn];
int mpr[maxn];
int pos[maxn];
int ans[maxn], best[maxn];

class cmp
{
	public: bool operator() (int i, int j) {return pos[i] < pos[j];}
};

void scan()
{
	cin >> n;
	forn(i, n)
	{
		forn(j, n) cin >> pr[i][j];
		forn(j, n) pr[i][j]--;
	}
	forn(i, n) cin >> mpr[i];
	forn(i, n) mpr[i]--;
	forn(i, n) pos[mpr[i]] = i;
}
void solve()
{
	set<int, cmp> cur;
	forn(i, n) best[i] = maxn;
	forn(I, n)
	{
		//add i-th postcard
		cur.insert(I);
		
		int fave = *cur.begin();
		int vice = -1;
		if ((int)cur.size() > 1)
		{
			cur.erase(fave);
			vice = *cur.begin();
			cur.insert(fave);
		}
		//cout << fave+1 << " " << vice+1 << endl;
		
		
		forn(j, n) 
		{
			int curcard = (j == fave ? vice : fave);
			if (curcard == -1)
				continue;
			int t = 0; //position of i in their priority list
			forn(k, n) if (pr[j][k] == curcard)
			{
				t = k;
				break;
			}
			//cout << "Friend #" << j+1 << " card = " << curcard+1 << " pos = " << t << " ";
			if (t < best[j])
			{
				//cout << "relax";
				best[j] = t, ans[j] = I;
			}
			//cout << endl;
		}

	}
	forn(i, n) cout << ans[i] + 1 << " ";
}

int main()
{
	ios :: sync_with_stdio(false);
	
	//freopen("input.txt", "r", stdin);
	
	scan();
	solve();
}