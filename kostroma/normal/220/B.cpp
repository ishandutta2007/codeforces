//#pragma comment(linker, "/STACK:206777216")

#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <complex>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()

typedef long long li;
typedef vector<li> vi;
typedef pair<int, int> pi;
typedef long double ld;
//#define NAME "lca"

//int timer=0;

int main() {
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	//cout<<NAME<<endl;
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);
	int t = 1;
#ifndef _DEBUG
	//cin>>t;
#endif
	//cin>>t;
#ifdef _DEBUG
	clock_t start = clock();
#endif
	while (t--)
			solve();
		
#ifdef _DEBUG
	printf ("\n\ntime = %.10lf\n", (double)(clock()-start)/CLOCKS_PER_SEC);
#endif
	return 0;
}

const int MAXN=100500;
int n, m;
vector <pair <int, int> > q[MAXN];
int a[MAXN];

vector <int> poses[MAXN];

int uk[MAXN];
int res[MAXN];

const int shift=1<<17;
int tree[2*shift + 5];

int sum (int l, int r){
	if (l>r)
		return 0;
	if (l%2)
		return tree[l] + sum(l+1, r);
	if (r%2==0)
		return tree[r] + sum(l, r-1);
	return sum(l/2, r/2);
}

void modify (int l, int val){
	l+=shift;
	tree[l]+=val;
	for (int i=l/2; i>=0; --i)
		tree[i]=tree[2*i]+tree[2*i+1];
}

void solve(){
	cin>>n>>m;
	for (int i=0; i<n; ++i)
		scanf ("%d", &a[i]);
	for (int i=0; i<m; ++i){
		int l, r;
		scanf ("%d%d", &l, &r);
		--l; --r;
		q[l].push_back(mp(r,i));
	}
	for (int i=0; i<n; ++i)
		if (a[i]<=100000)
			poses[a[i]].push_back(i);
	for (int val=1; val<=100000; ++val){
		uk[val]=0;
		if (val - 1 < poses[val].size())
			modify(poses[val][val-1], 1);
		if (poses[val].size() > val)
			modify(poses[val][val], -1);
	}
	for (int l=0; l<n; ++l){
		for (int i=0; i<q[l].size(); ++i){
			int r=q[l][i].first;
			res[q[l][i].second] = sum(l+shift, r+shift);
		}
		int val=a[l];
		if (val > 100000)
			continue;
		if (uk[val] + val - 1 < poses[val].size())
			modify ( poses[val][uk[val] + val-1], -1 );
		++uk[val];
		if (uk[val] + val - 1 < poses[val].size())
			modify(poses[val][uk[val] + val-1], 2);
		if (uk[val] + val < poses[val].size())
			modify(poses[val][uk[val] + val], -1);
	}
	for (int i=0; i<m; ++i)
		cout<<res[i]<<"\n";
	
}