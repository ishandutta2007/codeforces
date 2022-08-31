#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 1000005;

int n, a[MAXN];
priority_queue<int, vector<int>, greater<int> > pq;

int main(){
	scanf("%d",&n);
	lint ret = 0;
	for(int i=0; i<n; i++){
		int x; scanf("%d",&x);
		pq.push(x); pq.push(x);
		ret += x - pq.top();
		pq.pop();
	}
	cout << ret << endl;
}