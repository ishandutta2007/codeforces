#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
using lint = long long;
using pi = pair<int, int>;

int deg[MAXN];

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n-1; i++){
		int s, e; scanf("%d %d",&s,&e);
		deg[s]++; deg[e]++;
	}
	if(count(deg, deg + n + 1, 2)) puts("NO");
	else puts("YES");
}