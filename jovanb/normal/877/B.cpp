#include <bits/stdc++.h>

using namespace std;
char niz[6000];
int broja[6000];
int brojb[6000];
int main()
{
    cin>>niz;
    int k=strlen(niz),mini=10000,i,j,t;
    for(i=0;i<k;i++){
        if(niz[i]=='a')broja[i]++;
        else brojb[i]++;
        broja[i]+=broja[i-1];
        brojb[i]+=brojb[i-1];
    }
    if(broja[k-1]==0 || brojb[k-1]==0){cout<<k;return 0;}
    if(k==1){cout<<1;return 0;}
    if(k==2){cout<<k;return 0;}
    for(i=0;i<k;i++){
        for(j=i+1;j<=k;j++){
            if(i==0 && j==k)break;
            if(i==0){
                t=broja[j-1]+brojb[k-1]-brojb[j-1];}
            else if(j==k){
                t=brojb[i-1]+broja[j-1]-brojb[i-1];
            }
            else(t=brojb[i-1]+broja[j-1]-broja[i-1]+brojb[k-1]-brojb[j-1]);
            mini=min(mini,t);
        }
    }
    cout<<k-mini;
    return 0;
}