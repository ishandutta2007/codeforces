#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009],b[200009];
string s;
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
        for(int i=0;i<n;i++)cin>>a[i];
        int u=0;
        cin>>s;
       for(int i=0;i<n;i++)
            if(s[i]=='0')u++;
       vector<int>g,h;
       for(int i=0;i<n;i++)
       {
           if(a[i]<=u && s[i]=='1')g.push_back(a[i]);
           if(a[i]>u && s[i]=='0')h.push_back(a[i]);
       }
       for(int i=0;i<n;i++)
       {

           if(a[i]<=u && s[i]=='1'){cout<<h.back()<<" ";h.pop_back();continue;}
           if(a[i]>u && s[i]=='0'){cout<<g.back()<<" ";g.pop_back();continue;}
        cout<<a[i]<<" ";
       }
       cout<<endl;

    }
    return 0;
}