#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include<iostream>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
ll num1,num2,tmp,k,minn,ans=0;
ll t1,t2;
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
void ok(ll k){
    ll tmp=((num1+k)*(num2+k))/(gcd(num1+k,num2+k));
    if(minn>=tmp){
        if(minn==tmp&&k<ans)ans=k;
        ans=k;
        minn=tmp;
    }
}
int main(){
    cin>>num1>>num2;
    minn=num1*num2;
    tmp=abs(num1-num2);
    for(ll i=1;i*i<=tmp;i++){
        if(tmp%i==0){
            t1=i;
            t2=tmp/i;
            k=t1-(num1%t1);
            ok(k);
            k=t2-(num1%t2);
            ok(k);
        }
    }
    ok(0);
    cout<<ans<<endl;
    return 0;
}