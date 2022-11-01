#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

bool p[20005];
int a, b, c;

int main() {
    scanf("%d%d%d", &a, &b, &c);
    p[0] = true;
    FO(i,0,c+1) {
        if (p[i]) {
            p[i+a] = true;
            p[i+b] = true;
        }
    }
    if (p[c]) printf("Yes\n");
    else printf("No\n");
}