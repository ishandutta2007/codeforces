#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int n; scanf("%d", &n);

    if (n%2) printf("%d\n", (n-1)/2);
    else {
    	n = n/2 - 1;
    	int l = 1;
    	while (n >= l) {
    		n -= l;
    		l *= 2;
    	}
    	printf("%d\n", n);
    }

    return 0;
}