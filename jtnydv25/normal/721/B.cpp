#include <bits/stdc++.h>
using namespace std;
map<int,int> cnt;
int main()
{
    int n,k;
    cin>>n>>k;
    int ans = 0;
    string s;
    for(int i=1;i<=n;i++)
        cin>>s,cnt[(int)s.length()]++;
    cin>>s;
    int l = s.length();
    int wrong = 0;
    for(auto x:cnt)
    {
        int len = x.first, num = x.second;
        for(int i = 1;i<=num;i++)
        {
            ans++;
            if(i==1 && len == l)
                cout<<ans<<" ";
            if(i==num && len == l)
                cout<<ans;
            wrong++;
            if(wrong == k)
            {
                wrong = 0;
                ans+=5;
            }
        }
    }
}