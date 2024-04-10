#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, a[100005], res[100005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", a+i);
    int mx = -1;
    for (int i = n-1; i >= 0; i--) {
        int r = max(a[i],mx+1);
        res[i] = r-a[i];
        mx = max(mx,a[i]);
    }
    FO(i,0,n) printf("%d%c", res[i], " \n"[i+1==n]);
}