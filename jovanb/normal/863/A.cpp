#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    char niz[10];
    int i;
    cin>>niz;
    int n=strlen(niz);
    for(i=0;i<n;i++){
        if(niz[i]!=niz[n-i-1])break;
        if(i==n-1){cout<<"YES";return 0;}
    }
    while(niz[n-1]=='0'){
        n--;
        for(i=0;i<n;i++){
            if(niz[i]!=niz[n-i-1])break;
            if(i==n-1){cout<<"YES";return 0;}
        }
    }
    cout<<"NO";
    return 0;
}