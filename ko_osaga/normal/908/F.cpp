#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
const int MAXN = 300005;

int n;
char c[MAXN][3];
int a[MAXN];

int maxGap(vector<int> v){
	int dap = 0;
	for(int i=1; i<v.size(); i++) dap = max(dap, v[i] - v[i-1]);
	return dap;
}

int main(){
	scanf("%d",&n);
	vector<int> gp;
	for(int i=0; i<n; i++){
		scanf("%d %c",&a[i],c[i]);
		if(*c[i] == 'G') gp.push_back(i);
	}
	if(gp.empty()){
		int minR = 1e9, maxR = -1e9;
		int minB = 1e9, maxB = -1e9;
		for(int i=0; i<n; i++){
			if(*c[i] == 'R'){
				minR = min(minR, a[i]);
				maxR = max(maxR, a[i]);
			}
			else{
				minB = min(minB, a[i]);
				maxB = max(maxB, a[i]);
			}
		}
		cout << max(maxR - minR, 0) + max(maxB - minB, 0) << endl;
		return 0;
	}
	int ret = 0;
	for(int i=1; i<gp.size(); i++){
		vector<int> Rp, Bp;
		for(int j=gp[i-1]; j<=gp[i]; j++){
			if(*c[j] != 'B') Rp.push_back(a[j]);
			if(*c[j] != 'R') Bp.push_back(a[j]);
		}
		int L = a[gp[i]] - a[gp[i-1]];
		ret += 3ll * L - max({L, maxGap(Rp) + maxGap(Bp)});
	}
	{
		int minR = 1e9, maxR = -1e9;
		int minB = 1e9, maxB = -1e9;
		for(int i=0; i<=gp[0]; i++){
			if(*c[i] != 'B') minR = min(minR, a[i]);
			if(*c[i] != 'R') minB = min(minB, a[i]);
		}
		for(int i=gp.back(); i<n; i++){
			if(*c[i] != 'B') maxR = max(maxR, a[i]);
			if(*c[i] != 'R') maxB = max(maxB, a[i]);
		}
		ret += 2 * a[gp[0]] - minR - minB + (maxR + maxB - a[gp.back()] * 2);
	}
	cout << ret << endl;
}