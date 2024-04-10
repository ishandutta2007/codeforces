#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
const ll DIM = 100007;
const ll INF = 10000000007;
const ll MOD = ll(1000000007) ;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 Artem
#define y1 Pidor
const ll LOG = 9;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> my_super_set;

ll pref[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    ll cntu = 0,cntw = 0,res = 1,r1 = 1;
    pref[0] = pref[1] = 1;
    if (s[0]=='w' || s[0]=='m'){
        cout<<"0\n";
        return 0;
    }
    for(ll i = 1;i<s.length();i++){
            if (s[i]=='w' || s[i]=='m'){
                cout<<"0\n";
                return 0;
            }
            ll rot = res;
        if (s[i-1]==s[i]){
            if(s[i]=='u'){
                rot = (res+r1)%MOD;
            }
            else if (s[i]=='n'){
                rot = (res+r1)%MOD;
            }

        }
        r1 = res;
        res = rot;

    }
    cout<<res%MOD<<endl;
    return 0;
}