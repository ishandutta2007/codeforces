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
int gcd(int a, int b){
    if(a == 0)return b;
    else return gcd(b%a,a);
}
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        vi v(N);
        for(auto &x: v)cin >> x;
        int mm = 1000000000,gd=0;
        for(auto x: v)mm = min(x,mm);
        vi r = v;
        bool ans = 1;
        sort(r.begin(),r.end());
        for(int i = 0; i < N; i++){
            if(v[i]%mm == 0)gd = gcd(gd,v[i]);
            if(v[i]==r[i])continue;
            if(v[i]%mm)ans = 0;
        }
        if(gd!=mm && gd > 0)ans = 0;
        if(ans)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}