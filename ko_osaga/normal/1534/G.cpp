#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 800005;
const int mod = 1e9 + 7;

int n;
pi a[MAXN];

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		int x, y; scanf("%d %d",&x,&y);
		a[i] = pi(x + y, y);
	}
	sort(a, a + n);
	priority_queue<lint> loQ;
	priority_queue<lint, vector<lint>, greater<lint>> hiQ;
	lint hiOffset = 0;
	int prv = 0;
	lint ret = 0;
	for(int i = 0; i < n; ){
		int e = i;
		while(e < n && a[e].first == a[i].first) e++;
		hiOffset += a[i].first - prv;
		prv = a[i].first;
		for(int j = i; j < e; j++){
			loQ.push(a[j].second);
			hiQ.push(a[j].second - hiOffset);
		}
		while(loQ.top() > hiQ.top() + hiOffset){
			lint x = loQ.top();
			lint y = hiQ.top() + hiOffset;
			loQ.pop();
			hiQ.pop();
			ret += x - y;
			loQ.push(y);
			hiQ.push(x - hiOffset);
		}
		i = e;
	}
	cout << ret << endl;
}