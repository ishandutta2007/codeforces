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
const ll MOD = 1000000007;
ll n1[2000001];
ll n0[2000001];
ll n3[2000001];
ll ans[2000001];

int main(){
    cin >> T;
    n1[2]=1; n0[2]=1;
    for(int i = 3; i < 2000001; i++){
        n0[i]=(2*n1[i-1]+n0[i-1])%MOD;
        n1[i]=n0[i-1];
        n3[i]=n1[i-1];
        ans[i]=(4*(n3[i])+ans[i-3])%MOD;
    }


    while(T--){
        cin >> N;
        cout << ans[N]<<"\n";
    }
    return 0;
}