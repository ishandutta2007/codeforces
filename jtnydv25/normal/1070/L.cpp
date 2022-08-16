#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
const int N = 2005;

struct graph{
	vector<int> deg;
	bitset<N> con[N];
	int n;
	graph(int n) : n(n){}

	void add_edge(int a, int b){
		con[a][b] = con[b][a] = 1;
	}

	pair<set<int>, set<int> > partition(){
		set<int> A,B;
		for(int i = 1; i <= n; i++) A.insert(i);

		int node = 0;

		for(int i = 1; i <= n; i++) if(con[i].count() & 1) node = i;
		if(node == 0) return {A, {}};
		A.clear();

		bitset<N> temp = con[node];
		con[node].reset();

		for(int i = 1; i <= n; i++){
			con[i][node] = 0;
			if(temp[i]){
				con[i] ^= temp;
				con[i][i] = 0;
			}
		}

		pair<set<int>, set<int>> part = partition();
		A = part.first, B = part.second;

		int cnt1 = 0, cnt2 = 0;
		for(int i = 1; i <= n; i++) if(temp[i]) {
			cnt1 ^= A.count(i);
			cnt2 ^= B.count(i);
		}
		
		if(cnt1 == 0 && !A.count(node)){
			A.insert(node);
			B.erase(node);
		} else if(cnt1==1 && A.count(node)){
			B.insert(node);
			A.erase(node);
		}

		// restore
		con[node] = temp;
		for(int i = 1; i <= n; i++) if(temp[i]) con[i][node] = 1;
		for(int i = 1; i <= n; i++){
			if(temp[i]){
				con[i] ^= temp;
				con[i][i] = 0;
			}
		}
		return {A, B};
	}
};

int main(){
	int t, n = 0, m = 0;
	sd(t);
	while(t--){
		sd(n); sd(m);
		graph g(n);
		for(int i = 1; i <= m; i++){
			int x, y; sd(x); sd(y);
			g.add_edge(x, y);
		}
		pair<set<int>, set<int>> part = g.partition();
		printf("%d\n", (part.second.empty())?1:2);
		for(int i = 1; i <= n; i++){
			if(part.first.count(i)) printf("%d ", 1);
			else printf("%d ", 2);
		}
		printf("\n");
	}
}