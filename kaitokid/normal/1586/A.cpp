#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool pr[1000009];
int n;
int a[109];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=2;i<1000;i++)
    {
        if(pr[i])continue;
        for(int j=i*i;j<=1000000;j+=i)pr[j]=true;
    }
    int t;
    cin>>t;

    while(t--)
    {
        cin>>n;
        int s=0,b=-1;
        for(int i=0;i<n;i++){cin>>a[i];s+=a[i];if(a[i]%2)b=i;}

    if(pr[s])
    {
        cout<<n<<endl;
        for(int i=0;i<n;i++)cout<<i+1<<" ";
        cout<<endl;
        continue;
    }
    cout<<n-1<<endl;
    for(int i=0;i<n;i++)
    if(i!=b)cout<<i+1<<" ";
    cout<<endl;
    }
    return 0;
}