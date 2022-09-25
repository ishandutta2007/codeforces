#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int maxn=4100, inf=1000000007;

int n,k,ans;
int b[100000];
pair <int,int> t[maxn];
int d[maxn][maxn];
string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> k;
	t[0]=make_pair(1,0);
	for (int i=1; i<=n; i++) {
		cin >> t[i].first >> t[i].second;
		for (int j=t[i-1].first; j<t[i].first; j++) b[j]=i-1;
		t[n+i]=make_pair(86401,86400);
	} for (int j=t[n].first; j<t[n+1].first; j++) b[j]=n;
	t[2*n+1]=make_pair(86401,86400);

	for (int i=0; i<maxn; i++) for (int j=0; j<maxn; j++) d[i][j]=inf;
	d[0][0]=1;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=k; j++) {
			d[i+1][j+1]=min(d[i+1][j+1],d[i][j]);
			d[i+1][j]=min(d[i+1][j],max(t[i+1].first,d[i][j])+t[i+1].second);
		}
	}
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=k; j++) {
			ans=max(ans,t[i+(k-j)+1].first-d[i][j]);
		}
	}

	cout << ans;
	return 0;
}