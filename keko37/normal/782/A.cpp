#include<iostream>

using namespace std;

const int MAXN = 100005;

int n, x, cnt, sol;
int l[MAXN];

int main () {
	cin >> n;
	for (int i=0; i<2*n; i++) {
		cin >> x;
		if (l[x]==0) {
			l[x]++;
			cnt++;
			sol=max(sol, cnt);
		} else if (l[x]==1) {
			l[x]++;
			cnt--;
		}
	}
	cout << sol;
	return 0;
}