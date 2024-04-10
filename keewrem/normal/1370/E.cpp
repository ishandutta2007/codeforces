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
string a,b;
int main(){
    ll c = 0;

    cin >> N;
    cin >> a >> b;
    for(auto x: a)c+=(x-'0');
    for(auto x: b)c-=(x-'0');
    if(c!=0){cout << "-1"; return 0;}
    vi v;
    for(int i = 0; i < N; i++){
        if(a[i]!=b[i])v.pb(a[i]);
    }
    int b = 0, m = 0;
    int p  =0, pm = 0;
    for(auto x: v){
        if(x == '0')b++;
        else b--;
        pm = min(pm,b); p = max(b,p);
        m = max(m,max(b-pm,p-b));

    }

    cout << m << "\n";
    return 0;
}