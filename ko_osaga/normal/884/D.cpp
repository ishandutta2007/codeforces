#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;

priority_queue<lint, vector<lint>, greater<lint> > pq;

int main(){
	int n; scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x; scanf("%d",&x); pq.push(x);
	}
	lint ret = 0;
	int w = 1 - n % 2;
	for(int i=0; i<w; i++){
		auto x = pq.top(); pq.pop();
		auto y = pq.top(); pq.pop();
		ret += x + y;
		pq.push(x + y);
	}
	while(sz(pq) > 1){
		auto x = pq.top(); pq.pop();
		auto y = pq.top(); pq.pop();
		auto z = pq.top(); pq.pop();
		ret += x + y + z;
		pq.push(x + y + z);
	}
	cout << ret << endl;
}