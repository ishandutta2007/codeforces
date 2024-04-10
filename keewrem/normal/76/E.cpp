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

int T = 1;
ll N;

int main(){
    //cin >> T;
    cin >> N;
    vll x(N);
    vll y(N);
    for(int i = 0; i < N; i++)cin >> x[i] >> y[i];
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    ll ans = 0, s = 0, k = 0;
    for(int i = 1; i < N; i++){
        k+=i*(x[i]-x[i-1])*(x[i]-x[i-1])+2*(s*(x[i]-x[i-1]));
        s+=(x[i]-x[i-1])*i;
        ans+=k;
    }
    s = 0; k = 0;
    for(int i = 1; i < N; i++){
        k+=i*(y[i]-y[i-1])*(y[i]-y[i-1])+2*(s*(y[i]-y[i-1]));
        s+=(y[i]-y[i-1])*i;
        ans+=k;
    }
    cout << ans <<"\n";
    return 0;
}