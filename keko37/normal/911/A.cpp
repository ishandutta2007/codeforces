#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int MAXN = 100005;
const int INF = 1000000007;

int n, mini=INF, sol=INF;
int l[MAXN];
vector <int> v;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
		mini=min(mini, l[i]);
	}
	for (int i=0; i<n; i++) {
		if (l[i]==mini) v.push_back(i);
	}
	for (int i=1; i<v.size(); i++) {
		sol=min(sol, v[i]-v[i-1]);
	}
	cout << sol;
	return 0;
}