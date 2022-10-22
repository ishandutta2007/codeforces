#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,t;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        int sum=0,m,x;
        cin>>n>>m;
        for(int i=0;i<n;i++){cin>>x;sum+=x;}
        cout<<min(sum,m)<<endl;
    }
    return 0;
}