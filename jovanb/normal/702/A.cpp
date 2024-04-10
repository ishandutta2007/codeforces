#include <bits/stdc++.h>

using namespace std;
long long niz[1000000];
int main()
{
    long n,i;
    long long br=1,maxbr=1;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i];
    }
    for(i=1;i<n;i++){
        if(niz[i]<=niz[i-1]){maxbr=max(maxbr,br);br=0;}
        br++;
        maxbr=max(maxbr,br);
    }
    cout<<maxbr;
    return 0;
}