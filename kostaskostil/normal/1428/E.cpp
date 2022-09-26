#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax=500500;
typedef long long ll;
#define int ll

int f(int a, int k)
{
    return k*(a/k)*(a/k) + (a%k) * (2*(a/k) + 1);
}

int pl(int a, int k)
{
    return f(a, k) - f(a, k+1);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> v(n, 1);
    set<pair<int, int> > st;
    for (int& i:a)
        cin>>i;
    for (int i=0; i<n; i++)
        st.insert({pl(a[i], v[i]), i});
    for (int i=0; i<k-n; i++)
    {
        auto pa=*prev(st.end());
        int x=pa.se;
        st.erase({pl(a[x], v[x]), x});
        v[x]++;
        st.insert({pl(a[x], v[x]), x});
    }
    int ans=0;
    for (int i=0; i<n; i++)
        ans+=f(a[i], v[i]);
    cout<<ans<<"\n";
//    for (int i:v)
//        cout<<i<<" ";

}