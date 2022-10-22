#include <bits/stdc++.h>

using namespace std;
char niz[30];
string nizstr[500];
int copi[500];
int main()
{
    int n,i,j,k,z,brojac=0,k1;
    cin>>n;
    for(i=0;i<n;i++){
    cin>>niz;
    k=strlen(niz);
    k1=k;
    for(j=1;j<k;j++){
        if(niz[j]=='u' && niz[j-1]=='o'){
            niz[j-1]='u';
            niz[j]='o';
        }
        if(niz[j]=='o' && niz[j-1]=='o'){
            k--;
            niz[j-1]='u';
            for(z=j;z<k;z++){
                niz[z]=niz[z+1];
            }

        }
        if(niz[j]=='h' && niz[j-1]=='k'){
            k--;
            for(z=j-1;z<k;z++){
                niz[z]=niz[z+1];

            }
        j=j-2;}
    }
    nizstr[i] = niz;
    nizstr[i].erase(k,k1-k);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(nizstr[i]==nizstr[j])copi[j]=1;
        }
    }
    for(i=0;i<n;i++){
        brojac-=copi[i];
    }
    cout<<n+brojac;
    return 0;
}