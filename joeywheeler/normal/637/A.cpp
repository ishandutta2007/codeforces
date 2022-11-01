#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int b = 0, bi = -1;
map<int,int> r;

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int x;
        scanf("%d", &x);
        r[x]++;
        if (r[x] > b) {
            b = r[x];
            bi = x;
        }
    }
    printf("%d\n", bi);
}