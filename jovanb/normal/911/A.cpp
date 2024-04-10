#include <bits/stdc++.h>

using namespace std;
long long niz[1000000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n;
    cin>>n;
    long long mini=10000000000,i;
    for(i=0;i<n;i++){
        cin>>niz[i];
        mini=min(mini,niz[i]);
    }
    long long br=0,brmin=10000000,poj=0;
    for(i=0;i<n;i++){
        if(niz[i]==mini && poj==1){brmin=min(brmin,br);br=0;}
        else if(niz[i]==mini){br=0;poj=1;}
        br++;
    }
    cout<<brmin;
    return 0;
}