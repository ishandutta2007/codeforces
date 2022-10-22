#include<bits/stdc++.h>
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
        string s;
        cin>>s;
        int n=s.size();
        s='$'+s+'$';
        bool bl=true;
        for(int i=1;i<=n;i++)
            if(s[i]!=s[i-1]&& s[i]!=s[i+1])bl=false;
        if(bl)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;

}