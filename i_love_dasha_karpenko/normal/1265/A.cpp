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
const ll DIM = 107+7;
const ll INF = 10e16;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        string s; cin>>s;
        ll n = s.length(),flag = 0;
        vector<ll> V;
        for(ll i = 0;i<n;i++){
            if (i!=n-1 && s[i]!='?' && s[i]==s[i+1]){
                flag = 1;
                break;
            }
        }
        if (flag==1){
            cout<<"-1\n";
            continue;
        }
        //string res = s;
        if (n==1 && s[0]=='?')s[0] = 'a';
        for(ll i = 0;i<n;i++){
            if (s[i]=='?'){
                if (i+1==n || s[i+1]=='?'){
                    if (i==0)s[i] = 'a';
                    else if (s[i-1]=='a')s[i] = 'b';
                    else if (s[i-1]=='b')s[i] = 'a';
                    else s[i] = 'a';
                }

                else{
                    if (i==0){
                        if (i==n-1 || s[i+1]=='b')s[i] = 'a';
                        else s[i] = 'b';
                    }
                    else{
                        if (s[i-1]==s[i+1]){
                            if (s[i-1]=='b')s[i] = 'a';
                            else s[i] = 'b';
                        }
                        else{
                            char ch = 'a'+'b'+'c'-s[i-1]-s[i+1];
                            s[i] = ch;
                        }
                    }
                }
            }
        }
        cout<<s<<endl;
    }

    return 0;

}