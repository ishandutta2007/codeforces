#include <bits/stdc++.h>

using namespace std;
string s;
int q,t,l,r;
char z;
set<int> a[30];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++)a[s[i]-'a'].insert(i+1);
    cin>>q;
    while (q--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>l>>z;
            a[s[l-1]-'a'].erase(l);
            a[z-'a'].insert(l);
            s[l-1]=z;
            continue;
        }
        int ans=0;
        cin>>l>>r;
        for(int i=0;i<26;i++){set<int> :: iterator it=a[i].lower_bound(l);if(it!=a[i].end()&&(*it)<=r)ans++;}
    cout<<ans<<"\n";
    }
    return 0;
}