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

int N,a,K;
signed main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        vi v(N);
        for(auto &x : v)cin >> x;
        for(int i = 0; i < N; i++)cin >> a;
        vi kek(N);
        sort(v.begin(),v.end());
        int cnt = 0, st = 0;
        for(int i = 0; i < N; i++){
            cnt++; while(st < N && v[st]<v[i]-K){st++; cnt--;}
            kek[i]=cnt;
        }
        int best = 0, ans = 0;st = 0;
        for(int i = 0; i < N; i++){
            while(st < N && v[st]<v[i]-K){best=max(best,kek[st++]);}
            ans = max(ans, kek[i]+best);
        }
        cout << ans<<"\n";
    }
    return 0;
}