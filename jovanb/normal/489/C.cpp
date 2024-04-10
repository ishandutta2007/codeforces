#include <bits/stdc++.h>

using namespace std;
int niz[1000];
int main()
{
    int m,s,cs,i;
    cin>>m>>s;
    if(s==0){
        if(m!=1){cout<<-1<<" "<<-1;return 0;}
        else{cout<<0<<" "<<0;return 0;}
    }
    if(s>m*9){cout<<-1<<" "<<-1;return 0;}
    cs=s;
    cs--;
    niz[0]=1;
    for(i=m-1;i>0;i--){
        niz[i]=min(9,cs);
        cs-=min(9,cs);
    }
    if(cs>0)niz[0]+=cs;
    for(i=0;i<m;i++)cout<<niz[i];
    cout<<" ";
    cs=s;
    for(i=0;i<m;i++){
        niz[i]=min(9,cs);
        cs-=min(9,cs);
    }
    for(i=0;i<m;i++){
        cout<<niz[i];
    }


    return 0;
}