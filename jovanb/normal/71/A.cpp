#include <bits/stdc++.h>
using namespace std;
char niz[100];
int main(){
    int n,i,k,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz;
        k=strlen(niz);
        if(k>10)cout<<niz[0]<<k-2<<niz[k-1]<<endl;
        else {for(j=0;j<k;j++)cout<<niz[j];cout<<endl;}
    }
    return 0;
}