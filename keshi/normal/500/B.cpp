#include <bits/stdc++.h>
using namespace std;
int dsu[350], Size[350], n, m, ans, a[350];
vector< int > b[350];
vector <int> c;
string s;
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
	cin >> n;
	initialize();
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> s;
		for (int j = 0; j < n; j++){
			if (s[j] == '1'){
				Union(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++){
		b[root(i)].push_back(i);
	}
	for (int i = 0; i < n; i++){
		c.clear();
		for (int j = 0; j < b[i].size(); j++){
			c.push_back(a[b[i][j]]);
		}
		sort(c.begin(), c.end());
		for (int j = 0; j < b[i].size(); j++){
			a[b[i][j]] = c[j]; // b[i] is sorted!
		}
	}
	for(int i = 0; i < n; i++){
		cout << a[i] << ' ';
	}
	return 0;
}