#include<bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
const int MAXN = 200005;
using lint = long long;
using pi = pair<lint, lint>;

int n, a[MAXN];
int minpos[MAXN], maxpos[MAXN];
int dx[MAXN];

int main(){
	scanf("%d %*d",&n);
	memset(minpos, 0x3f, sizeof(minpos));
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		minpos[a[i]] = min(minpos[a[i]], i);
		maxpos[a[i]] = max(maxpos[a[i]], i);
	}
	for(int i=1; i<=200000; i++){
		if(minpos[i] < maxpos[i]){
			dx[minpos[i]]++;
			dx[maxpos[i]]--;
		}
	}
	for(int i=1; i<=n; i++) dx[i] += dx[i-1];
	int dap = 0;
	for(int i=0; i<n; ){
		int e = i;
		while(e < n-1 && dx[e]) e++;
	//	printf("%d %d\n", i, e);
		sort(a + i, a + e + 1);
		int ret = 0;
		for(int j=i; j<=e; ){
			int k = j;
			while(k <= e && a[j] == a[k]) k++;
			ret = max(ret, k - j);
			j = k;
		}
		dap += e - i + 1 - ret;
		i = e + 1;
	}
	cout << dap << endl;
}