#include <bits/stdc++.h>
using namespace std;
char a[1000],b[1000];
int main(){
    int i;
    cin>>a>>b;
    int n=strlen(a);
    for(i=0;i<n;i++){
        a[i]=tolower(a[i]);
        b[i]=tolower(b[i]);
        if(a[i]>b[i]){cout<<1;return 0;}
        else if(a[i]<b[i]){cout<<-1;return 0;}
    }
    cout<<0;
    return 0;
}