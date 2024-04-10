#include <bits/stdc++.h>

using namespace std;
char a[100],b[100],glavna[100];
string niz[2000];
int nemoze[400];
int main()
{
    int i,n,m,lampa=0,r,k,j,z;
    cin>>n;
    cin>>glavna;
    for(i=0;i<n;i++){
        if(glavna[i]!='*'){
            nemoze[glavna[i]-'0']=1;
        }
    }
    cin>>m;
    k=m;
    for(i=0;i<m;i++){
        cin>>a;
        r=0;
        for(j=0;j<n;j++){
            if(glavna[j]!=a[j] && glavna[j]!='*'){lampa=1;break;}
            else if(glavna[j]=='*'){
            if(nemoze[a[j]-'0']==1){lampa=1;break;}
            else{b[r]=a[j];r++;}
        }

        }
        if(lampa==1)k--;
        else(niz[i+k-m]=b);
        lampa=0;
    }
    if(k==0){cout<<0;return 0;}
    n=26;
    for(j=0;j<26;j++){
    for(i=0;i<k;i++){
        lampa=0;
        strcpy(a,niz[i].c_str());
        z=strlen(a);
        for(r=0;r<z;r++){
            if(a[r]-'0'==(j+49))break;
            if(r==z-1){n--;lampa=1;}
        }
        if(lampa==1)break;
    }}
    cout<<n;
    return 0;
}