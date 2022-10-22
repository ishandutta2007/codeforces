#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool bl[30];
int d[30];
int k;
void ask(int x)
{
    int res=0;
    ll q=1;
    for(int i=0;i<26;i++)
    {
        if(q>20000009)break;
        int u=x%k;
        x/=k;
        ll p=d[i];
        if(bl[i])p=(p-u+k)%k;
        else p=(p+u)%k;
        res+=p*q;
        q*=k;
        bl[i]=1-bl[i];
        d[i]=(p-d[i]+k)%k;
    }
    cout<<res<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n>>k;
    for(int i=0;i<26;i++){bl[i]=0;d[i]=0;}
    int x=0;
    for(int i=0;i<n;i++)
    {
        ask(i);
        fflush(stdout);
        int r;
        cin>>r;
        if(r==1)break;
        x=i;
    }

    }
    return 0;
}