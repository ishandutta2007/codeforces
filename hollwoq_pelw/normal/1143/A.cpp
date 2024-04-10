#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,i,j;
    cin>>n;
    int a[n+1];
    int e[2]={0,0};
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        e[a[i]]++;
    }
    for(i=1;i<=n;i++)
    {
        e[a[i]]--;
        if(e[a[i]]==0)
        {
            cout<<i;
            break;
        }
    }

    
    return 0;
}