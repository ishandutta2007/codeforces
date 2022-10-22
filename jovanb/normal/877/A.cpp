#include <bits/stdc++.h>

using namespace std;
char niz[200];
int main()
{
    int i,p=0;
    cin>>niz;
    int k=strlen(niz);
    for(i=0;i<k;i++){
        if(niz[i]=='D' && niz[i+1]=='a' && niz[i+2]=='n' && niz[i+3]=='i' && niz[i+4]=='l')p++;
        if(niz[i]=='O' && niz[i+1]=='l' && niz[i+2]=='y' && niz[i+3]=='a')p++;
        if(niz[i]=='S' && niz[i+1]=='l' && niz[i+2]=='a' && niz[i+3]=='v' && niz[i+4]=='a')p++;
        if(niz[i]=='A' && niz[i+1]=='n' && niz[i+2]=='n')p++;
        if(niz[i]=='N' && niz[i+1]=='i' && niz[i+2]=='k' && niz[i+3]=='i' && niz[i+4]=='t' && niz[i+5]=='a')p++;
        if(p>1){cout<<"NO";return 0;}
    }
    if(p==0){cout<<"NO";return 0;}
    else cout<<"YES";
    return 0;
}