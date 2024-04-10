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
        for(auto &x: v)cin >> x;
        sort(v.begin(),v.end());
        for(int i = 0; i < K; i++){
            if(N-2-i>=0)v[N-1]+=v[N-2-i];
        }
        cout << v[N-1]<<"\n";
    }
    return 0;
}