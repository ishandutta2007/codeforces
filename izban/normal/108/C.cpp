#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

#define sqr(x) ((x)*(x))

int nx[1000],w[1000],a1[1000],a2[1000],a3[1000];
bool vis[1000],u[1000];
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
#endif
	int n,m,k=0,i,a,b,c,x,ans=0;
	cin >> n >> m;
	for (i=0; i<n; i++) nx[i]=-1;
	for (i=0; i<m; i++) {
		cin >> a >> b >> c;
		nx[a-1]=b-1;
		w[a-1]=c;
		u[b-1]=true;
	}
	for (i=0; i<n; i++){
		if (!vis[i] && !u[i] && nx[i]!=-1) {
			a1[ans]=i+1;
			int mn=2<<25;
			x=i;
			bool f=false;
			while (nx[x]!=-1 && !f) {
				vis[x]=true;
				mn=min(mn,w[x]);
				x=nx[x];
				if (x==i) f=true;
			}
			if (f) continue;
			vis[x]=true;
			a2[ans]=x+1;
			a3[ans]=mn;
			ans+=1;
		}
	}
	cout << ans << endl;
	for (i=0; i<ans; i++) {
		cout << a1[i] << ' ' << a2[i] << ' ' << a3[i] << endl;
	}
	return 0;
}