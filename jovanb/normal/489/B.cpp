#include <bits/stdc++.h>

using namespace std;
int br[1000];
int niz[1000];
int main()
{
    int n,m,i,x,r=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i];
    }
    cin>>m;
    for(i=0;i<m;i++){
        cin>>x;
        br[x]++;
    }
    sort(niz,niz+n);
    for(i=0;i<n;i++){
        if(br[niz[i]-1]>0){br[niz[i]-1]--;r++;}
        else if(br[niz[i]]>0){br[niz[i]]--;r++;}
        else if(br[niz[i]+1]>0){br[niz[i]+1]--;r++;}
    }
    cout<<r;
    return 0;
}