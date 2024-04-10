#include <bits/stdc++.h>

using namespace std;
long long niz[100000];
int main()
{
    long n,i;
    cin>>n;
    for(i=0;i<n;i++)cin>>niz[i];
    sort(niz,niz+i);
    for(i=2;i<n;i++){
        if(niz[i]<niz[i-1]+niz[i-2]){cout<<"YES";return 0;}
    }
    cout<<"NO";
    return 0;
}