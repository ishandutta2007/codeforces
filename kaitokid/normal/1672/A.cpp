#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    int sum=0;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        sum+=x;
    }
    if((sum-n)%2)cout<<"errorgorn\n";
    else cout<<"maomao90\n";
}

return 0;
}