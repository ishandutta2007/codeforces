#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
typedef int ll;
typedef pair<ll,ll> pp;
const ll DIM = 200007+7;
const ll INF = 10E10;

int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    forn(q,n){
        string s; cin>>s;
        ll sum = 0,flag1 = 0,flag2 = 0;
        for(ll i = 0;i<s.length();i++){
            sum+=s[i]-'0';
            if (flag1==0 && s[i]=='0')flag1 = 1;
            else if ((s[i]-'0')%2==0)flag2 = 1;
        }
        if (sum%3==0 && flag1 && flag2)cout<<"red\n";
        else cout<<"cyan\n";
    }
    return 0;
}