#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, x;
vector<pair<int, int> > v[2];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) v[(i + j) & 1].push_back({i, j});
	for(int i = 1;i <= n * n;i++){
		scanf("%d", &x);
		if(x == 1){
			if(!v[1].empty()){
				printf("2 %d %d\n", v[1].back().first, v[1].back().second);
				fflush(stdout);
				v[1].pop_back();
			}else{
				printf("3 %d %d\n", v[0].back().first, v[0].back().second);
				fflush(stdout);
				v[0].pop_back();
			}
		}else if(x == 2){
			if(!v[0].empty()){
				printf("1 %d %d\n", v[0].back().first, v[0].back().second);
				fflush(stdout);
				v[0].pop_back();
			}else{
				printf("3 %d %d\n", v[1].back().first, v[1].back().second);
				fflush(stdout);
				v[1].pop_back();
			}
		}else{
			if(!v[0].empty()){
				printf("1 %d %d\n", v[0].back().first, v[0].back().second);
				fflush(stdout);
				v[0].pop_back();
			}else{
				printf("2 %d %d\n", v[1].back().first, v[1].back().second);
				fflush(stdout);
				v[1].pop_back();
			}
		}
	}
}