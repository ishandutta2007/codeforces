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

const int maxn=1000100;
const int xr=(1<<22)-1;

int n,a[maxn],d[1<<22];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin >> n; 
	for (int i=0; i<n; i++) 
		cin >> a[i], d[a[i]]=a[i];
	for (int i=0; i<1<<22; i++) 
		if (d[i])
			for (int j=0; j<22; j++)
				if (!(i&(1<<j)))
					d[i+(1<<j)]=d[i];
	for (int i=0; i<n; i++) {
		int x=a[i]^xr;
		if (d[x]) cout << d[x] << ' ';
		else cout << -1 << ' ';
	}


	return 0;
}