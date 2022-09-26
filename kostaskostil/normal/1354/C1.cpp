#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=5e5+100;
typedef long long ll;
#define int ll

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout<<fixed<<setprecision(10);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++){
        int n;
        cin>>n;
        cout<<1.0/tan(3.141592653589/2/n)<<"\n";
    }

    return 0;
}