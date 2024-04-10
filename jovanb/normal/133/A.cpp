#include <bits/stdc++.h>
using namespace std;
char niz[1000];
int main(){
    cin>>niz;
    int i;
    int k=strlen(niz);
    for(i=0;i<k;i++){
        if(niz[i]=='H' || niz[i]=='Q' || niz[i]=='9'){cout<<"YES";return 0;}
    }
    cout<<"NO";
    return 0;
}