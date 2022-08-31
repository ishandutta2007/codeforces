#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

const int N = 300005;
int n, m;
vector<int> con[N];
set<int> con2[N];

int hsh[N];

int main(){
	sd(n); sd(m);
	for(int i = 1; i <= m; i++){
		int x, y;
		sd(x); sd(y);
		con[x].push_back(y);
		con[y].push_back(x);
		con2[x].insert(y);
		con2[y].insert(x);
	}

	if(con2[1].count(n)){
		printf("1\n");
		printf("%d %d\n", 1, n);
		return 0;
	}

	for(auto it : con[1]) if(con2[it].count(n)){
		printf("2\n");
		printf("%d %d %d\n", 1, it, n);
		return 0;
	}

	for(auto it : con[1]){
		for(auto it2 : con[it])
			if(it2 != 1 && con2[it2].count(n)){
				printf("3\n");
				printf("%d %d %d %d\n", 1, it, it2, n);
				return 0;
			}
		}

	for(auto it : con[1]){
		for(auto it2 : con[it])
			if(it2 != 1 && !con2[1].count(it2)){
				printf("4\n");
				printf("%d %d %d %d %d\n", 1, it, it2, 1, n);
				return 0;
			}
	}

	for(auto it : con[1]){
		con[it].push_back(it);
		sort(con[it].begin(), con[it].end());
		for(auto it2 : con[it]) if(it2 != 1 && con2[1].count(it2)) hsh[it] = (hsh[it] * (ll) 1000003 + it2) % 1000000007;;
	}

	for(auto it : con[1]){
		for(auto it2 : con[it]){
			if(it2 < it || it2 == 1 || it2 == it || !con2[1].count(it2) || hsh[it] == hsh[it2]) continue;

			for(auto z : con[it])
				if(z != it && z != it2 && !con2[it2].count(z)){
					printf("5\n");
					printf("%d %d %d %d %d %d\n", 1, it2, it, z, it2, n);
					return 0;
				}

			for(auto z : con[it2])
				if(z != it && z != it2 && !con2[it].count(z)){
					printf("5\n");
					printf("%d %d %d %d %d %d\n", 1, it, it2, z, it, n);
					return 0;
				}
		}
	}
	printf("-1\n");
}