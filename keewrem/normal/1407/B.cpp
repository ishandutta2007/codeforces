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
        vi v(N);
        for(auto &x: v)cin >> x;
        sort(v.begin(),v.end());
        vi ans(N);
        int p = 0;
        for(auto &y: ans){
            int mx = 0, mi = 0;
            for(int i = 0; i < N; i++){
                if(v[i] == -1)continue;
                if(__gcd(v[i],p)> mx){
                    mx = __gcd(v[i],p);
                    mi = i;
                }
            }
            y = v[mi];
            v[mi] =-1;
            p = mx;
        }
        for(auto x: ans)cout << x << " ";
        cout << "\n";
    }
    return 0;
}