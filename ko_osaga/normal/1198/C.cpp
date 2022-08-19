#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 600000;
const int mod = 1e9 + 7;
#define has(msk, v) (((msk) >> (v)) & 1)

int n, m;
pi e[MAXN];
bool chk[MAXN];

int main(){
	int t; scanf("%d",&t);
	for(int i=1; i<=t; i++){
		scanf("%d %d",&n,&m);
		fill(chk, chk + 3 * n + 1, 0);
		vector<int> v;
		for(int j=0; j<m; j++){
			scanf("%d %d",&e[j].first,&e[j].second);
			if(!chk[e[j].first] && !chk[e[j].second]){
				chk[e[j].first] = chk[e[j].second] = 1;
				v.push_back(j + 1);
			}
		}
		if(v.size() < n){
			puts("IndSet");
			int cnt = n;
			for(int i=1; i<=3*n; i++){
				if(!chk[i] && cnt){
					cnt--;
					printf("%d ", i);
				}
			}
			puts("");
		}
		else{
			puts("Matching");
			v.resize(n);
			for(auto &i : v) printf("%d ", i);
			puts("");
		}
	}
}