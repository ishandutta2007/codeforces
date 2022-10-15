#include<bits/stdc++.h>
using namespace std;
int x[1000100];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    sort(x+1,x+n+1);
    reverse(x+1,x+n+1);
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(x[i]>=x[k]&&x[i])
            cnt++;
    cout<<cnt<<endl;
    return 0;
}