#include <bits/stdc++.h>

using namespace std;
long raz[200000];
char x[200000];
unordered_map <long, long> ind;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n,maxi=0,i;
    cin>>n;
    cin>>x;
    for(i=1;i<=n;i++){
        raz[i]=raz[i-1];
        if(x[i-1]=='0')raz[i]++;
        else raz[i]--;
        if(ind[raz[i]]==0)ind[raz[i]]=i;
    }
    for(i=1;i<=n;i++){
        if(raz[i]==0)maxi=max(maxi,i);
        else if(ind[raz[i]]!=0)maxi=max(maxi,i-ind[raz[i]]);
    }
    cout<<maxi;
    return 0;
}