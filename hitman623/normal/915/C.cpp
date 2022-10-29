#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define M 1000000007
#define sz(a) (ll)a.size()
#define pll pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define sep(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define mll map<ll,ll>
#define vl vector<ll>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define F first
#define S second
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
string a,b;
ll f[10],c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string ans;
    cin>>a>>b;
    if(sz(a)<sz(b))
    {
        vector<char> v;
        rep(i,0,sz(a))
        v.pb(a[i]);
        sort(all(v));
        reverse(all(v));
        for(auto i:v)
            cout<<i;
        cout<<"\n";
        return 0;
    }
    sep(i,sz(b),0)
    {
        ans="";
        rep(j,0,10)
        f[j]=0;
        rep(j,0,sz(a))
        f[a[j]-'0']++;
        rep(j,0,i)
        {
            if(f[b[j]-'0'])
            {
                ans+=b[j];
                f[b[j]-'0']--;   
            }
            else
            {
                ans="";
                break;
            }
        }
        if(i&&ans=="")
            continue;
        if(i==sz(b))
        {
            cout<<ans<<"\n";
            return 0;
        }
        if(b[i]=='0')
            continue;
        c=0;
        sep(j,(ll)(b[i]-'0')-1,0)
        {
            if(f[j])
            {
                ans+=(j+'0');
                f[j]--;
                c=1;
                break;
            }
        }
        if(c==0)
            continue;
        rep(j,i+1,sz(b))
        {
            sep(k,9,0)
            {
                if(f[k])
                {
                    ans+=(k+'0');
                    f[k]--;
                    break;
                }
            }
        }
        cout<<ans<<"\n";
        return 0;
    }
}