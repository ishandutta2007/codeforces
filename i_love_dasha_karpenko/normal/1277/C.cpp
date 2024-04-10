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

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        string s; cin>>s;
        ll n = s.length();
        ll cnt = 0;
        for(ll i = 0;i<n-2;i++){
            if (s[i]=='o' && s[i+1]=='n' && s[i+2]=='e'){
                s[i+1] = '#';
                cnt++;
            }
            if (s[i]=='t' && s[i+1]=='w' && s[i+2]=='o'){
                if (i+3<n && s[i+3]!='o')s[i+2] = '#';
                else s[i+1] = '#';
                cnt++;
            }
        }
        cout<<cnt<<endl;
        for(ll i = 0;i<n;i++){
            if (s[i]=='#')cout<<i+1<<' ';
        }
        cout<<endl;
    }
    return 0;
}
// 5 4 1 2 3 4 5 2 1 3