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

int N,K,a;
vi sas;

int c[200010];
int main(){
    cin >> N >> K;
    for(int i = 0 ; i < N; i++){
        cin >> a; sas.pb(a);
    }
    for(int i = 1; i <= K; i++){
        cin >> c[i]; if(i > 1)c[i] = min(c[i],c[i-1]);
    }
    sort(sas.begin(),sas.end()); reverse(sas.begin(),sas.end());
    int cnt = 0; int ans = 1;
    for(auto x: sas){
        cnt++; ans = max(ans,((cnt-1)/c[x])+1);
    }
    cout << ans << "\n";
    vi kek;
    for(int i = 0; i < ans; i++){
        for(int j = i; j < N; j+= ans){
            kek.pb(sas[j]);
        }
        cout << kek.size();
        for(auto x: kek)cout << " " << x;
        cout << "\n";
        kek.clear();
    }
    return 0;
}