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

int n,m,k,p,ans;
string s;
int a,x,y;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> a >> x >> y;

	if (y%a==0) cout << -1; else {
		int k=y/a; k++;
		if (k==1) {
			if (abs(x)<a/2+a%2) cout << 1; else cout << -1;
			return 0;
		}
		if (k%2==1) {
			if (x!=0 && abs(x)<a) {
				int ans=k;
				ans+=k/2-1;
				cout << ans+(x>0);
			} else cout << -1;
		}
		if (k%2==0) {
			if (abs(x)<a/2+a%2) {
				int ans=k;
				ans+=k/2-1;
				cout << ans;
			} else cout << -1;
		}
	}

	return 0;
}