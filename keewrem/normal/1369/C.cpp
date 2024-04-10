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
        cin >> N>>K;
        vll v(N);
        for(int i = 0; i < N; i++)cin >> v[i];
        vi w(K);
        for(int i = 0; i < K; i++)cin >> w[i];
        ll r = 0;
        sort(v.rbegin(),v.rend()); sort(w.begin(),w.end());
        for(int i = 0; i < K; i++)r+=v[i];
        int q = K-1, qq = 0;
        //cout <<r <<"\n";
        for(auto x: w){
            if(x==1)r+=v[qq++];
            else {
                q+=x-1; r+=v[q];
            }
        }
        cout << r<<"\n";
    }
    return 0;
}