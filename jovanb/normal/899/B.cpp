#include <bits/stdc++.h>

using namespace std;
int sek[]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int niz[100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int n,i,br=0,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i];
        if(niz[i]==29){br++;niz[i]=28;}
    }
    if(br>1){cout<<"No";return 0;}
    for(i=0;i<12;i++){
        for(j=0;j<n;j++){
            if(niz[j]!=sek[i+j])break;
            if(j==n-1){cout<<"yes";return 0;}
        }
    }
    cout<<"no";
    return 0;
}