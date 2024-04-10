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
        int k = 0, l = s[0];
        for(auto x: s){
            if(x==l)k++;
            else {
                l = x;
                v.pb(k);
                k=1;
            }
        }
        v.pb(k);
        int ans = v.size(), lc= ans;
        vi vv((int)v.size(),0);
        for(int i = v.size()-1; i>=0; i--){
            if(i < v.size()-1) vv[i] = vv[i+1];
            vv[i]+=v[i]-1;
        }
        for(int i = 0; i < v.size(); i++){
            lc = min(vv[i],lc);
            if(lc)lc--;
            else if(i!=v.size()-1){ans--;i++;}
        }
        cout << ans << "\n";
    }

    return 0;
}