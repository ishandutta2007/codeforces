#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	deque<int> a;
	for (int i=1; i<=n; i++) 
		a.push_back(i);
	for (int k=2; k<=n; k++) {
		a.push_back(-1);
		vector<deque<int>::iterator> vit;
		for (int i=0; i<n; i+=k)
			vit.push_back(a.begin() + i);
		vit.push_back(--a.end());
		for (int i=vit.size()-1; i>0; i--)
			*vit[i] = *vit[i-1];
		a.pop_front();
	}

	for (int x : a)
		cout << x << ' ';
	cout << '\n';
}