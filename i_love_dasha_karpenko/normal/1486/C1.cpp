#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
//#define endl '\n'
#define exp fgfdgd
const ll DIM = 1E5+7;
const ll INF = 1E18;
ll ask(ll l,ll r){
    cout<<"? "<<l<<' '<<r<<endl;
    ll ret;
    cin>>ret;
    return ret;
}

int main()
{

    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll pos = ask(1,n);
    if (pos!=1 && ask(1,pos)==pos){
        ll l = 1,r = pos-1;
        while(l!=r){
            ll tm = (l+r+1)/2;
            if (ask(tm,pos)==pos)l = tm;
            else r = tm-1;
        }
        cout<<"! "<<l<<endl;
    }
    else{
        ll l = pos+1,r = n;
        while(l!=r){
            ll tm = (l+r)/2;
            if (ask(pos,tm)==pos)r = tm;
            else l = tm+1;
        }
        cout<<"! "<<l<<endl;
    }
    return 0;
}