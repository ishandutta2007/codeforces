#include <bits/stdc++.h>

using namespace std;
long long niz1[100005];
long long niz2[100005];
int main()
{
    long n,i,m,l,r;
    short x;
    cin>>n;
    for(i=1;i<=n;i++){cin>>niz1[i];niz2[i]=niz1[i];}
    sort(niz2+1,niz2+n+1);
    niz1[0]=0;
    niz2[0]=0;
    for(i=1;i<=n;i++){
        niz1[i]+=niz1[i-1];
        niz2[i]+=niz2[i-1];
    }
    cin>>m;
    for(i=0;i<m;i++){
        cin>>x>>l>>r;
        if(x==1)cout<<niz1[r]-niz1[l-1]<<endl;
        else cout<<niz2[r]-niz2[l-1]<<endl;
    }
    return 0;
}