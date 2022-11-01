#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int m[3000005];
bool e[3000005];
int n;

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int x; scanf("%d", &x); e[x]=1; m[x]=x;
    }
    FO(i,1,3000005) m[i] = max(m[i],m[i-1]);
    int res = 0;
    FO(i,2,3000005) if (e[i]) {
        for (int j = i; j < 3000005; j += i) {
            if (m[j-1] >= i) res = max(res, m[j-1]%i);
        }
    }
    printf("%d\n", res);
}