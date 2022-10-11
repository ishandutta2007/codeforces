#include <bits/stdc++.h>
using namespace std;
int dsu[150], Size[150], n, ans, x, y;
vector< pair< pair<int, int>, int> > a;
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
		cin >> x >> y;
		a.push_back( {{x, y}, i} );
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n - 1; i++){
		if (a[i].F.F == a[i + 1].F.F){
			Union(a[i].S, a[i + 1].S);
		}
		swap(a[i].F.F, a[i].F.S);
	}
	swap(a[n - 1].F.F, a[n - 1].F.S);
	sort(a.begin(), a.end());
	for(int i = 0; i < n - 1; i++){
		if (a[i].F.F == a[i + 1].F.F){
			Union(a[i].S, a[i + 1].S);
		}
		swap(a[i].F.F, a[i].F.S);
	}
	swap(a[n - 1].F.F, a[n - 1].F.S);
	ans = -1;
	for (int i = 0; i < n; i++){
		if (dsu[i] == i){
			ans++;
		}
	}
	cout << ans;
	return 0;
}