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
ll N,M;
ll sas[101][101];
int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 0; i < N; i++)for(int j = 0; j < M; j++)cin >> sas[i][j];
        vll v;
        ll ans = 0;
        for(int i = 0; i < N; i++)for(int j = 0; j < M; j++){
            v.clear();
            v.pb(sas[i][j]);
            v.pb(sas[i][M-j-1]);
            v.pb(sas[N-i-1][M-j-1]);
            v.pb(sas[N-i-1][j]);
            sort(v.begin(),v.end());
            ll k = 0;
            for(auto x: v)k+=abs(x-v[2]);
            if(2*i+1==N || 2*j+1==M)ans += k/2;
            else ans+=k;
            sas[i][j]=0;
            sas[i][M-j-1]=0;
            sas[N-i-1][M-j-1]=0;
            sas[N-i-1][j]=0;
            //cout << ans << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}