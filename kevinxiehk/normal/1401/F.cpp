#include<bits/stdc++.h>
#define int long long
#define m ((l+r)/2)
using namespace std;
int rev[20];
int seg[1100000];
int arr[300000];
int mode,x,y,k,n,nn,q;
void build(int id,int l,int r){
    if(l==r){seg[id]=arr[l];return;}
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    seg[id]=seg[id*2]+seg[id*2+1];
    return;
}
void upd(int id,int l,int r,int k,int x){
    seg[id]+=k;
    if(l==r)return;
    if(x<=m)upd(id*2,l,m,k,x);
    else upd(id*2+1,m+1,r,k,x);
}
int add(int id,int l,int r,int ll,int rr,int lay){
    //cout<<id<<" "<<l<<" "<<r<<" "<<lay<<endl;
    if(l>rr||r<ll)return 0;
    if(l>=ll&&r<=rr||lay==-1)return seg[id];
    if(!rev[lay])return add(id*2,l,m,ll,rr,lay-1)+add(id*2+1,m+1,r,ll,rr,lay-1);
    return add(id*2,m+1,r,ll,rr,lay-1)+add(id*2+1,l,m,ll,rr,lay-1);
}
void one(){
    cin>>x>>k;
    for(int i=0;i<n;i++){
        if(rev[i])x=((x-1)^(1<<i))+1;
    }
    k-=arr[x];
    arr[x]+=k;
    upd(1,1,nn,k,x);
    return;
}
void two(){
    cin>>k;
    for(int i=k-1;i>=0;i--)rev[i]^=1;
    return;
}
void three(){
    cin>>k;
    rev[k]^=1;
    return;
}
void four(){
    cin>>x>>y;
    cout<<add(1,1,nn,x,y,n-1)<<endl;
    return;
}
main(){
    cin>>n>>q;
    nn=pow(2,n);
    for(int i=0;i<=n;i++)rev[i]=0;
    for(int i=1;i<=nn;i++)cin>>arr[i];
    build(1,1,nn);
    for(int _=0;_<q;_++){
        cin>>mode;
        if(mode==1)one();
        else if(mode==2)two();
        else if(mode==3)three();
        else if(mode==4)four();
    }
    return 0;
}