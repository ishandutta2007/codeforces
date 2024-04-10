#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2000009];
int n;
bool ch(int x)
{
    int l=0,r=n-1;
    while(r>l)
    {
        if(a[l]==x){l++;continue;}
        if(a[r]==x){r--;continue;}
        if(a[l]!=a[r])return false;
        l++;
        r--;
    }
    return true;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int r=n-1,l=0;
    bool bl=true;
    while(r>l)
    {
        if(a[l]==a[r]){l++;r--;continue;}
        bl=false;
        if(ch(a[l]))bl=true;
        if(ch(a[r]))bl=true;
        break;
    }
    if(bl)cout<<"YES\n";
    else cout<<"NO\n";

    }
    return 0;
}