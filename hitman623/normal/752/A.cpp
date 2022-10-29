#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,m,k,l,r,c=0;
    cin>>n>>m>>k;
    l=(k/(2*m))+!!(k%(2*m));
    k%=2*m;
    if(k==0) k=2*m;
    r=k/2+!!(k%2);
    k%=2;
    if(k==1) c=1;
    else c=2;
    cout<<l<<" "<<r<<" ";
    if(c==1) cout<<'L';
    else cout<<'R';
    return 0;
}