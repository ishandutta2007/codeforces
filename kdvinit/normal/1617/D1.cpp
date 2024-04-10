/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

int q;
int query(int a, int b, int c)
{
    cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
    cin>>q;
    return q;
}

void solve()
{
    int n;
    cin>>n;

    int imp=-1, cre=-1;

    for(int i=1; i<=n; i+=3)
    {
        query(i, i+1, i+2);
        if(q==0) imp=i;
        else cre=i;
        if(imp!=-1 && cre!=-1) break;
    }

    int s0 = query(cre, imp+1, imp+2);
    int s1 = query(cre+1, imp+1, imp+2);
    int s2 = query(cre+2, imp+1, imp+2);

    int fi, fc;

    if((s0+s1+s2)==0) fi=imp+1;
    else fi=imp;

    s0 = query(imp, cre+1, cre+2);
    s1 = query(imp+1, cre+1, cre+2);
    s2 = query(imp+2, cre+1, cre+2);

    if((s0+s1+s2)==3) fc=cre+1;
    else fc=cre;

    set<int> ans;
    for(int i=1; i<=n; i++)
    {
        if(i==fi || i==fc) continue;
        query(fi, fc, i);
        if(q==0) ans.insert(i);
    }
    ans.insert(fi);

    cout<<"! ";
    cout<<ans.size()<<" ";
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}