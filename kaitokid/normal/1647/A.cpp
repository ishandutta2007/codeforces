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
        int n;
        cin>>n;
        string s="";
        while(n>=3)
        {
            s+="21";
            n-=3;
        }
        if(n==1)s="1"+s;
        if(n==2)s=s+"2";
        cout<<s<<endl;
    }
    return 0;
}