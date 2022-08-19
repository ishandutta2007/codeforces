#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 200005;
const int mod = 1e9 + 7;

int n, a[MAXN];
int trg[MAXN][31];
vector<pi> stk;

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<=n; i++){
		for(int j=0; j<30; j++){
			if((a[i] >> j) & 1) trg[i][j] = i;
			else trg[i][j] = trg[i-1][j];
		}
	}
	stk.push_back(pi(2e9, 0));
	lint ret = 0;
	for(int i=1; i<=n; i++){
		while(!stk.empty() && stk.back().first <= a[i]){
			stk.pop_back();
		}
		stk.push_back(pi(a[i], i));
		sort(trg[i], trg[i] + 31);
		int v = unique(trg[i], trg[i] + 31) - trg[i];
		reverse(trg[i], trg[i] + v);
		int val = 0;
		for(int j=0; j+1<v; j++){
			int s = trg[i][j+1] + 1;
			int e = trg[i][j];	
			val |= a[e];
			int st = 0, ed = stk.size() - 1;
			while(st != ed){
				int m = (st+ed+1)/2;
				if(stk[m].first < val) ed = m - 1;
				else st = m;
			}
			int firstpos = stk[st].second;
			ret += max(e - max(s, firstpos + 1) + 1, 0);
		}
	}
	cout << ret;
}