#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
const int nmax=5e5+100;
typedef long long ll;
#define int ll

int n;
int a[nmax];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int t_=0; t_<t; t_++){
        cin>>n;
        int s=0, x=0;
        for (int i=1; i<=n; i++)
            cin>>a[i], s+=a[i], x^=a[i];
        cout<<2<<"\n"<<s+x<<" "<<x<<"\n";
    }



    return 0;
}