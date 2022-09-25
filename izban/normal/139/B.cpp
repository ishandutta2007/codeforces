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

int n,m,k,p;
string s;

long long a[2000],b[2000],c[2000],d[2000],e[2000],f[2000];
long long trans=0;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i] >> b[i] >> c[i];
	cin >> m;
	for (int i=0; i<m; i++) cin >> d[i] >> e[i] >> f[i];

	for (int i=0; i<n; i++) {
		long long ans=(1e9);
		long long s=(2*a[i]+2*b[i]);
		for (int j=0; j<m; j++) {
			long long colpol=d[j]/c[i];
			if (colpol==0) continue;
			ans=min(ans,(s/(e[j]*colpol)+(s%(e[j]*colpol)>0))*f[j]);
		}
		trans+=ans;
	}
	cout << trans;
	return 0;
}