#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=5e5+100;
#define int long long

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++){
        int n, k;
        cin>>n>>k;
        int a=0;
        a+= n*((k-1)/(n-1)) + ((k-1)%(n-1)) + 1;
        cout<<a<<"\n";
    }

    return 0;
}