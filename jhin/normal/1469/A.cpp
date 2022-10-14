#include <bits/stdc++.h>

using namespace std;



int t,n,d[101][101][101];
string st;

int f(int ind,int l,int r)
{
    if(ind == n) return l == r;
    if(r>l)return 0;
    if(d[ind][l][r] != -1)return d[ind][l][r];
    int ans = 0;

    if(st[ind] == '(' || st[ind] == '?')
        ans = max(ans,f(ind+1,l+1,r));
    if(st[ind] == ')' || st[ind] == '?')
        ans = max(ans,f(ind+1,l,r+1));

    return d[ind][l][r]=ans;

}

int main()
{
    ios::sync_with_stdio(0);

    cin>>t;
    while(t--)
    {
        cin>>st;
        n = st.size();
        memset(d,-1,sizeof(d));

        if(f(0,0,0))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;

}