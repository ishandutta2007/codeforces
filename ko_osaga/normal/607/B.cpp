#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, a[505];
int dp1[505][505], dp2[505][505];

bool pal[505][505];

inline bool ispal(int s, int e){
	if(s > e) return 1;
	return pal[s][e];
}

int f(int s, int e);

int g(int s, int e){
	if(s > e) return 0;
	if(~dp1[s][e]) return dp1[s][e];
	int ret = 1e9;
	if(a[s] == a[e]) ret = min(ret, g(s+1, e-1));
	for(int i=s; i<e; i++){
		ret = min(ret, f(s, i) + g(i+1, e));
		ret = min(ret, g(s, i) + f(i+1, e));
	}
	return dp1[s][e] = ret;
}

int f(int s, int e){
	if(s > e) return 0;
	if(~dp2[s][e]) return dp2[s][e];
	int ret = g(s, e) + 1;
	return dp2[s][e] = ret;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			pal[i][j] = 1;
			for(int k=i; k<=j; k++){
				if(a[k] != a[i+j-k]){
					pal[i][j] = 0;
				}
			}
		}
	}
	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));
	cout << f(0, n-1);
}