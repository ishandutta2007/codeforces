#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) ((unsigned long long)(1)<<x)
const ll DIM = 500+7;
const ll INF = 10E17;
ll cnt[30];
ll gi(char ch){
    return ch-'a'+1;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        for(char to:s){
            cnt[gi(to)]++;
        }
        ll flag = 0;
        ll st = 0;
        for(ll i = 1;i<=26;++i){
            if (cnt[i]!=0 && st==0)st = i;
            if (cnt[i]%k!=0){
                flag = 1;
                break;
            }
        }

            ll last = 0;
            forn(i,26){
                if (cnt[i]!=0)last = i;
            }
            if (st==last){
                forn(i,cnt[st]/k+(cnt[st]%k!=0))cout<<char(st+'a'-1);
                cout<<endl;
            }
            else if (cnt[st]==k && cnt[st]+cnt[last]==n){
                cout<<char(st+'a'-1);
                forn(i,cnt[last]/k+(cnt[last]%k!=0))cout<<char(last+'a'-1);
                cout<<endl;
            }
            else if (cnt[st]>=k){
                cnt[st]-=k-1;
                string ans = "";
                forn(i,26){
                    forn(j,cnt[i]){
                        ans+=char('a'+i-1);
                    }
                }
                cout<<ans<<endl;
            }
            else{
                ll ct = 0;
                forn(i,26){
                    ct+=cnt[i];
                    if (ct>=k){
                        cout<<char(i+'a'-1)<<endl;
                        break;
                    }
                }
            }

        forn(i,26)cnt[i] = 0;
    }
    return 0;
}