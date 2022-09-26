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
        double R = 0.5 / sin(3.1415926536 / 2/n);
        double alpha = 3.1415926536 * (n/2) / n;
        double beta = (3.1415926536/2 - alpha)/2;
        cout << 2*R*cos(beta) <<"\n";
    }

    return 0;
}