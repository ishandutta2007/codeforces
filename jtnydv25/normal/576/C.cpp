#include <bits/stdc++.h>
using namespace std;

const int B = 1005;
pair<int, pair<int, int> > pts[1000006];
vector<pair<int, pair<int, int> > > ptblocks[1005];

int main(){
	int n, x, y;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &x, &y);
		ptblocks[x / B].push_back({y, {x, i}});
	}

	for(int i = 0; i < 1005; i++){
		sort(ptblocks[i].begin(), ptblocks[i].end());
		for(auto it : ptblocks[i]) printf("%d ", it.second.second);
	}
	printf("\n");
}