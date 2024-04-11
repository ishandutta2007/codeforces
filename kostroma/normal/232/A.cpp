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
#include <ctime>
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
#define NAME "change me please\n"

//int timer=0;

clock_t start;

int main() {
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
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
	//cin>>t;
#ifdef _DEBUG
	start = clock();
#endif
	while (t--)
		solve();
		
#ifdef _DEBUG
	printf ("\n\ntime = %.10lf\n", (double)(clock()-start)/CLOCKS_PER_SEC);
#endif
	return 0;
}

#define int li

int k;

int ans[111][111];

void solve(){
	//freopen("out.txt", "w", stdout);
	cin>>k;
	int n = 3;
	for (; n <= 100; ++n){
		if (n * (n - 1) * (n - 2) / 6 > k){
			break;
		}
	}
	--n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i != j){
				ans[i][j] = ans[j][i] = 1;
			}
	k -= n * (n - 1) * (n - 2) / 6;
	//cout<<n<<' '<<k<<endl;
	for (int i = 0; i < 100 - n; ++i){
		if (k == 0)
			break;
		int u = 0;
		for (int j = 0; j < n; ++j){
			if (j * (j + 1) / 2 > k){
				u = j;
				break;
			}
			else
				ans[i + n][j] = ans[j][i + n] = 1;
		}
		k -= u * (u - 1) / 2;
		//cout<<k<<endl;
	}
	assert(k == 0);
	cout<<100<<endl;
	for (int i = 0; i < 100; ++i){
		for (int j = 0; j < 100; ++j)
			cout<<ans[i][j];
		cout<<endl;
	}
}