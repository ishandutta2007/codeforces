#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;

int n, k, a[MAXN];

int trial(int x){
	int cnt = 0;
	for(int i=0; i<n; ){
		int e = i;
		while(e < n && a[e] - a[i] < x) e++;
		i = e;
		cnt++;
	}
	return cnt;
}

int main(){
	scanf("%d %*d %d",&n,&k);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	int dap = n;
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=0; i+1<n; i++){
		pq.push(a[i+1] - a[i] - 1);
	}
	for(int i=0; i<n-k; i++){
		dap += pq.top();
		pq.pop();
	}
	cout << dap << endl;
}