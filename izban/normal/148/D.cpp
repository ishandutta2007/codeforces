#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)

int a,b;
string s;

long double d[1001][1001],ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> a >> b;
	int i=0;
	d[a][b]=1;
	//q.push(make_pair(a,b));
	//while (!q.empty()) {
	//	int l=q.front().first();
	//	int r=q.front().second();
	int k=0;
	bool f=true;
	for (int i=a+b; i>0; i--) {
		f=false;
		for (int l=0; l<=i; l++) {
			int r=i-l;
			if (!(l<=a && r<=b && r>=0)) continue;
			if ((k&1)) {
			if (r) {
				if (l) d[l-1][r-1]+=d[l][r]*(l)/(l+r-1)*(r)/(l+r);
				if (r-1) d[l][r-2]+=d[l][r]*(r-1)/(l+r-1)*(r)/(l+r);
				if (d[l][r]) f=true;
			} } else {
				ans+=d[l][r]*(l)/(l+r);
				if (r) d[l][r-1]+=d[l][r]*(r)/(l+r);
				if (d[l][r]) f=true;
			}
		}
		k+=f;
	}
	printf("%.11lf",ans);
	return 0;
}