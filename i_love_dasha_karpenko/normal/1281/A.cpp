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
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        string s; cin>>s;
        //cout<<getpos(s.length()-1,s.length()-1,s)<<endl;
        if (s.length()>=5 && getpos(s.length()-5,s.length()-1,s)=="mnida"){
            cout<<"KOREAN\n";
        }
        else if (s.length()>=4 && getpos(s.length()-4,s.length()-1,s)=="desu" || getpos(s.length()-4,s.length()-1,s)=="masu"){
            cout<<"JAPANESE\n";
        }
        else{
            cout<<"FILIPINO\n";
        }
    }
    return 0;
}
// 5 4 1 2 3 4 5 2 1 3