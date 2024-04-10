#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define X first
#define Y second

const int MN = 1005;

int n;
vector<int> ch[MN];

int main(){
	scanf("%d", &n);
	for(int i = 2, x; i <= n; i++){
		scanf("%d", &x);
		ch[x].push_back(i);
	}
	for(int i = 1; i <= n; i++){
		if(ch[i].empty()) continue;
		int cnt = 0;
		for(int j : ch[i]){
			if(ch[j].empty()) cnt++;
		}
		if(cnt < 3){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}