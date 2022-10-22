#include <bits/stdc++.h>

using namespace std;
char niz[1000];
int main()
{
    cin>>niz;
    int k=strlen(niz),brc=0,bro=0,i;
    for(i=0;i<k;i++){
        if(niz[i]<91)brc++;
        else bro++;
    }
    if(bro==0 || (bro==1 && niz[0]>=91)){
        for(i=0;i<k;i++){
            if(niz[i]<91)niz[i]=tolower(niz[i]);
            else niz[i]=toupper(niz[i]);
        }
    }
    for(i=0;i<k;i++){
        cout<<niz[i];
    }
    return 0;
}