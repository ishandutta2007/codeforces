#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
const int MAXN = 100005;
const int MAXT = 4200000;
 
int n, m;
int s[MAXN], e[MAXN];
 
int component(){
	set<pi> edg;
	for(int i=0; i<m; i++){
		edg.insert(pi(s[i], e[i]));
		edg.insert(pi(e[i], s[i]));
	}
	set<int> s;
	int cnt = 0;
	for(int i=1; i<=n; i++) s.insert(i);
	for(int i=1; i<=n; i++){
		if(s.find(i) != s.end()){
			cnt++;
			queue<int> q;
			q.push(i);
			s.erase(i);
			while(!q.empty()){
				int t = q.front();
				q.pop();
				vector<int> stk;
				for(auto &i : s){
					if(edg.find(pi(t, i)) == edg.end()){
						stk.push_back(i);
					}
				}
				for(auto &i : stk){
					s.erase(i);
					q.push(i);
				}
			}
		}
	}
	return cnt;
}
 
int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		scanf("%d %d",&s[i], &e[i]);
	}
	cout << component() - 1 << endl;
}