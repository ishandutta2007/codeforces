#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int kpow(int x,int y,int rex=0){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
int n;
vector<pii>ot;
void put(int x,int y) {
    ot.push_back(pii(x,y));
}
int main() {
    cin>>n;
    int ans=n/3*2;
    int x=(ans+1)/2;
    if(n%3!=0) ans++;
    for(int i=1;i<=x;i++) put(i,x-i+1);
    if(n%3!=0) {
        for(int i=1;i<=ans-x;i++) {
            put(x+i,ans-i+1);
        }
    } else {
        for(int i=1;i<ans-x;i++) {
            put(x+i,ans-i);
        }
        put(x+x,x+x);
    }
    cout<<ot.size()<<endl;
    for(auto x:ot) printf("%d %d\n",x.first,x.second);
    return 0;
}