#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <set>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
const int maxn = 100500;
typedef long long ll;
typedef pair<int, int> pii;
#define se second
#define fi first
#define mp make_pair

int f[maxn], best[maxn];
int n;
int k;
int get(int);

int main()
{
	forn(i, maxn) f[i] = -1;
	int k;
	cin >> k;
	get(k);
	//get(15);
	//forn(i, 110) {if(i)get(i);cout << i << " " << f[i] << " " << best[i] << endl;}cout << endl;return 0;
	if (f[k]) cout << best[k];
	else cout << -1;
	
};
int get (int i)
{
	//cout << "get " << i << endl;
	//cin >> k;
	if (f[i] == -1)
	{
		set<int> cand;
		for (int k = 2; k*k < 2*i+10; k++)
		{
			if ((i*2) % k) continue;
			if ( ((2*i)/k - k + 1) % 2) continue;
			int a = ((2*i)/k - k + 1) / 2;
			if (a <= 0) continue;
			//if (i == 10) cout << "k = " << k << ", a = " << a << endl;
			int cur = 0;
			forn(j, k)
				cur ^= get(a+j);
			cand.insert(cur);
			if (!cur && !best[i]) best[i] = k;
			//if (i == 10) cout << "cur = " << cur << endl;
		}
		//if (i == 10){for (set<int> :: iterator it = cand.begin(); it != cand.end(); it++) cout << *it << " ";cout<<endl;}
		for (int j = 0;; j++)
			if (!cand.count(j))
			{
				f[i] = j;
				//if (i==10) cout << "now fi = " << f[i] << endl;
				break;
			}
	}
	return f[i];
};