#include <bits/stdc++.h>
using namespace std;
char x[1000];
int main(){
    cin>>x;
    int n=strlen(x),i;
    for(i=0;i<n;i++){
        x[i]=tolower(x[i]);
     }
    for(i=0;i<n;i++){
        if(x[i]!='a' && x[i]!='e' && x[i]!='i' && x[i]!='o' && x[i]!='u' && x[i]!='y')cout<<"."<<x[i];
    }
    return 0;
     }