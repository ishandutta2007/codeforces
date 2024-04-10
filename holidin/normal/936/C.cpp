#include <bits/stdc++.h>
using namespace std;
int n;
string s, t;
void rev(int x)
{
    string sub=s.substr(n-x, x);
    reverse(sub.begin(), sub.end());
    s=sub+s.substr(0, n-x);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin>>n>>s>>t;
    string a=s, b=t;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a!=b)return cout<<"-1\n", 0;
    cout<<3*n<<"\n";
    for(int i=0; i<n; i++)
    {
        int id=i;
        for(; s[id]!=t[n-i-1]; ++id);
        rev(n);
        rev(id);
        rev(1);
        cout<<n<<" "<<id<<" "<<1<<" \n"[i==n-1];
    }
    return 0;
}