#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int main(void) {
    set<int> s;
    int n;
    scanf("%d",&n);
    REP(i,n) s.insert(i+1);
    REP(i,n-1) {
        int v;
        scanf("%d",&v);
        assert(s.erase(v));
    }
    assert(s.size()==1);
    printf("%d",*s.begin());
    return 0;
}