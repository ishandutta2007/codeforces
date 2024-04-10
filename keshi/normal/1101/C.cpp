#include <bits/stdc++.h>
using namespace std;

#define L second
#define R first
#define pb push_back

int dsu[100100], Size[100100], t, n, m, root_i, root_j;
pair<int, int> p, Un[100100];
pair< pair<int, int>, int> ab;
vector< pair< pair<int, int>, int> > a;

bool check(pair<int, int> se, pair<int, int> fi){
	if(fi.R >= se.L && fi.R <= se.R || fi.L >= se.L && fi.L <= se.R || se.R >= fi.L && se.R <= fi.R || se.L >= fi.L && se.L <= fi.R){
		return 1;
	}
	return 0;
}

pair<int, int> u(pair<int, int> fi, pair<int, int> se){
	p.L = min(fi.L, se.L);
	p.R = max(fi.R, se.R);
	return p;
}

void initialize(){
    for(int i = 0; i < n; i++){
    	dsu[i] = i;
    	Size[i] = 1;
	}
	a.clear();
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
    root_i = root(i);
    root_j = root(j);
    if(Size[root_i] < Size[root_j]){
		dsu[root_i] = dsu[root_j];
		Size[root_j] += Size[root_i];
		Un[root_j] = u(Un[root_j], Un[root_i]);
	}
	else{
		dsu[root_j] = dsu[root_i];
		Size[root_i] += Size[root_j];
		Un[root_i] = u(Un[root_j], Un[root_i]);
	}
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		initialize();
		for (int i = 0; i < n; i++){
			cin >> Un[i].L >> Un[i].R;
			ab.first = Un[i];
			ab.second = i;
			a.pb(ab);
		}
		sort(a.begin(), a.end());
		for(int i = n - 1; i > 0; i--){
			root_i = root(a[i].second);
			root_j = root(a[i - 1].second);
			if(check(Un[root_i], Un[root_j])){
				Union(root_i, root_j);
			}
		}
		m = root(0);
		if(Size[m] == n){
			cout << -1 << endl;
			continue;
		}
		for(int i = 0; i < n; i++){
			if(root(i) == m){
				cout << 1;
			}
			else{
				cout << 2;
			}
			cout << ' ';
		}
		cout << endl;
	}
}