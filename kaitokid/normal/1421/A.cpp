#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{ios::sync_with_stdio(0);
int a,b,t;
cin>>t;
while(t--)
{
    cin>>a>>b;
    int c=(a&b);
    a-=c;
    b-=c;
    cout<<a+b<<endl;
}
    return 0;
}