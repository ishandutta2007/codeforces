#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int cal(int x)
{
    int r=sqrt(x),ans=0;
    for(int i=2;i<=r;i++)
    {
        if(x==1)break;
        while((x%i)==0){x/=i;ans++;}
    }
    if(x>1)ans++;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        if(a>b)swap(a,b);
        int u=cal(a),v=cal(b);
        int i=2;

        if((a==1)&&(b==1)){cout<<"NO\n";continue;}
        if(k==1)
        {
            if(a==b){cout<<"NO\n";continue;}
            if((b%a)==0){cout<<"YES\n";continue;}
            cout<<"NO\n";continue;
        }
        if(a==1)
        {
            if(k>v){cout<<"NO\n";continue;}
            cout<<"YES\n";
            continue;
        }
        if(k>u+v){cout<<"NO\n";continue;}
        cout<<"YES\n";

    }
    return 0;
}