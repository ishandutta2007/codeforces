#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int maxlen=195;
int str[205];

ll mo;
ll mul(ll a,ll b){
    ll ans=0;
    do{
        if(b&1){
            ans=ans+a;
            if(ans>=mo)ans-=mo;
        }
        a<<=1;
        if(a>=mo)a-=mo;
    }while(b>>=1);
    return ans;
}/*
ll mul(ll a,ll b){
    return ((a*b-ll((long double)a*b/mo)*mo)%mo+mo)%mo;
}*/
ll z;
void genrand(){
    str[maxlen]=rand()%9+1;
    str[1]=rand()%9+1;
    for (int i=2;i<maxlen;i++)str[i]=rand()%10;
}

ll t[205],T[205];
ll p10[205],P10[205];
ll f(int *a,int n){
    ll ans=0;
    ll suf=0;
    for (int i=1;i<=n;i++){
        ans=ans+mul(((a[i]-1)*a[i]/2),p10[i-1]);
        if(ans>=mo)ans-=mo;
        ans=ans+mul(a[i],suf);
        if(ans>=mo)ans-=mo;
        ans=ans+mul(a[i],t[i-1]);
        if(ans>=mo)ans-=mo;
        suf=suf+mul(p10[i-1],a[i]);if(suf>=mo)suf-=mo;
    }
    return ans;
}
ll f1(int *a,int n){
   ll ans=0;
    ll suf=0;
    for (int i=1;i<=n;i++){
        ans=ans+((a[i]-1)*a[i]/2)*P10[i-1];
        ans=ans+a[i]*suf;
        ans=ans+a[i]*T[i-1];
        suf=suf+P10[i-1]*a[i];
    }
    return ans;
}
int str2[100];
ll f2(ll x){
    int n=1;
    while(x){
        str2[n]=x%10;
        x/=10;
        n++;
    }
    n--;
    return f1(str2,n);
}

int main()
{
    cin>>mo;
    p10[0]=P10[0]=1;
    for (int i=1;i<=200;i++)p10[i]=mul(p10[i-1],10),P10[i]=P10[i-1]*10;
    for (int i=1;i<=200;i++){
        t[i]=mul(45*i,p10[i-1]);
        T[i]=45*i*P10[i-1];
    }   
    while(1){
        genrand();
        ll z=f(str,maxlen);
        ll l=0,r=ll(1e17),mid;
        ll fo=-1;
        while(l<=r){
                 mid=l+r>>1;
                 ll tmp=f2(mid);
                 if(tmp<z)l=mid+1;
                 else if(tmp==z){
                      fo=mid;
                      break;
                 }else r=mid-1;
        }
        if(fo!=-1){
                   str[1]--;
                   cout<<mid<<" ";
                   for (int i=maxlen;i>=1;i--)putchar(str[i]+'0');
                   printf("\n");
                   return 0;                   
        }
    }
}