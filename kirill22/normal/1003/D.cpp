#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q,b;
    cin >> n >> q;
    array<int, 31> cnt={};
    for(int i=0; i<n; ++i) {
            int a;
            cin >> a;
            ++cnt[ilogb(a)];
    }
    while (q--) {
        cin >> b;
        int res=0;
        for(int i=30; i>=0; --i) if (cnt[i]) {
            int t=min(b/(1<<i), cnt[i]);
            b-=t*(1<<i);
            res+=t;
        }
        printf("%d\n", b ? -1 : res);
    }
}