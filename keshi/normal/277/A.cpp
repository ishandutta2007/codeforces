#include <bits/stdc++.h>
using namespace std;
int dsu[150], Size[150], n, m, ans, k, l;
vector< int > a[150];
#define F first
#define S second

void initialize(){
    for(int i = 0; i < n; i++){
    	dsu[i] = i;
    	Size[i] = 1;
	}
}

int root(int i){
	if (dsu[i] == i){
		return dsu[i];
	}
	dsu[i] = root(dsu[i]);
	return dsu[i];
}

bool find(int i, int j){
	if (root(i) == root(j)){
		return 1;
	}
	return 0;
}

void Union(int i, int j){
	if (find(i, j)){
		return;
	}
    int root_i = root(i);
    int root_j = root(j);
    if(Size[root_i] < Size[root_j]){
		dsu[root_i] = dsu[root_j];
		Size[root_j] += Size[root_i];
	}
	else{
		dsu[root_j] = dsu[root_i];
		Size[root_i] += Size[root_j];
	}
}

int main(){
	bool f = 1;
	cin >> n >> m;
	initialize();
	for (int i = 0; i < n; i++){
		cin >> k;
		if (k){
			f = 0;
		}
		while (k--){
			cin >> l;
			a[l - 1].push_back(i);
		}
	}
	for(int i = 0; i < m; i++){
		for (int j = 1; j < a[i].size(); j++){
			Union(a[i][j], a[i][j - 1]);
		}
	}
	ans = -1;
	for (int i = 0; i < n; i++){
		if (dsu[i] == i){
			ans++;
		}
	}
	if (f){
		ans++;
	}
	cout << ans;
	return 0;
}