#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <cstdlib>
#include <set>
#include <sstream>
#include <queue>
#include <functional>



#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

#pragma comment(linker,"/STACK:64000000")

const int maxn=100100, mod=1000000007;

int n,  a[maxn];
ll k;

map<int,ll> m;

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> n >> k;
	for (int i=0; i<n; i++) 
		cin >> a[i], m[a[i]]++;
	sort(a,a+n);
	a[n]=a[n-1]+1;
	int a1=0,a2=0;
	ll k1=k;
	while (k1>n) 
		a1++, k1-=n;
	for (int i=0; a[i]!=a[a1]; i++) k-=n;
	for (int i=0; i<n; i++) 
		if (a[i]!=a[i+1]) {
			ll d=(a[i]==a[a1])? m[a[i]]*m[a[a1]] : m[a[i]]*m[a[a1]];
			if (k>d) k-=d;
			else {
				a2=i; 
				break;
			}
		}
	cout << a[a1] << ' ' << a[a2] << endl;
	return 0;
}