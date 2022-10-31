#include <bits/stdc++.h>
using namespace std;
queue <long long> arrm;
long long n, m, arrg[10000007],c,k=0;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin>>arrg[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> c; arrm.push(c);
	}
	for (int i = 0; i < n; i++) {
		if (arrm.empty()!=true && arrm.front() >= arrg[i]) {
			k++;
			arrm.pop();
		}
	}
	cout << k;
	
}