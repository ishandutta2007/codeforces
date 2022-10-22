#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int q,n,a[60];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
cin>>q;
while(q--)
{
    memset(a,0,sizeof a);
    cin>>n;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        int d=0;
        while(x>1){d++;x/=2;}
        a[d]++;
        }
        for(int i=1;i<13;i++)
        {
            a[i]+=(a[i-1]/2);


       }

if(a[11]==0)cout<<"NO\n" ;
else cout<<"YES\n";
}
    return 0;
}