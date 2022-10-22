#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
int t,a,b;
cin>>t;
while(t--)
{
    cin>>a>>b;
    if(a<b)swap(a,b);
    cout<<(max(a,2*b)*max(a,2*b))<<endl;
}
    return 0;
}