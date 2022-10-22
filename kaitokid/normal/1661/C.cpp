#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll h[300009],n;
ll ch(ll p)
{
        ll mx=h[n-1];
        ll ans1=0;
        if(mx%2==p){mx++;ans1++;}
        ll pr=0;
        for(int i=0;i<n-1;i++)
        {
            if((h[i]%2)==p)ans1++;
            pr+=(mx-h[i])/2;
        }
        int u=ans1-1;
        pr=(pr-u);
        if(pr<0)pr=0;
        ans1+=u;
        if(pr==0)return ans1;
        pr--;
        ans1++;
        if(pr==0)return ans1;
        ans1+=(pr/3)*4;
        if((pr%3)==1)ans1+=2;
        if((pr%3)==2)ans1+=3;
        return ans1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)cin>>h[i];
        sort(h,h+n);
        cout<<min(ch(0),ch(1))<<endl;
    }


    return 0;
}