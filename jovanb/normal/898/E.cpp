#include <bits/stdc++.h>

using namespace std;
long long niz[500000];
long long nizk[40000];
long long x[500000];
unordered_map <long long,long long>post;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long long n,a,b,brk=0,i,br=0,br0=0,r;
    cin>>n;
    for(i=0;i<n;i++)cin>>niz[i];
    for(i=0;i<35000;i++){nizk[i]=i*i;post[nizk[i]]=1;}
    for(i=0;i<n;i++){
        a=lower_bound(nizk,nizk+32000,niz[i])-nizk;
        if(a>0)b=a-1;
        else b=a;
        x[i]=min(nizk[a]-niz[i],niz[i]-nizk[b]);
        if(x[i]==0)brk++;
        if(niz[i]==0)br0++;
    }
    if(brk==n/2){cout<<0;return 0;}
    if(brk<n/2){
        i=0;
        sort(x,x+n);
        while(x[i]==0)i++;
        while(brk<n/2){
            br+=x[i];
            i++;
            brk++;
        }
        cout<<br;
        return 0;
    }
    sort(niz,niz+n);
    i=n-1;
    r=brk-br0;
    br+=min(r,brk-n/2);
    brk-=br;
    if(brk>n/2){
        br+=2*(brk-n/2);
    }
    /*while(brk>n/2){
        if(post[niz[i]]==1){
                if(niz[i]==0)br+=2;
                else br+=1;
                brk--;
        }
        i--;
    }*/
    cout<<br;
    return 0;
}