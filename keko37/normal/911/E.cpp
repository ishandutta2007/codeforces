#include<iostream>
#include<stack>
#include<cstdio>

using namespace std;

const int MAXN = 200005;

int n, k, curr;
int l[MAXN];
stack <int> s;

int main () {
	cin >> n >> k;
	for (int i=0; i<k; i++) {
		scanf("%d", &l[i]);
		if (!s.empty() && s.top()<l[i]) {
			cout << -1;
			return 0;
		}
		s.push(l[i]);
		while (!s.empty() && s.top()==curr+1) {
			curr++;
			s.pop();
		}
	}
	for (int i=0; i<k; i++) {
		printf("%d ", l[i]);
	}
	while (!s.empty()) {
		for (int i=s.top()-1; i>curr; i--) {
			printf("%d ", i);
		}
		curr=s.top()-1;
		while (!s.empty() && s.top()==curr+1) {
			curr++;
			s.pop();
		}
	}
	for (int i=n; i>curr; i--) {
		printf("%d ", i);
	}
	return 0;
}