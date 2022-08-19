#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;
const int MAXM = 200005;

int main(){
	int t; cin >> t;
	for(int i=1; i<=t; i++){
		int n; scanf("%d",&n);
		if(n == 1) puts("-1");
		else{
			for(int i=0; i<n-1; i++) printf("3");
			puts("4");
		}
	}
}