#include <iostream>

using namespace std;
int niz[1000];
int main()
{
    int n,br=0,i;
    cin>>n;
    for(i=0;i<n;i++)cin>>niz[i];
    for(i=1;i<n-1;i++){
        if(niz[i]<niz[i-1] && niz[i]<niz[i+1])br++;
        if(niz[i]>niz[i-1] && niz[i]>niz[i+1])br++;
    }
    cout<<br;
    return 0;
}