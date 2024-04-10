//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 100000+7;
const ll INF = 1E18;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        string sb;
        cin>>sb;
        vector<char> V = {'A','N','T','O'};
        vector<ll> ct;
        sort(V.begin(),V.end());
        ll res = 0;
        string ans = sb;
        do{
            vector<char> cp = V;
            string s = sb;
            ll sum = 0;
            while(!V.empty()){
                ll len = 0,cnt = 0;
                for(char to:s){
                    ++len;
                    if (to==V.back())
                        ++cnt;
                }
                string ns = "";
                ll pos = 0;
                ll cur = 0;
                for(char to:s){
                    ++pos;
                    if (to==V.back()) {
                        sum += max(0ll, (len - cnt + 1 + cur) - pos);
                        ++cur;
                    }
                    else ns+=to;
                }
                ct.push_back(cnt);
                s = ns;
                V.pop_back();
            }
            V = cp;
            s = "";
            reverse(ct.begin(),ct.end());
            for(ll i = 0;i<4;++i)
                for(ll j = 0;j<ct[i];++j)
                    s+=V[i];
            // cout<<s<<endl;
            if (sum>res){
                res = sum;

                ans = s;
            }
        }while(next_permutation(V.begin(),V.end()));

        cout<<ans<<endl;
    }
    return 0;
}