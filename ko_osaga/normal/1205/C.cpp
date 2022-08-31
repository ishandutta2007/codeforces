#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 10005;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n;
int arr[5][5];

struct disj{
	int pa[MAXN];
	void init(){
		iota(pa, pa + MAXN, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
	void set(int x, int y, int z){
		uni(2 * x + z, 2 * y);
		uni(2 * y + 1, 2 * x + 1 - z);
	}
}disj;

bool same_color(int x, int y){
	assert(disj.find(2 * x) == disj.find(2 * y) ||
	disj.find(2 * x) == disj.find(2 * y + 1));
	return disj.find(2 * x) == disj.find(2 * y);
}

bool ispal(vector<int> &v, int x, int y){
	vector<int> w(v.begin() + x, v.begin() + y);
	auto ww = w;
	reverse(ww.begin(), ww.end());
	return w == ww;
}

int query(int x1, int y1, int x2, int y2){
	printf("? %d %d %d %d\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
	fflush(stdout);
	int x; cin >> x;
	return x;
}

int get(int x, int y){
	 return x * n + y;
}

void report(){
	puts("!");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!same_color(0, get(i, j))) printf("0");
			else printf("1");
		}
		puts("");
	}
	exit(0);
}


int main(){
	scanf("%d",&n);
	disj.init();
	for(int i=1; i<n; i++){
		for(int j=1; j<n; j++){
			bool diff = !query(i - 1, j - 1, i, j);
			disj.set(get(i - 1, j - 1), get(i, j), diff);
		}
	}
	for(int i=2; i<n; i++){
		{
			bool diff = !query(0, i - 2, 0, i);
			disj.set(get(0, i - 2), get(0, i), diff);
		}
		{
			bool diff = !query(i - 2, 0, i, 0);
			disj.set(get(i - 2, 0), get(i, 0), diff);
		}
	}
	disj.set(get(1, 0), get(1, 2), !query(1, 0, 1, 2));
	for(int i=1; i<n; i++){
		for(int j=1; j<n; j++){
			if(!same_color(get(i-1, j), get(i, j-1))){
				if(i == 1){
					auto qr = !query(i - 1, j - 1, i + 1, j);
					disj.set(get(i - 1, j - 1), get(i + 1, j), qr);
					report();
				}
				else{
					auto qr = !query(i - 2, j - 1, i, j);
					disj.set(get(i - 2, j - 1), get(i, j), qr);
					report();
				}
			}
		}
	}
	vector<int> theory1 = {0, 0};
	vector<int> theory2 = {0, 1};
	vector<pi> cells;
	for(int i=0; i<2*n-1; i++){
		pi celly(i, 0);
		if(celly.first >= n){
			celly.second = celly.first - n + 1;
			celly.first = n - 1;
		}
		cells.push_back(celly);
	}
	for(int i=2; i<=2*n-2; i++){
		auto cellx = cells[i - 2];
		auto celly = cells[i - 0];
		if(same_color(get(cellx.first, cellx.second), get(celly.first, celly.second))){
			theory1.push_back(theory1[i - 2]);
			theory2.push_back(theory2[i - 2]);
		}
		else{
			theory1.push_back(!theory1[i - 2]);
			theory2.push_back(!theory2[i - 2]);
		}
	}
	for(int i=0; i<theory1.size(); i++){
		for(int j=i+2; j<theory1.size(); j++){
			if(ispal(theory1, i, j + 1) != ispal(theory2, i, j + 1)){
				auto cellx = cells[i];
				auto celly = cells[j];
				auto qr = query(cellx.first, cellx.second, celly.first, celly.second);
				if(qr == ispal(theory1, i, j + 1)){
					disj.set(get(0, 0), get(0, 1), 0);
				}
				else{
					disj.set(get(0, 0), get(0, 1), 1);
				}
				report();
			}
		}
	}
}