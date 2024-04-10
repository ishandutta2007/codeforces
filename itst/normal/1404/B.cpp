#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7;
int T , N , A , B , DA , DB; vector < int > nxt[300003];

int dep[_] , mxlen[_] , mx;
void dp(int x , int p){
	dep[x] = dep[p] + 1; mxlen[x] = 0;
	for(auto t : nxt[x])
		if(t != p){dp(t , x); mx = max(mx , mxlen[t] + mxlen[x] + 1); mxlen[x] = max(mxlen[x] , mxlen[t] + 1);}
}

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> A >> B >> DA >> DB; for(int i = 1 ; i <= N ; ++i) nxt[i].clear();
		for(int i = 1 ; i < N ; ++i){int p , q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
		dep[0] = -1; mx = 0; dp(A , 0);
		cout << (mx <= 2 * DA || dep[B] <= DA || DB <= 2 * DA ? "Alice" : "Bob") << endl;
	}
	return 0;
}