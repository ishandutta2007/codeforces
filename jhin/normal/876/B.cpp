#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,m,x;
    cin>>n>>k>>m;
    vector <int> ss[m];int s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++){int j=s[i]%m;ss[j].push_back(s[i]);
    if(ss[j].size()>=k){cout<<"Yes"<<endl;for(int z=0;z<k;z++)cout<<ss[j][z]<<" ";return 0;}}
    cout<<"No";
    return 0;
}