#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pp;
const ll DIM = 10E5+7;
const ll INF = 10E18+173;

string getpos(ll l,ll r,string s){
    string s1="";
    for(ll i = l;i<=r;i++)s1+=s[i];
    return s1;
}
ll gi(char ch){
    return ch-'A';
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        string s; cin>>s;
        string c; cin>>c;
        ll pref = INF,ind = -1;
        for(ll i = s.length()-1;i>=0;i--){
            pref = min(pref,gi(s[i]));
            if (pref<gi(s[i])){
                ind = i;
            }
        }
        if (ind!=-1){
            pp mi = {INF,0};
            for(ll i = ind+1;i<s.length();i++){
                if (gi(s[i])<=mi.fi){
                    mi.fi = gi(s[i]);
                    mi.sc = i;
                }
            }

            swap(s[ind],s[mi.sc]);
        }
        if (s<c){
            cout<<s<<endl;
        }
        else{
            cout<<"---"<<endl;
        }
    }
    return 0;
}
// 5 4 1 2 3 4 5 2 1 3