#include <bits/stdc++.h>

using namespace std;
int niz[1000];
int main()
{
    int n,i,rmin=180,j;
    cin>>n;
    for(i=0;i<n;i++)cin>>niz[i];
    int brl=0,brd;
    niz[n]=0;
    for(i=0;i<n;i++){
        brl+=niz[i];
        brd=0;
        for(j=n;j>1;j--){
            brd+=niz[j];
            rmin=min(rmin,abs(brl+brd-180));
        }
    }
    cout<<rmin*2;
    return 0;
}