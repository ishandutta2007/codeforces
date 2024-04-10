#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 dsfdsf
#define y1 fgdfgdfg
const ll DIM = 400000+7;
const ll INF = 10e16;
const ll MOD = 998244353;
void ne(){
    cout<<"NO\n";
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    deque<ll> ans;
    if (a>=b){
        while(b>0){
            ans.pb(0);
            a--;
            ans.pb(1);
            b--;
        }
        if (a>0){
            ans.pb(0);
            a--;
        }

    }
    else{
        while(a>0){
            ans.pb(1);
            b--;
            ans.pb(0);
            a--;
        }
        if (b>0){
            ans.pb(1);
            b--;
        }
    }
    if (b==c && b!=0){
        if (d>0)ne();
        if (!ans.empty()  && ans.back()==0)ne();
        while(b>0){
            ans.pb(2);
            ans.pb(1);
            b--;
            c--;
        }
    }
    else{
        while(b>0){
            if (!ans.empty() && ans.back()==0)ne();
            ans.pb(2);
            ans.pb(1);
            b--;
            c--;
        }
        if (d>c){
            if (d>c+1)ne();
            if (!ans.empty())ne();
            while(c>0){
                ans.pb(3);
                ans.pb(2);
                c--;
                d--;
            }
            ans.pb(3);
            d--;
        }
        else{

            while(d>0){
                if (!ans.empty() && ans.back()==0)ne();
                ans.pb(2);
                ans.pb(3);
                d--;
                c--;
            }
            if (c>0){
                if (!ans.empty() && ans.back()==0)ne();
                ans.pb(2);
                c--;
            }
        }
    }
    if (c>0){
        if (ans.empty() || ans.front()==1){ans.push_front(2);c--;}
        else ne();
    }
    if (a>0 || b>0 || c>0 || d>0)ne();
    cout<<"YES\n";
    while(!ans.empty()){
        cout<<ans.front()<<' ';
        ans.pop_front();
    }
    cout<<endl;
    return 0;

}
// 0 1 2 3
// 0 1 -> 0 1 2 1 0
// 1 2 -> 1 2 3 2 1
// 2 3 -> 2 3 2 1 2 3