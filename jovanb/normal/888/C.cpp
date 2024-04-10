#include <bits/stdc++.h>

using namespace std;
char niz[100000];
long laspos[30];
long maxraz[30];
int exist[30];
int main()
{
    cin>>niz;
    int i;
    long mini=200000;
    for(i=0;i<26;i++){laspos[i]=-1;}
    long k=strlen(niz);
    for(i=0;i<k;i++){
            exist[niz[i]-97]=1;
        maxraz[niz[i]-97]=max(i-laspos[niz[i]-97],maxraz[niz[i]-97]);
        laspos[niz[i]-97]=i;
    }
    for(i=0;i<26;i++){
            if(exist[i]==1){
        maxraz[i]=max(maxraz[i],k-laspos[i]);
    }}
    for(i=0;i<26;i++){
        if(exist[i]==1){
        mini=min(mini,maxraz[i]);
    }}
    cout<<mini;
    return 0;
}