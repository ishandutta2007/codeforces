#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int t;
vector<int> v[2];
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= 2 * n;i++){
			scanf("%d", &x);
			v[x & 1].push_back(i);
		}
		if(v[0].size() & 1) v[0].pop_back(), v[1].pop_back();
		else if(v[0].size()) v[0].pop_back(), v[0].pop_back();
		else v[1].pop_back(), v[1].pop_back();
		while(v[0].size()){
			printf("%d ", v[0][v[0].size() - 1]), v[0].pop_back();
			printf("%d\n", v[0][v[0].size() - 1]), v[0].pop_back();
		}
		while(v[1].size()){
			printf("%d ", v[1][v[1].size() - 1]), v[1].pop_back();
			printf("%d\n", v[1][v[1].size() - 1]), v[1].pop_back();
		}
	}
}