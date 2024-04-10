#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;

int X[10], Y[10];
pair<int, int> x[10];

int main(){
	for(int i = 0; i < 3; i++){
		scanf("%d%d", &x[i].first, &x[i].second);
		X[i] = x[i].first, Y[i] = x[i].second;
	}
	sort(X, X + 3), sort(Y, Y + 3);
	int xx = X[1], yy = Y[1]; 
	vector<tuple<int, int, int, int>> ans;
	for(int i = 0; i < 3; i++){
		if(x[i].first == xx && x[i].second == yy) continue;
		if(x[i].first != xx){
			ans.push_back(make_tuple(x[i].first, x[i].second, xx, x[i].second));
		}
		if(x[i].second != yy){
			ans.push_back(make_tuple(xx, x[i].second, xx, yy));
		}
	}
	printf("%d\n", ans.size());
	for(auto t: ans){
		printf("%d %d %d %d\n", get<0>(t), get<1>(t), get<2>(t), get<3>(t));
	}
}