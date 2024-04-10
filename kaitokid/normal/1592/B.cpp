#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009],b[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,x;

        cin>>n>>x;
        for(int i=0;i<n;i++){cin>>a[i];b[i]=a[i];}
        sort(b,b+n);
        bool ans=true;
        for(int i=0;i<n;i++)
        {
            if(i+x>=n && i-x<0 && a[i]!=b[i]){ans=false;break;}
        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}