#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
const int nmax=2e5+100;
typedef long long ll;
//#define int ll

ll ans=0;
int n;
int cmax=0;
int a[nmax];
int p[nmax];

void add(int c){
    unordered_map<int, int> um;
    for (int i=0; i<=n; i++)
        um[p[i]*c-i]++;
    for (auto pa:um)
        ans+=ll(pa.se)*(pa.se-1)/2;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    n=s.size();
    for (int i=1; i<=n; i++)
        a[i]=(s[i-1]=='1');
    for (int i=1; i<=n; i++)
        p[i]=p[i-1]+a[i];
    for (int i=1; i<=n; i++)
    {
        cmax=i;
        add(cmax);
        if (clock()*1.0/CLOCKS_PER_SEC > 1.0)
            break;
    }
    vector<int> ones;
    for (int i=1; i<=n; i++)
        if (a[i]==1)
            ones.pb(i);
    for (int i=0; i<int(ones.size()); i++)
        for (int j=i; j<int(ones.size()) and ll(j-i+1)*ll(cmax+1)<=n; j++){
            int all=ones[j]-ones[i]+1;
            int lt, rt;
            if (i==0) lt=ones[i]-1;
            else lt=ones[i]-ones[i-1]-1;
            if (j==int(ones.size())-1) rt=n-ones[j];
            else rt=ones[j+1]-ones[j]-1;
            int o=j-i+1;

            int left_border=max(cmax+1, (all+o-1)/o);
            int right_border=(all+lt+rt)/o;
            for (int so=left_border; so <= right_border; so++)
            {
                int kt=so*o-all;
                ans+=kt+1-max(0, kt-lt)-max(0, kt-rt);
            }
    }

    cout<<ans<<"\n";
    return 0;
}