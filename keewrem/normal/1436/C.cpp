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
ll N,K,pos;

int main(){
    cin >> N >> K >> pos;
    int sopra = 0,sotto = 0;
    int ub = N, lb = 0, mid;
    while(lb < ub){
        mid = (ub+lb)/2;
        if(mid <= pos){
            lb = mid+1;
            if(mid < pos)sotto++;
        }else{
            ub = mid;
            sopra++;
        }
    }
//    cout << "sotto "<<sotto << " "<<sopra <<"\n";
    ll mod = 1000000007;
    ll ans = 1;
    for(ll i = 0; i < sotto; i++){
        ans*=(K-1-i);
        ans%=mod;
    }
    for(ll i = 0; i < sopra; i++){
        ans*=(N-K-i);
        ans%=mod;
    }
    for(ll i = 2; i < N-sopra-sotto; i++){ans*=i; ans%=mod;}

    cout << ans << "\n";
    return 0;
}