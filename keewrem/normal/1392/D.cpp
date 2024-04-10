#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll N;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        string s;
        cin >> s;
        vi v;
        int l = s[0];
        int c = 0;
        for(auto x: s){
            if(x == l)c++;
            else {v.pb(c); c = 1; l = x;}
        }
        if(c){
            if(v.size()>1 && s[0]==s[N-1])v[0]+=c;
            else v.pb(c);
        }
        int ans = 0;
        //for(auto x: v)cout << x << " ";
        //cout << endl;
        if(v.size()==1)ans = (N+2)/3;
        else for(auto x: v){
            ans += x/3;
        }
        cout << ans << endl;
    }
    return 0;
}