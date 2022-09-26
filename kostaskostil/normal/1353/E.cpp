#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=1e6+100;

typedef long long ll;
#define int ll

int a[nmax];
int pref[nmax];

int f(vector<int> v){
//    for (int i:v)
//        cout<<i<<" ";
//    cout<<"\n";
    int n=v.size();
    vector<int> pref(n, 0);
    vector<int> suf(n, 0);
    pref[0]=v[0];
    for (int i=1; i<n; i++)
        pref[i]=pref[i-1]+v[i];
    suf[n-1]=v[n-1];
    for (int i=n-2; i>=0; i--)
        suf[i]=suf[i+1]+v[i];
    vector<int> ans(n, 0);
    ans[0]=0;
    for (int i=1; i<n; i++)
    {
        if (v[i]==1)
            ans[i]=min(ans[i-1], pref[i]);
        else
            ans[i]=min(ans[i-1]+1, pref[i]);
    }
    vector<int> ans2(n, 0);
    ans2[n-1]=0;
    for (int i=n-2; i>=0; i--)
    {
        if (v[i]==1)
            ans2[i]=min(ans2[i+1], n-suf[i]);
        else
            ans2[i]=min(ans2[i+1]+1, suf[i]);
    }
//    for (int i=0; i<n; i++)
//        cout<<i<<": "<<ans[i]<<" "<<ans2[i]<<"\n";
    int answ=min(ans[n-1], ans2[0]);
    for (int i=0; i<n-1; i++)
        answ=min(answ, ans[i]+ans2[i+1]);
    return answ;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++){
        int n, k;
        cin>>n>>k;
        string s1;
        cin>>s1;
        for (int i=0; i<n; i++)
            a[i]=(s1[i]=='1');
        vector<int> sum(k, 0);
        for (int i=0; i<k; i++){
            for (int j=i; j<n; j+=k)
                sum[i]+=a[j];
        }
        int s=0;
        for (int i=0; i<k; i++)
            s+=sum[i];
        int ans=1e9;
        for (int i=0; i<k; i++){
//                cout<<i<<"th\n";
            vector<int> v;
            for (int j=i; j<n; j+=k)
                v.pb(a[j]);
            ans=min(ans, f(v)+s-sum[i]);
        }
        cout<<ans<<"\n";
    }

    return 0;
}