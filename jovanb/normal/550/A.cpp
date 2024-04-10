#include <bits/stdc++.h>

using namespace std;
char x[100005];
int main()
{
    cin>>x;
    int n=strlen(x),i;
    bool k=false;
    for(i=0;i<n-1;i++){
        if(x[i]=='A' && x[i+1]=='B' && k==false){k=true;i++;}
        else if(x[i]=='B' && x[i+1]=='A' && k==true){cout<<"YES";return 0;}
    }
    k=false;
    for(i=0;i<n-1;i++){
        if(x[i]=='B' && x[i+1]=='A' && k==false){k=true;i++;}
        else if(x[i]=='A' && x[i+1]=='B' && k==true){cout<<"YES";return 0;}
    }
    cout<<"NO";
    return 0;
}