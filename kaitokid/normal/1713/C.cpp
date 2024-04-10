#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[100009];
bool pw[300009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i*i<300000;i++)
        pw[i*i]=true;
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)ans[i]=-1;
    int d=n-1;
    for(int i=n-1;i>=0;i--)
    {
        if(!pw[d+i])continue;
        for(int j=i;j<n;j++)
        {
            if(ans[j]!=-1)break;
            ans[j]=d;
            d--;
        }
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    cout<<endl;
    }

    return 0;
}