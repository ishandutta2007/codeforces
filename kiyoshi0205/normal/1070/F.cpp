#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;
#define rep(i,N) for(i=0;i<(ll)N;i++)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

template<class T>
void output(vector<T>& v){
    bool f=false;
for(auto i:v){
    if(f)cout<<" ";
    cout<<i;
    f=true;
}
cout<<endl;
}

//-------------------------------------
using P=pair<ll,ll>;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll i,n, k,ans=0,sum=0;
    cin >> n;
    string s;
    vector<ll> a,b,z;
    for(i = 0; i < n; i++) {
        cin >> s>>k;
        if(s[0]=='1'){
            if(s[1]=='1'){
                ans+=k;
                sum++;
            }else{
                a.push_back(k);
            }
        }else{
            if(s[1]=='1'){
                b.push_back(k);
            }else{
                z.push_back(k);
            }
        }
    }
    sort(RALL(a));
    sort(RALL(b));
    if(a.size()<b.size()){
        rep(i,a.size()){
            ans+=a[i]+b[i];
        }
        while(i<b.size()){
            z.push_back(b[i]);
            i++;
        }
    }else{
        rep(i,b.size()){
            ans+=a[i]+b[i];
        }
        while(i<a.size()){
            z.push_back(a[i]);
            i++;
        }
    }
    sort(RALL(z));
    rep(i,min(sum,(ll)z.size())){
        ans+=z[i];
    }
        cout<<ans;
}