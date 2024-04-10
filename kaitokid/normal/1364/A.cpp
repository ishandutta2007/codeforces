#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    int n,x,z;
    int sum=0,l=-1,r=-1;
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
        cin>>z;
        sum+=z;
        sum%=x;
        if(z%x>0){r=i;if(l==-1)l=i;}
    }
    if(l==-1){cout<<-1<<endl;continue;}
    if(sum>0){cout<<n<<endl;continue;}
    int u=n-l-1;
    cout<<max(u,r)<<endl;
}
       return 0;
}