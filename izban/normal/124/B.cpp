#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;

#define sqr(x) ((x)*(x))

int gcd(int a,int b) {
	if (a*b==0) return a+b;
	return gcd(b%a,a);
}

int n,k;
int b[9],vis[9];
string a[9],c[9];
int ans=1e9;

void rec(int x) {
	if (x==k) {
		int mi=1e9,ma=0;
		for (int i=1; i<=n; i++) {
			c[i]="";
			c[i]+='0';
			for (int j=1; j<=k; j++)
				c[i]+=a[i][b[j]-1];
			int p=0;
			string s=c[i];
			sscanf(s.c_str(), "%d", &p);
			mi=min(mi,p);
			ma=max(ma,p);
		}
		ans=min(ans,ma-mi);
	}
	else {
		for (int i=1; i<=k; i++) {
			if (!vis[i]) {
				b[x+1]=i;
				vis[i]=true;
				rec(x+1);
				b[x+1]=0;
				vis[i]=false;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> k;
	for (int i=1; i<=n; i++) cin >> a[i];
	rec(0);
	cout << ans;
	return 0;
}