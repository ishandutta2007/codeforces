#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fs first
#define sc second
#define int long long
using namespace std;

int n, m;
bool prav = 0;
vector<int> a[100000]; 
int u[100000];

void dfs(int x, int y){
	u[x] = y;
	for (int i = 0; i < a[x].size(); i++){
		if (u[a[x][i] == y]){
			prav = 1;
		}
		if (u[a[x][i]] == 0){
			dfs(a[x][i], (y) % 2 + 1);
		}
	}
}

main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	bool prav = 0;
	cin >> n >> m;
	vector<pair<int, int> > kek;
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		a[x].push_back(y);
		
		a[y].push_back(x);
		kek.push_back(mp(x, y));
	}
	for (int i = 0; i < n; i++){
		if (u[i] == 0){
			dfs(i, 0);
		}
	}
	int kol1 = 0;
	int kol2 = 0;
	for (int i = 0; i < n; i++){
		if (u[i] == 1){
			kol1++;	
		}
		if (u[i] == 2){
			kol2++;
		}
	}
	for (int i = 0; i < m; i++){
		if (u[kek[i].fs] == u[kek[i].sc] && u[kek[i].fs] != 0){
			prav = 1;
		}
	}
	if (prav){
		cout << -1;
		return 0;
	}
	cout << kol1 << endl;
	for (int i = 0; i < n; i++){
		if (u[i] == 1){
			cout << i+1 << ' ';	
		}
	}
	
	cout << endl;
	cout << kol2 << endl;
	for (int i = 0; i < n; i++){
		if (u[i] == 2){
			cout << i+1 << ' ';	
		}
	}
	cout << endl;
}