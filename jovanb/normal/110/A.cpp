#include <bits/stdc++.h>
using namespace std;
char niz[40];
int main(){
    //Milose prestani da mi gledas u kod
    cin>>niz;
    int i,b=0;
    int k=strlen(niz);
    for(i=0;i<k;i++){
        if(niz[i]=='4' || niz[i]=='7')b++;
    }
    if(b==4 || b==7)cout<<"YES";
    else cout<<"NO";
    return 0;
}