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

const int maxn=110, mod=1000000007;

int n;
char c;
int a[maxn],b[maxn],d[maxn],e[maxn];
bool f1=true, f2=true;

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) 
		cin >> c, a[i]=c-'0';
	sort(a,a+n);
	for (int i=0; i<n; i++)
		cin >> c, b[i]=c-'0';
	sort(b,b+n);
	for (int i=0; i<n; i++) 
		d[i]=a[i]-b[i], e[i]=b[i]-a[i];
	for (int i=0; i<n; i++) 
		f1=f1&&(d[i]>0), f2=f2&&(e[i]>0);
	if (f1||f2) cout << "YES";
	else cout << "NO";
	return 0;
}