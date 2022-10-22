#include <bits/stdc++.h>

using namespace std;
long niz[100005];
string a[100005],b[100005];
int main()
{
    long i,n;
    string c;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        }

    for(i=1;i<=n;i++){
        cin>>niz[i];
    }
    c=min(a[niz[1]],b[niz[1]]);
    for(i=2;i<=n;i++){
        if(c<min(a[niz[i]],b[niz[i]]))c=min(a[niz[i]],b[niz[i]]);
        else if(c<max(a[niz[i]],b[niz[i]]))c=max(a[niz[i]],b[niz[i]]);
        else {cout<<"NO";return 0;}

    }
    cout<<"YES";
    return 0;
}