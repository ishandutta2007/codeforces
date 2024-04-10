#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;

pair<int,int> tf(pair<int,int> p) {
    int y = p.first/1000;
    int x = p.second;
    if (y&1) x *= -1;
    return make_pair(y,x);
}

pair<pair<int,int>,int> v[1000005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        v[i].second = i+1;
        scanf("%d%d", &v[i].first.first, &v[i].first.second);
        v[i].first = tf(v[i].first);
    }
    sort(v,v+n);
    FO(i,0,n) printf("%d%c", v[i].second, " \n"[i+1==n]);
}