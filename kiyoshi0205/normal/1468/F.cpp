#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
int gcd(int a,int b){
    if(!b)return abs(a);
    return (a%b)?gcd(b,a%b):abs(b);
}

using P=pair<int,int>;
int main(){
    int T;
    cin>>T;
    while(T--){
        int N,a,b,c,d;cin>>N;
        vector<P> v(N);
        map<P,int> mp;
        rep(i,N){
            cin>>a>>b>>c>>d;
            c-=a;
            d-=b;
            if(!c){
                v[i]=P(0,d/abs(d));
            }else if(!d){
                v[i]=P(c/abs(c),0);
            }else{
                a=gcd(c,d);
                v[i]=P(c/a,d/a);
            }
            mp[v[i]]++;
        }
        long long ans=0;
        rep(i,N){
            v[i].first*=-1;
            v[i].second*=-1;
            ans+=mp[v[i]];
        }
        cout<<ans/2<<"\n";
    }
}