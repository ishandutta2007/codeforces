#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 500005;

int n, d[N], p[N], oddr[N], evenr[N];
vector<int> e[N], dep[N];

int f(int x, int y){
	for(int i : e[x]) if(i != y){
		int t = f(i, x);
		dep[x].push_back(t + 1);
		d[x] = max(d[x], t + 1);
	}
	sort(dep[x].rbegin(), dep[x].rend());
	return d[x];
}

void g(int x, int y, int pd){
	int fm = 0, sm = 0;
	if(dep[x].size() >= 1) fm = dep[x][0];
	if(dep[x].size() >= 2) sm = dep[x][1];
	for(int i : e[x]) if(i != y){
		int td = max(pd, (d[i]+1 == fm ? sm : fm)) + 1;
		g(i, x, td);
	}
	if(x == 1) return;
	p[x] = pd;
	dep[x].push_back(pd);
	sort(dep[x].rbegin(), dep[x].rend());
}

void oddf(int x, int y){
	//cout << x << '\n';
	//for(int i : dep[x]) cout << i << ' '; cout << '\n';
	for(int i = 2; i-1 < dep[x].size(); i++){
		int t = min(dep[x][i-1] + 1, dep[x][i-2]);
		//cout << "-- " << i << ' ' << t << '\n';
		oddr[t] = max(oddr[t], i);
		int u = dep[x][i-1];
		evenr[u] = max(evenr[t], i);
	}
	for(int i : e[x]) if(i != y) oddf(i, x);
}

void evenf(int x, int y){
	//cout << " ////// " << x << ' ' << y << '\n';
	for(int i : e[x]) if(i != y){
		int AT = e[x].size() + e[i].size(), BT = min(dep[x][0], dep[i][0]);
		if(AT < BT){
			//cout << "A\n";
			vector<int> v;
			int t = 0;
			for(int j : dep[x]){
				if(!t && j == d[i]+1) t = 1;
				else v.push_back(j);
			}
			t = 0;
			for(int j : dep[i]){
				if(!t && j == p[i]) t = 1;
				else v.push_back(j);
			}
			sort(v.rbegin(), v.rend());
			//for(int j : v) cout << j << ' '; cout << '\n';
			for(int j = 2; j <= v.size(); j++){
				evenr[v[j-1]] = max(evenr[v[j-1]], j);
			}
		}
		else{
			//cout << "B\n";
			for(int j = 1; ; j++){
				int xc = int(
					upper_bound(dep[x].begin(), dep[x].end(), j, greater<int>())
					- dep[x].begin()) - (d[i]+1 >= j);
				int ic = int(
					upper_bound(dep[i].begin(), dep[i].end(), j, greater<int>())
					- dep[i].begin()) - (p[i] >= j);
				//cout << j << ' ' << xc+ic << '\n';
				if(xc == 0 || ic == 0) break;
				evenr[j] = max(evenr[j], xc + ic);
			}
		}
	}
	for(int i : e[x]) if(i != y) evenf(i, x);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0, x, y; i < n-1; i++){
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	f(1, 0);
	g(1, 0, 0);

	fill(oddr, oddr + N, 1);
	fill(evenr, evenr + N, 1);

	oddf(1, 0);
	evenf(1, 0);

	for(int i = 1; i <= n; i++){
		int t = dep[i][0] / 2;
		evenr[t] = max(evenr[t], 2);
	}

	for(int i = n; i >= 1; i--){
		oddr[i] = max(oddr[i], oddr[i+1]);
		evenr[i] = max(evenr[i], evenr[i+1]);
	}

	oddr[1] = 0;
	for(int i = 1; i <= n; i++) oddr[1] = max(oddr[1], (int)e[i].size() + 1);
	for(int i = 1; i <= n; i++){
		if(i & 1) cout << oddr[i / 2 + 1] << ' ';
		else cout << evenr[i / 2] << ' ';
	}
	cout << '\n';
}