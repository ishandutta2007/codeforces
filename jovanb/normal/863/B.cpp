#include <bits/stdc++.h>

using namespace std;
int niz[100],mark[100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int n,mini=50000,i,j,k,trenraz=0;
    cin>>n;
    n*=2;
    for(i=0;i<n;i++)cin>>niz[i];
    sort(niz,niz+n);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            for(k=0;k<n;k++)mark[k]=0;
            mark[i]=1;
            mark[j]=1;
            trenraz=0;
            for(k=0;k<n;k++){
                if(mark[k]==0){
                    if(mark[k+1]==0){trenraz+=niz[k+1]-niz[k];mark[k+1]=1;mark[k]=1;}
                    else if(mark[k+2]==0){trenraz+=niz[k+2]-niz[k];mark[k+2]=1;mark[k]=1;}
                    else{trenraz+=niz[k+3]-niz[k];mark[k+3]=1;mark[k]=1;}
                }
            }
            mini=min(mini,trenraz);
        }
    }
    cout<<mini;
    return 0;
}