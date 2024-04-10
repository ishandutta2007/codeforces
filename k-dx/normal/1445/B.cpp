#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n;

int main () {
	int ttt;
	scanf("%d", &ttt);
	while (ttt--) {
        int a, b, c, d;
        vector<int> t;
		scanf("%d %d %d %d", &a, &b, &c, &d);

        for (int i = 0; i < 50; i++) {
            t.push_back(a+c);
        }
        for (int i = 0; i < 50; i++) {
            t.push_back(a+b);
        }
        for (int i = 0; i < 50; i++) {
            t.push_back(c+d);
        }

        sort(t.rbegin(), t.rend());

		printf("%d\n", t[99]);
		
	}
	return 0;
}