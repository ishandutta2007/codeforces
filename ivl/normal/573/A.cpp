#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector < int > v;
    REP(n,i){
        int x;
        scanf("%d", &x);
        while (x%2 == 0) x /= 2;
        while (x%3 == 0) x /= 3;
        v.pb(x);
    } sort(v.begin(), v.end());
    if (v.front() == v.back()) printf("Yes\n");
    else printf("No\n");
    return 0;
}