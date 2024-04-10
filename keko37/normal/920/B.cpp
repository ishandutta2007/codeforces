#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

const int MAXN = 10005;

int t, n;
int x[MAXN], y[MAXN];
queue <int> q;

int main () {
	cin >> t;
	for (int tc=0; tc<t; tc++) {
		cin >> n;
		for (int i=0; i<n; i++) {
			scanf("%d%d", &x[i], &y[i]);
		}
		int ind=0;
		for (int i=1; i<MAXN; i++) {
			while (ind<n && x[ind]<=i) {
				q.push(ind);
				ind++;
			}
			while (!q.empty()) {
				int f=q.front();
				q.pop();
				if (i>y[f]) {
					printf("0 ");
				} else {
					printf("%d ", i);
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}