#include <bits/stdc++.h>

using namespace std;
int niz[1000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<2*n;i++)cin>>niz[i];
    sort(niz,niz+n*2);
    if(niz[n-1]==niz[n])cout<<"NO";
    else cout<<"YES";
    return 0;
}