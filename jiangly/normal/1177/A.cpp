#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll k;
    cin>>k;
    int c=1;
    ll d=9;
    while(k>d*c){
        k-=d*c;
        ++c;
        d*=10;
    }
    d/=9;
    d+=(k-1)/c;
    k=c-(k-1)%c;
    while(--k){
        d/=10;
    }
    cout<<d%10<<endl;
    return 0;
}