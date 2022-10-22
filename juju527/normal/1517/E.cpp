#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5,mod=998244353;
int a[maxn];
ll pre[maxn],suf[maxn];
ll s0[maxn],s1[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){
    return x>=mod?x-mod:x;
}
ll suma=0;
bool check(ll v){return v<suma-v;}
int main(){
    int T;
    T=read();
    while(T--){
        int n,res=0;
        n=read();
        suma=0;
        ll sum=0;
        for(int i=1;i<=n;i++)a[i]=read(),suma+=a[i];
        // for(int i=0;i<(1<<4);i++){
        //     ll val=0;
        //     for(int j=0;j<4;j++)if(i&(1<<j))val+=a[j+1];
        //     cout<<i<<" "<<check(val)<<endl;
        // }
        for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
        suf[n+1]=0;
        for(int i=n;i>=1;i--)suf[i]=suf[i+1]+a[i];
        for(int i=1;i<=n;i++)s1[i]=s1[i-1]+((i&1)?a[i]:0),s0[i]=s0[i-1]+((i%2==0)?a[i]:0);
        for(int i=1;i<=n;i++)if(i&1)sum+=a[i];
        if(check(sum))res++;
        if(check(suma-sum))res++;
//        cout<<res<<endl;
        for(int i=2;i<=n;i++){
            if(check(pre[i]+((i&1)?s1[n]-s1[i]:s0[n]-s0[i])))res++;
//            cout<<res<<endl;
            if(i<n&&check(pre[i]-a[1]+((i&1)?s0[n]-s0[i]:s1[n]-s1[i])))res++;
//            cout<<res<<endl;
            if(check(((n-i+1)&1)?s0[n-i]:s1[n-i]))res++;
//            cout<<res<<endl;
            if(i<n&&check(a[n]+(((n-i+1)&1)?s1[n-i]:s0[n-i])))res++;
//            cout<<res<<endl;
            if(n-i>1&&check(suf[n-i+1]))res++;
//            cout<<res<<endl;
            res%=mod;
            int l,r,mid,op;
            l=0;r=(n-i)/2+1;op=(n-i)&1;
            while(l+1<r){
                mid=l+((r-l)>>1);
                int p=n-(2*mid+op)+1;
                if(check(pre[i]+((i&1)?s1[p]-s1[i]:s0[p]-s0[i])))r=mid;
                else l=mid;
            }
            if(n-i>=2)res=add(res+((n-i)-(2*r+op))/2+1);
//            cout<<res<<endl;
            l=0;r=(n-i-1)/2+1;op=(n-i-1)&1;
            while(l+1<r){
                mid=l+((r-l)>>1);
                int p=n-(2*mid+op)+1;
                if(check(pre[i]-a[1]+((i&1)?s0[p]-s0[i]:s1[p]-s1[i])))r=mid;
                else l=mid;
            }
            if(n-i-1>=2)res=add(res+((n-i-1)-(2*r+op))/2+1);
//            cout<<res<<endl;
            l=0;r=(n-i-1)/2+1;op=(n-i-1)&1;
            while(l+1<r){
                mid=l+((r-l)>>1);
                int p=n-(2*mid+op);
                if(check(pre[i]+a[n]+((i&1)?s1[p]-s1[i]:s0[p]-s0[i])))r=mid;
                else l=mid;
            }
            if(n-i-1>=2)res=add(res+((n-i-1)-(2*r+op))/2+1);
//            cout<<res<<endl;
            l=0;r=(n-i-2)/2+1;op=(n-i-2)&1;
            while(l+1<r){
                mid=l+((r-l)>>1);
                int p=n-(2*mid+op);
                if(check(pre[i]-a[1]+a[n]+((i&1)?s0[p]-s0[i]:s1[p]-s1[i])))r=mid;
                else l=mid;
            }
            if(n-i-2>=2)res=add(res+((n-i-2)-(2*r+op))/2+1);
//            cout<<"*"<<res<<endl;
        }
        printf("%d\n",res);
    }
    return 0;
}