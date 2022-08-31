#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d", &(x))

const int N = 1e5 +10;
int p[N], col[N], vis[N];
int c1, c2;
vector<int> vec;
vector<pair<int, int> > edges;
int main(){
	int n;
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(p[i]);
		if(p[i] == i){
			printf("YES\n");
			for(int j= 1; j <= n; j++){
				if(j != i){
					printf("%d %d\n", i, j);
				}
			}
			return 0;
		}
	}
	// check if permutation cycles are all even
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			int j = i;
			int cnt = 0;
			int c = 0;
			vec.clear();
			while(!vis[j]){
				col[j] = c;
				c ^= 1;
				vis[j] = 1;
				vec.push_back(j);
				j = p[j];
				cnt++;
			}
			if(cnt & 1){
				printf("NO\n");
				return 0;
			}
			if(cnt == 2){
				c1 = vec[0];
				c2 = vec[1];
			}
		}
	}
	if(c1 == 0){
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
	printf("%d %d\n", c1, c2);
	for(int i = 1; i <= n; i++){
		if(i != c1 && i != c2){
			if(col[i]){
				printf("%d %d\n", c1, i);
			}
			else{
				printf("%d %d\n", c2, i);
			}
		}
	}
}