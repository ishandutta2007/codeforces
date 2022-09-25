#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=50;

int n,k,ans;
string s[maxn];
int a[maxn][maxn];
vector<int> v;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> k;
	for (int i=0; i<n; i++) 
		cin >> s[i];
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++) {
			a[i][j]=a[j][i]=min(s[i].length(),s[j].length());
			for (int k=0; k<max(s[i].length(),s[j].length()); k++) 
				if (s[i][k]!=s[j][k]) {
					a[i][j]=a[j][i]=k;
					break;
				}
		}
	}
	for (int mask=0; mask<(1<<n); mask++) {
		v.clear();
		for (int i=0; i<n; i++) 
			if (mask & (1<<i)) 
				v.push_back(i);
		if (v.size()==k) {
			int sum=0;
			for (int i=0; i<k-1; i++)
				for (int j=i+1; j<k; j++)
					sum+=a[v[i]][v[j]];
			ans=max(ans,sum);
		}
	}
	cout << ans;
	return 0;
}