#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define N 1111
typedef long long ll;
ll f[N][N];
struct cell {
	int x,y;
	int p1,p2;
} from[N][N];
vector<int> lst[N+N];
ll a[N];
int n;

int main() {
	//freopen("in","r",stdin);
	
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	
	if (n == 1) {
		cout << a[1] << endl;
		cout << 1 << endl;
		return 0;
	}
	if (n == 2) {
		cout << max(a[1],a[2]) << endl;
		cout << "1 2" << endl;
		return 0;
	}
	
	memset(f,63,sizeof(f));
	
	f[1][2] = 0;
	for (int j=2;j<=n+1;j++)
		for (int i=1;i<j;i++) {
			//cout << i << " " << j << endl;
			//cout << f[i][j] << endl;
			//cout << "------------" << endl;
			
			int p[3] = {i,j,j+1};
			
			for (int p1=0;p1<3;p1++)
				for (int p2=p1+1;p2<3;p2++) {
					ll res = f[i][j] + max(a[ p[p1] ],a[ p[p2] ]);
					int p3 = 3 - p1 - p2;
					
					cell fr;
					fr.x = i; fr.y = j;
					fr.p1 = p[p1]; fr.p2 = p[p2];
					if (f[p[p3]][j+2] > res) {
						f[p[p3]][j+2] = res;
						from[p[p3]][j+2] = fr;
					}
				}
		}
	
	int st = 0;
	ll ans = 0;
	int cx=-1,cy; 
	if (n&1) {
		for (int i=1;i<=n;i++)
			if (cx == -1 || ans > f[i][n+1] + a[i]) {
				cx = i; cy = n+1;
				ans = f[i][n+1] + a[i];
			}
		lst[st++].push_back(cx); 
	} else {
		for (int i=1;i<=n;i++)
			if (cx == -1 || ans > f[i][n] + max(a[i],a[n])) {
				cx = i; cy = n;
				ans = f[i][n] + max(a[i],a[n]);
			}
		lst[st].push_back(n);
		lst[st++].push_back(cx);
	}
	
	while (cx != 1 || cy != 2) {
		cell fr = from[cx][cy];
		lst[st].push_back(fr.p1);
		lst[st++].push_back(fr.p2);
		
		cx = fr.x; cy = fr.y;
	}
	
	cout << ans << endl;
	for (st--;st>=0;st--) {
		for (int i=0;i<lst[st].size();i++) cout << lst[st][i] << " ";
		cout << endl;
	}
	
	return 0;
}