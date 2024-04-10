#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int ans[200009];
int main()
{
ios::sync_with_stdio(0);
int n,t;
cin>>t;
while(t--)
{
    cin>>n;
    string s;
    cin>>s;
    int d=1;
    vector<int>a,b;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0'&&a.empty()){a.push_back(d);d++;}
        if(s[i]=='1'&&b.empty()){b.push_back(d);d++;}
        if(s[i]=='0'){int u=a[a.size()-1];b.push_back(u);ans[i]=u;a.pop_back();}
        if(s[i]=='1'){int u=b[b.size()-1];a.push_back(u);ans[i]=u;b.pop_back();}
    }
    cout<<d-1<<endl;
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}
    return 0;
}