#include <iostream>

using namespace std;
int nr[1001], k, n, a[1001];
int main()
{
    int nrmax=0;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]-(i-1)*k>0)
        nr[a[i]-(i-1)*k]++;
    }
    for(int i=1;i<=1000;i++)
        if(nr[i]>nr[nrmax])
            nrmax=i;
    cout<<n-nr[nrmax]<<'\n';
    for(int i=1;i<=n;i++)
    {
        int h=a[i]-(i-1)*k;
        if(h>nrmax) cout<<"- "<<i<<' '<<h-nrmax<<'\n';
        if(h<nrmax) cout<<"+ "<<i<<' '<<-h+nrmax<<'\n';
    }
    return 0;
}