#include <bits/stdc++.h>

using namespace std;
long long niz[100000];
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long n,a,b,l,r,v,broj,i,x=0;
    cin>>a>>b;
    broj=__gcd(a,b);
    for(i=1;i<=sqrt(broj);i++){
        if(broj%i==0){
            niz[x]=i;
            x++;
            niz[x]=broj/i;
            x++;
        }
    }
    sort(niz,niz+x);
    cin>>n;
    for(i=0;i<n;i++){
        cin>>l>>r;
        if(niz[x-1]<l)cout<<-1<<endl;
        else if(niz[0]>r)cout<<-1<<endl;
        else{
            v=(upper_bound(niz,niz+x,r)-niz)-1;
            if(niz[v]<l)cout<<-1<<endl;
            else cout<<niz[v]<<endl;
        }
    }
    return 0;
}