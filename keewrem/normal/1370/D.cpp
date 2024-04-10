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
    cin >> N >> K;
    vi v(N);
    for(int i = 0; i < N; i++)cin>>v[i];
    ll ub = 1000000000, lb = 0,mid;
    while(lb <= ub){
        mid = (ub + lb)/2;
        ll c = 0; int f = -1, l;
        for(int i = 0; i < N; i++){
            if(f == -1 && v[i]<=mid)f = i;
            if(v[i]<=mid){c++; i++; l= i;}
        }
        bool k = 0;
        if(c>K/2)k = 1;
        if(K%2 == 0 && c >= K/2 && (l < N || f > 0))k = 1;
        if(K%2 == 1 && c >= K/2 && l < N && f > 0)k = 1;
        f = -1; c = 0;
        for(int i = 1; i < N; i++){
            if(f == -1 && v[i]<=mid)f = i;
            if(v[i]<=mid){c++; i++; l= i;}
        }
        if(c>K/2)k = 1;
        if(K%2 == 0 && c >= K/2 && (l < N || f > 0))k = 1;
        if(K%2 == 1 && c >= K/2 && l < N && f > 0)k = 1;
        if(k) ub = mid-1;
        else lb = mid+1;
        //cout << mid << " "<< f<< " " << l<<" " << c <<"\n";
    }
    cout << ub+1;
    return 0;
}