#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cassert>
using namespace std;
typedef long long li;
typedef pair<int, int> pi;
#define FILENAME "arrays"

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
void solve();
int main(){


#ifdef room210
	freopen("in.txt","r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<FILENAME<<endl;
#else
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif
	int t = 1;
	//cin>>t;
	while(t--)
		solve();
	return 0;
}

#define int li

int n, k;
int d[2000], s[2000];

int rec (int l, int r, int &rest){
	if (l == r)
		return 0;
	if (l + 1 == r){
		rest += s[l];
		if (rest >= d[l]){
			rest -= d[l];
			return d[l];
		}
		int need = (d[l] - rest - 1)/s[l] + 1;
		rest += need * s[l];
		rest -= d[l];
		return need * k + d[l];
	}
	int mx = l;
	for (int i = l; i < r; ++i){
		if (s[i] > s[mx])
			mx = i;
	}
	int ans = rec(l, mx, rest);
	int mn = rest;
	for (int i = mx; i < r; ++i){
		rest += s[i];
		rest -= d[i];
		ans += d[i];
		mn = min(mn, rest);
	}
	mn = -mn;
	if (mn == 0){
		return ans;
	}
	int need = (mn - 1) / s[mx] + 1;
	ans += need * k;
	rest += s[mx] * need;
	return ans;
}

void solve(){
	cin>>n>>k;
	int sum = 0;
	for (int i = 0; i < n; ++i)
		cin>>d[i];
	for (int i = 0; i < n; ++i)
		cin>>s[i];
	int rest = 0;
	cout<<rec(0, n, rest);
}