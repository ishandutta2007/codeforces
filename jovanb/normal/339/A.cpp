#include <bits/stdc++.h>
using namespace std;
char niz[200];
int p[100];
int main(){
    cin>>niz;
    int k=strlen(niz),n=0,i;
    for(i=0;i<k;i+=2){
    p[n]=niz[i]-'0';
    n++;
    }
    sort(p,p+n);
    cout<<p[0];
    for(i=1;i<n;i++)cout<<"+"<<p[i];
    return 0;
}