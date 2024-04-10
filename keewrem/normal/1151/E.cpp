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

int main(){
    cin >> N;
    vll v(N);
    for(int i = 0; i< N; i++)cin >> v[i];
    ll res = (v[0])*(N-v[0]+1);
    for(int i = 1; i < N; i++){
        if(v[i]<v[i-1])res+=v[i]*(v[i-1]-v[i]);
        else res+=(N+1-v[i])*(v[i]-v[i-1]);
    }
    cout << res;
    return 0;
}