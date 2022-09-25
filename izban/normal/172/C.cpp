#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int maxn=131072;


int n,m;
int ans[maxn];
pair<int,int> a[maxn],b[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	for (int i=0; i<n; i++) 
		cin >> a[i].first >> a[i].second;
	int k=0;
	int curt=1;
	while (k<n) {
		int cnt=0;
		for (int i=0; i<m && i+k<n; i++) {
			b[cnt++]=make_pair(a[i+k].second,i+k);
			curt=max(curt,a[i+k].first);
		}
		k+=cnt;
		sort(b,b+cnt);
		int curx=0;
		for (int i=0; i<cnt; ) {
			curt+=b[i].first-curx;
			curx=b[i].first;
			int l=i,r=i;
			while (i<cnt && b[i].first==curx) {
				ans[b[i].second]=curt;
				i++;
			}
			curt+=1+(i-l)/2;
		}
		curt+=curx;
	}
	for (int i=0; i<n; i++)
		cout << ans[i] << ' ';
	return 0;
}