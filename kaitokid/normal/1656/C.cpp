#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009];
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
        bool bl=false;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==1)bl=true;
        }
       if(bl==false){cout<<"YES"<<endl;continue;}
       sort(a,a+n);
       bool ans=true;
       for(int i=1;i<n;i++)if(a[i]==a[i-1]+1)ans=false;
       if(ans)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;

    }
    return 0;
}