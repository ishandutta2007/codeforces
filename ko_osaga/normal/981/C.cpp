#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
using lint = long long;
using pi = pair<int, int>;

vector<int> gph[MAXN];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n-1; i++){
		int s, e; scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	int cnt = 0, mx = 0;
	for(int i=1; i<=n; i++){
		if(gph[i].size() >= 3){
			cnt++;
		}
		mx = max(mx, (int)gph[i].size());
	}
	if(cnt > 1) puts("No");
	else{
		puts("Yes");
		for(int i=1; i<=n; i++){
			if(gph[i].size() == mx){
				vector<pi> v;
				for(int j=1; j<=n; j++){
					if(j != i && gph[j].size() == 1){
						v.emplace_back(i, j);
					}
				}
				cout << v.size() << endl;
				for(auto &i : v){
					printf("%d %d\n", i.first, i.second);
				}
				break;
			}
		}
}
}