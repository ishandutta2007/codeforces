#include <bits/stdc++.h>
using namespace std;
long long niz[40];
int n,i;
long long niz1[2000000];
long long niz2[2000000];
long s;
long long x,m;
long long broj=0;
long long zb;
long long p=0,k=0;
void sjebi1(long long zbir,int l,int r)
{
    zbir=zbir%m;
    niz1[p]=zbir;
    p++;
    if(l==r)return;
    sjebi1(zbir+niz[l],l+1,r);
    sjebi1(zbir,l+1,r);
    return;
}
void sjebi2(long long zbir,int l,int r)
{
    niz2[k]=zbir;
    k++;
    if(l==r)return;

    sjebi2((zbir+niz[l])%m,l+1,r);
    sjebi2(zbir,l+1,r);
    return;
}
int bs(long long l,long long r)
{
   if (r>=l){
        int s=l+(r-l)/2;
        if (niz2[s]==zb)return niz2[s];
        if (niz2[s]>zb)return bs(l,s-1);
        return bs(s+1,r);
   }
   return niz2[r];
}


int main()
{

    cin>>n>>m;

    for(i=0;i<n;i++){
        cin>>x;
        x=x%m;
        niz[i]=x;
    }
    if(n==1){cout<<niz[0];return 0;}
    sjebi1(0,0,n/2);
    sjebi2(0,n/2,n);
    sort(niz2,niz2+k);
    for(i=0;i<p;i++){
        zb=(m-1)-niz1[i];
        broj=max(broj,niz1[i]+bs(0,k-1));
    }
    cout<<broj;
    return 0;
}