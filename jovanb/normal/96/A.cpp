#include <bits/stdc++.h>
using namespace std;
char r[1000];
int main(){
    cin>>r;
    int i,n=strlen(r);
    for(i=0;i<=n-7;i++){
        if(r[i]==r[i+1] && r[i]==r[i+2] && r[i]==r[i+3] && r[i]==r[i+4] && r[i]==r[i+5] && r[i]==r[i+6]){cout<<"YES";return 0;}
    }
    cout<<"NO";
    return 0;
    }