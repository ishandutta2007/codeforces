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

const int maxn=21000000;

int m,n;
int a[maxn], mn[maxn];
ll sum;
vector<int> v;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> m >> n;
	for (int i=1; i*i<=m+n-1; i++) 
		v.push_back(i*i);
	reverse(v.begin(),v.end());
	for (int i=0; i<=m+n-1; i++)
		a[i]=1000000007, mn[i]=0;

	for (int i=0; i<v.size(); i++) {
		for (int j=1; v[i]*j<=m+n-1; j++)
			a[v[i]*j]=min(a[v[i]*j],j);
	}

	for (int i=m; i<m+n; i++)
		sum+=a[i];
	cout << sum;
	return 0;
}