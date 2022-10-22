#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[109];
int main()
{
 ios::sync_with_stdio(0);
 cin.tie(NULL);
int t,n,d;
cin>>t;
while(t--)
{
    int n,k;
    cin>>n>>k;
    int u=(k-(n-k));
    int l=1,r=k;
    for(int i=1;i<=k;i++)
    {
        if(i<u)cout<<l++<<" ";
        else cout<<r--<<" ";
    }
    cout<<endl;

}
    return 0;
}