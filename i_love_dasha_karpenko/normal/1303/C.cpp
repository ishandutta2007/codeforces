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
#define po(x) (1ll<<x)
const ll DIM = 3*10E4+7;
const ll INF = 10E17;

ll cnt[30][30],ans[30],fl[30],ps[30];
ll gi (char ch){
    return ch-'a'+1;
}
deque<ll> Q;
deque<ll> q1;
ll add(ll x,ll val){
    ll el = -1;
    forn(i,29){
        if (cnt[x][i]==1){

            cnt[x][i] = 0;
            cnt[i][x] = 0;
            if (fl[i]==0){
                el = i;
                break;
            }
        }
    }

    if (el==-1)return 0;

    fl[el] = 1;
    if (val==1)q1.push_back(el);
    else q1.push_front(el);
    return 1;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    forn(qe,t){

        while(!Q.empty()){
            Q.pop_front();
        }
        string s;
        cin>>s;
        forn(i,29)forn(j,29){
            cnt[i][j] = 0;
            fl[i] = 0;
        }
        for(ll i = 1;i<s.length();i++){
            cnt[gi(s[i])][gi(s[i-1])] = 1;
            cnt[gi(s[i-1])][gi(s[i])] = 1;
        }

        forn(i,26){
            if(fl[i]==0){

                fl[i] = 1;
                q1.push_back(i);
                while(1){
                    if (!add(q1.back(),1))break;
                }
                while(1){
                    if (!add(q1.front(),0))break;
                }
                while(!q1.empty()){
                    Q.push_back(q1.front());
                    q1.pop_front();
                }
            }
        }
        string s1= "";
        //cout<<Q.size()<<endl;
        while(!Q.empty()){
            s1+=char(Q.front())+'a'-1;
            ps[gi(s1[s1.length()-1])] = s1.length()-1;
            Q.pop_front();
        }
       // cout<<s1.length()<<endl;
        ll flag = 0;
        forn(i,29){
            forn(j,29){
                if (cnt[i][j]==1){
                    flag = 1;
                    break;
                }
            }
        }
        for(ll i = 0;i<s.length()-1;i++){
            ll p = ps[gi(s[i])];
            ll next = gi(s[i+1]);
            ll ff = 0;
            if (p<s1.length() && s1[p+1]==s[i+1])ff = 1;
            if (p>0 && s1[p-1]==s[i+1])ff = 1;
            if (ff==0){
                flag = 1;
                break;
            }
        }
        //cout<<s1.length()<<endl;
        if (s1.length()!=26 || flag==1 ){
            cout<<"NO\n";
        }
        else
        cout<<"YES\n"<<s1<<endl;
    }
    return 0;
}