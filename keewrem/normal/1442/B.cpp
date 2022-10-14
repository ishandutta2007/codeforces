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
ll N,K;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        ll ans = 1;
        vi v(N);
        vi b(K);
        vi t(N,0);
        for(auto &x: v){cin >> x;x--;}
        for(auto &x: b){cin >> x; x--;}
        for(int i = 0; i < K; i++){
            t[b[i]]=i+1;
        }
        ll a= 0;
        for(int i = 1; i < N-1; i++){
            a = 0;
            if(t[v[i]]==0)continue;
            if(t[v[i]]>t[v[i-1]])a++;
            if(t[v[i]]>t[v[i+1]])a++;
            ans*=a; ans%=998244353LL;

        }
        if(t[v[0]]>0 && t[v[0]]<t[v[1]])ans=0LL;
        if(t[v[N-1]]>0 && t[v[N-1]]<t[v[N-2]])ans=0LL;
        cout << ans << "\n";
    }
    return 0;
}