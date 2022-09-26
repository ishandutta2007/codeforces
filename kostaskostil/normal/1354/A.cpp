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

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        if (a<=b){
            cout<<b<<"\n";
            continue;
        }
        a-=b;
        if (c<=d){
            cout<<-1<<"\n";
            continue;
        }
        if (a%(c-d) == 0)
            cout<<b + a/(c-d)*c<<"\n";
        else
            cout<<b + a/(c-d)*c+c<<"\n";
    }

    return 0;
}