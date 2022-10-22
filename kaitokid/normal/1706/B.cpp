#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[200009][3];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)fr[i][0]=fr[i][1]=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            fr[x][(i%2)]=max(fr[x][(i%2)],fr[x][1-(i%2)]+1);
        }
        for(int i=1;i<=n;i++)cout<<max(fr[i][0],fr[i][1])<<" ";//<<fr[i][1]<<endl;
        cout<<endl;

    }
    return 0;
}