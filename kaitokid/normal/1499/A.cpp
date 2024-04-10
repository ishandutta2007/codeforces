#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y;
        cin>>n>>x>>y;
        int a=(x+y)/2;
        int c=(2*n-x-y)/2;
        int w,b;
        cin>>w>>b;
        if(w>a||b>c){cout<<"NO\n";continue;}
        cout<<"YES\n";
    }
    return 0;
}