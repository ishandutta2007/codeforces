#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int s[100005];
int d[100005];
int n;

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", &s[i]);
    FO(i,0,n-1) d[i] = s[i+1] >= s[i];
    int res = 1;
    for (int i = 0; i < n;) {
        int j;
        for (j = i; j < n && d[j]; j++);
        res = max(res,j-i+1);
        i = j+1;
    }
    printf("%d\n", res);
}