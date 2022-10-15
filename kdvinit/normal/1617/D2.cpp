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

    int val[n+1]={0};
    for(int i=1; i<=n; i+=3)
    {
        val[i] = query(i, i+1, i+2);
        if(q==0) imp=i;
        else cre=i;
    }

    int fi, fc;

    int sum = query(cre, imp+1, imp+2) + query(cre+1, imp+1, imp+2);
    if(sum==0) fi=imp+1;
    else fi=imp;

    sum = query(imp, cre+1, cre+2) + query(imp+1, cre+1, cre+2);
    if(sum==2) fc=cre+1;
    else fc=cre;

    set<int> ans;
    for(int i=1; i<=n; i+=3)
    {
        if(i==imp)
        {
            ans.insert(fi);
            for(int j=i; j<=i+2; j++)
            {
                if(j==fi) continue;
                query(fi, fc, j);
                if(q==0) ans.insert(j);
            }

            continue;
        }

        if(i==cre)
        {
            for(int j=i; j<=i+2; j++)
            {
                if(j==fc) continue;
                query(fi, fc, j);
                if(q==0) ans.insert(j);
            }
            
            continue;
        }

        if(val[i]==0)
        {
            query(i, i+1, fc);
            if(q==0)
            {
                ans.insert(i);
                ans.insert(i+1);
                query(fc, fi, i+2);
                if(q==0) ans.insert(i+2);
            }
            else
            {
                ans.insert(i+2);
                query(fc, fi, i);
                if(q==0) ans.insert(i);
                else ans.insert(i+1);
            }

            continue;
        }

        if(val[i]==1)
        {
            query(i, i+1, fi);
            if(q==1)
            {
                query(fc, fi, i+2);
                if(q==0) ans.insert(i+2);
            }
            else
            {
                query(fc, fi, i);
                if(q==0) ans.insert(i);
                else ans.insert(i+1);
            }

            continue;
        }
    }

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