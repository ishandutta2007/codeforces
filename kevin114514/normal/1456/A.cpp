#include<bits/stdc++.h>
using namespace std;
int total[100100];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,p,k;
        cin>>n>>p>>k;
        for(int i=0;i<k;i++)
            total[i]=0;
        string S;
        cin>>S;
        int x,y;
        cin>>x>>y;
        int ans=2e9;
        p--;
        for(int i=n-1;i>=p;i--)
        {
            total[i%k]+=(S[i]-'0');
            int need=(n-i+k-1)/k;
            ans=min(ans,(i-p)*y+(need-total[i%k])*x);
        }
        cout<<ans<<endl;
        
    }
    return 0;
}