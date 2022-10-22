#include <bits/stdc++.h>
#define m(x,y) (a[x]>a[y]?x:y)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int a[10000];
vector<int> ans;
int main() {
	string s;
	bool b = 0;
	cin >> s;
	int i,n=s.size();
	for (i = 0; i < n - 1; i++) {
		if ((!b) && s[i + 1] == 'a')a[i] = 1, b = 1;
		if (b&&s[i + 1] == 'b')a[i] = 1, b = 0;
	}
	if (b)a[i] = 1;
	for (i = 0; i < n; i++)printf("%d ", a[i]);
	getchar(); getchar();
}