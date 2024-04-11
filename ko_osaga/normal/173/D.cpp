#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

vector<int> gph[100005];
int col[100005], ret[100005];

void dfs(int x, int c){
	if(col[x]) return;
	col[x] = c;
	for(auto &i : gph[x]){
		dfs(i, 3-c);
	}
}

vector<int> clr[3];

int main(){
	int n, m;
	cin >> n >> m;
	while(m--){
		int s, e;
		cin >> s >> e;
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	for(int i=1; i<=n; i++){
		if(!col[i]) dfs(i, 1);
	}
	int t = count(col + 1, col + n + 1, 1) % 3;
	if(t == 2){
		for(int i=1; i<=n; i++){
			col[i] = 3 - col[i];
		}
		t = 3 - t;
	}
	for(int i=1; i<=n; i++){
		clr[col[i]].push_back(i);
	}
	int p = 0;
	if(t == 1){
		bool ok = 0;
		for(int i=1; i<=n; i++){
			if(col[i] == 1){
				int u = clr[2].size();
				if(u - 2 >= gph[i].size()){
					set<int> s;
					for(auto &j : gph[i]){
						s.insert(j);
					}
					ret[i] = 1;
					int cnt = 2;
					for(auto &i : clr[2]){
						if(s.find(i) == s.end()){
							cnt--;
							ret[i] = 1;
						}
						if(cnt == 0) break;
					}
					ok = 1;
					break;
				}
			}
		}
		if(!ok){
			if(clr[1].size() >= 4 && clr[2].size() >= 2){
				int tcnt = 2;
				for(int i=1; i<=n; i++){
					if(col[i] == 2){
						int u = clr[1].size();
						if(u - 2 >= gph[i].size()){
							set<int> s;
							for(auto &j : gph[i]){
								s.insert(j);
							}
							ret[i] = 3 - tcnt;
							int cnt = 2;
							for(auto &i : clr[1]){
								if(s.find(i) == s.end()){
									cnt--;
									ret[i] = 3 - tcnt;
								}
								if(cnt == 0) break;
							}
							tcnt--;
							if(tcnt == 0){
								ok = 1;
								break;
							}
						}
					}
				}
				p++;
			}
			if(!ok){
				puts("NO");
				return 0;
			}
		}
		p++;
	}
	int cnt = 3;
	for(auto &i : clr[1]){
		if(!ret[i]){
			cnt--;
			ret[i] = p+1;
			if(cnt == 0) cnt = 3, p++;
		} 
	}
	for(auto &i : clr[2]){
		if(!ret[i]){
			cnt--;
			ret[i] = p+1;
			if(cnt == 0) cnt = 3, p++;
		}
	}
	puts("YES");
	for(int i=1; i<=n; i++){
		printf("%d ",ret[i]);
	}
}