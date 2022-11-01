#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef pair<int,int> ii;

int n;
vector<ii> v;

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        ii a; scanf("%d %d", &a.first, &a.second);
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int ld = -1;
    FO(i,0,n) {
        if (v[i].second >= ld) ld = v[i].second;
        else ld = v[i].first;
    }
    printf("%d\n", ld);
}