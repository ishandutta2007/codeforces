#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int pr[300009];
int p(int x)
{
    if(pr[x]==x)return x;
    return pr[x]=p(pr[x]);
}
bool bl[300009];
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
        for(int i=0;i<2*n;i++){pr[i]=i;bl[i]=false;}
        string s;
        cin>>s;
        stack <int>st;
        for(int i=0;i<2*n;i++)
        {
            if(s[i]=='(')st.push(i);
            if(s[i]==')')
            {
                if(st.empty())continue;
                int u=st.top();
                st.pop();
                bl[i]=true;
                pr[p(u)]=p(i);
                if(u>0 && bl[u-1])
                    pr[p(u)]=p(u-1);

            }
        }
        int ans=0;
        for(int i=0;i<2*n;i++)if(p(i)==i)ans++;
        cout<<ans<<endl;

    }
    return 0;
}