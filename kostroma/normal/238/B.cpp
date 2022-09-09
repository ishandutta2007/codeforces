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

//#define int li

pair <int, int> a[100500];
int n, h;
int res[100500];

void solve(){
	cin>>n>>h;
	for (int i = 0; i < n; ++i){
		cin>>a[i].first;
		a[i].second = i;
	}
	sort(a, a + n);
	if (n <= 2){
		cout<<"0\n1 2\n";
		return;
	}
	int ans = max(a[n - 1].first + a[n - 2].first, a[n - 1].first + a[0].first + h) - min(a[1].first + a[2].first, a[0].first + a[1].first + h);
	assert(ans >= 0);
	int ans1 = a[n - 1].first + a[n - 2].first - a[0].first - a[1].first;
	assert(ans1 >= 0);
	if (ans1 < ans){
		cout<<ans1<<endl;
		for (int i = 0; i < n; ++i)
			printf("1 ");
		return;
	}

	cout<<ans<<endl;

	for (int i = 0; i < n; ++i)
		if (i == a[0].second)
			printf("1 ");
		else
			printf("2 ");

}