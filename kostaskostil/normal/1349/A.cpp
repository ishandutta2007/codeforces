#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=5e5+100;
#define int long long

int a[nmax];
int n;

int ch(int p){
    vector<int> v;
    for (int i=1; i<=n; i++){
        int c=0;
        int q=a[i];
        while (q%p==0)
            q/=p, c++;
        v.pb(c);
    }
    partial_sort(v.begin(), v.begin()+2, v.end());
    int k=v[1];
    int r=1;
    for (int i=1; i<=k; i++)
        r*=p;
    return r;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i];

        int ans=1;
        int r=a[1]*a[2]/__gcd(a[1], a[2]);

    for (int i=2; i*i<=r; i++)
        if (r%i==0)
        {
            while (r%i==0)
                r/=i;
        ans*=ch(i);
    }
    if (r>1)
        ans*=ch(r);
    cout<<ans<<"\n";

    return 0;
}