#include <iostream>

using namespace std;
int nzd(long long a,long long b){
    if(b>a)return nzd(b,a);
    if(b==0)return a;
    return nzd(b,a-b);
}
long long niz[2005];
int main()
{
    int n,br1=0,r=30000,i,j;
    cin>>n;
    long long x;
    for(i=0;i<n;i++){cin>>niz[i];if(niz[i]==1)br1++;};
    if(br1>0){cout<<n-br1;return 0;}
    for(i=0;i<n;i++){
        x=niz[i];
        for(j=i+1;j<n;j++){
            x=nzd(x,niz[j]);
            if(x==1){r=min(r,j-i);break;}
        }
    }
    if(r==30000)cout<<-1;
    else cout<<n-1+r;
    return 0;
}