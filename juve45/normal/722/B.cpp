
#include <bits/stdc++.h>
using namespace std;
string s;
int v[120], n, ans;

int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>v[i];
}
cin.get();
for(int i=1;i<=n;i++)
{
    ans=0;
    getline(cin, s);
    ans+=count(s.begin(), s.end(), 'a');
    ans+=count(s.begin(), s.end(), 'e');
    ans+=count(s.begin(), s.end(), 'u');
    ans+=count(s.begin(), s.end(), 'i');
    ans+=count(s.begin(), s.end(), 'o');
    ans+=count(s.begin(), s.end(), 'y');
    if(ans!=v[i])
    {
        cout<<"NO\n";
        return 0;
    }
}
cout<<"YES\n";

    return 0;
}