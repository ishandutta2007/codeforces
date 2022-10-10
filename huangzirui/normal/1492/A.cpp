#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;cin>>T;
    while (T--) {
        long long p,a,b,c;
        cin>>p>>a>>b>>c;
        if (!(p%a) || !(p%b) || !(p%c))puts("0");
        else printf("%lld\n",min(a-p%a,min(b-p%b,c-p%c)));
    }
    return 0;
}