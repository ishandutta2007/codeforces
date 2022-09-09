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
int n;
int a[MAXN];
int b[MAXN];


void solve(){
	cin>>n;
	for (int i=0; i<n; ++i)
		cin>>a[i];
	for (int i=0; i<n; ++i)
		b[i]=a[i];
	sort (b, b+n);
	int cnt=0;
	for (int i=0; i<n; ++i)
		if (a[i]!=b[i])
			++cnt;
	if (cnt<=2)
		printf ("YES");
	else
		printf ("NO");

}