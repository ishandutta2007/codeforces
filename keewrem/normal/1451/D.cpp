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
ll N,K,d;

int main(){
    cin >> T;
    while(T--){
        cin >> d >> K;

        ll ans = 0;
        for(ll i = 1024*1024; i > 0; i/=2){
            if(K*i>100005)continue;
            if(2LL*K*K*(ans+i)*(ans+i)<=d*d)ans+=i;
        }
        //cout << ans <<"\n";
        if((ans*K+K)*(ans*K+K)+ans*ans*K*K>d*d)cout <<"Utkarsh\n";
        else cout << "Ashish\n";
    }
    return 0;
}