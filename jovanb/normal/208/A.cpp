#include <bits/stdc++.h>

using namespace std;
char ch[100];
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    cin>>ch;
    long i,n=strlen(ch);
    for(i=0;i<n-2;i++){
        if(ch[i]=='W' && ch[i+1]=='U' && ch[i+2]=='B'){ch[i]=' ';ch[i+1]=' ';ch[i+2]=' ';}
    }
    for(i=0;i<n;i++){
        cout<<ch[i];
    }
    return 0;
}