#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> x[3];
    FO(i,0,n) {
        int y; scanf("%d", &y);
        x[y-1].push_back(i+1);
    }
    printf("%d\n", min(sz(x[0]),min(sz(x[1]),sz(x[2]))));
    FO(i,0,min(sz(x[0]),min(sz(x[1]),sz(x[2])))) {
        printf("%d %d %d\n", x[0][i], x[1][i], x[2][i]);
    }
}