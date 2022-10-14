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
const int MN = 100002;

ll seg[262144];
ll v[262144];
ll p[262144];
ll k,kk;
ll vl,c,sq;
void upd(int pos){
    p[pos]++;
    pos+=131072;
    pos/=2;
    while(pos>0){
        c= p[seg[2*pos]]+1;vl = v[seg[2*pos]]; sq=vl/c;
        k=sq*sq*c+(vl%c)*(2*sq+1);
        c--; sq=vl/c;
        k-=sq*sq*c+(vl%c)*(2*sq+1);
        c= p[seg[2*pos+1]]+1;vl = v[seg[2*pos+1]]; sq=vl/c;
        kk=sq*sq*c+(vl%c)*(2*sq+1);
        c--; sq=vl/c;
        kk-=sq*sq*c+(vl%c)*(2*sq+1);
        if(k < kk)seg[pos]=seg[2*pos];
        else seg[pos]=seg[2*pos+1];
        pos/=2;
    }
}

int T;
ll N,K;

int main(){
    cin >> N>>K;
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    for(int i=0; i < 131072; i++){p[i]=1;seg[i+131072]=i;}
    for(int pos = 131071; pos>0;pos--){
        c= p[seg[2*pos]]+1;vl = v[seg[2*pos]]; sq=vl/c;
        k=sq*sq*c+(vl%c)*(2*sq+1);
        c--; sq=vl/c;
        k-=sq*sq*c+(vl%c)*(2*sq+1);
        c= p[seg[2*pos+1]]+1;vl = v[seg[2*pos+1]]; sq=vl/c;
        kk=sq*sq*c+(vl%c)*(2*sq+1);
        c--; sq=vl/c;
        kk-=sq*sq*c+(vl%c)*(2*sq+1);
        if(k < kk)seg[pos]=seg[2*pos];
        else seg[pos]=seg[2*pos+1];
    }
    K-=N;
    while(K--){
    //    cout << "upd "<<seg[1]<<"\n";
        upd(seg[1]);
    }
    ll ans = 0;

    for(int i = 0;i < N; i++){
        c= p[i];vl = v[i]; sq=vl/c;
        ans+=sq*sq*c+(vl%c)*(2*sq+1);
    }
    cout << ans<<"\n";
    return 0;
}