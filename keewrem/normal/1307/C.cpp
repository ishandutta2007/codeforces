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
ll kek[100010][30];
ll sus[30][30];
int main(){
    string s; cin >> s;
    ll ans = 0;
    N = (ll)s.size();
    for(auto &x: s)x-='a';
    for(int i = N-1; i>=0; i--){
        for(int j = 0; j < 30; j++){
            kek[i][j]=kek[i+1][j];
            if((int)s[i]==j)kek[i][j]++;
            ans=max(ans,kek[i][j]);
        }
    }

    for(int i = 0; i < N;i++){
        for(int j = 0; j < 30; j++){
            sus[(int)s[i]][j]+=kek[i+1][j];
        }
    }
    for(int i = 0; i < 30; i++)for(int j = 0; j < 30; j++)ans = max(ans,sus[i][j]);
    cout << ans << "\n";
    return 0;
}