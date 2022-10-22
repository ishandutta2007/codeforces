#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
void work(){
    int n,mi=10;
    cin>>n;
    if(n<100){
        cout<<n%10<<endl;
    }
    else{
        int x=n;
        while(x){
            mi=min(mi,x%10);
            x/=10;
        }
        cout<<mi<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}