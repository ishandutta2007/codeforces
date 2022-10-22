#include <bits/stdc++.h>

using namespace std;
int niz[5001];
int poj[5001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int n,br=0,i,j,last;
    cin>>n;
    br=n;
    for(i=0;i<n;i++)cin>>niz[i];
    sort(niz,niz+n);
    for(i=0;i<n-1;i++){
        last=niz[i];
        for(j=i+1;j<n;j++){
            if(last<niz[j] && poj[j]==0 && poj[i]==0){
                poj[j]=1;
                br--;
                last=niz[j];
            }
        }
    }
    cout<<br;
    return 0;
}