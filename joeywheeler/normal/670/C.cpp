#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
map<int,int> a;
int m;
pair<int,int> b[200005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int x; scanf("%d", &x);
        a[x]++;
    }
    scanf("%d", &m);
    FO(i,0,m) {
        int x; scanf("%d", &x);
        b[i].first = a[x];
    }
    FO(i,0,m) {
        int x; scanf("%d", &x);
        b[i].second = a[x];
    }
    int mx = 0;
    FO(i,1,m) if (b[i] > b[mx]) mx = i;
    printf("%d\n", mx+1);
}