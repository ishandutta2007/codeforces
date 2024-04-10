#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int md[509];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,r,c;
        cin>>n>>k>>r>>c;
        r--,c--;
        md[r]=c%k;
        for(int i=r+1;i<n;i++)md[i]=(md[i-1]+1)%k;
        for(int i=r-1;i>=0;i--)md[i]=(md[i+1]+k-1)%k;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                if((j%k)==md[i])cout<<"X"; else cout<<".";
            cout<<endl;
        }

    }
    return 0;
}