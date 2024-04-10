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

const int maxn=1000;

int n,ans;
int x[maxn],y[maxn];
string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) 
		cin >> x[i] >> y[i];
	for (int i=0; i<n; i++) {
		bool fx0=false,fx1=false,fy0=false,fy1=false;
		for (int j=0; j<n; j++) {
			fx0|= y[i]==y[j] && x[i]>x[j];
			fx1|= y[i]==y[j] && x[i]<x[j];
			fy0|= y[i]<y[j] && x[i]==x[j];
			fy1|= y[i]>y[j] && x[i]==x[j];
		}
		ans+=fx0&&fx1&&fy0&&fy1;
	}
	cout << ans;
	return 0;
}