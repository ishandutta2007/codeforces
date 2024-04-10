#include <bits/stdc++.h>

using namespace std;
char niz[100];
short g[100];
int main()
{
    cin>>niz;
    int n=strlen(niz),i,j,k;
    for(i=0;i<n;i++){
        g[i]=niz[i]-'0';
        if(g[i]%8==0){cout<<"YES\n"<<g[i];return 0;}
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if((g[i]*10+g[j])%8==0){cout<<"YES\n"<<g[i]<<g[j];return 0;}
        }
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            for(k=j+1;k<n;k++){
            if((g[i]*100+g[j]*10+g[k])%8==0){cout<<"YES\n"<<g[i]<<g[j]<<g[k];return 0;}
            }
        }
    }
    cout<<"NO";
    return 0;
}