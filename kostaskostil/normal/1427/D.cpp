#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

int n;
int a[500500];
vector<vector<int> > ans;

void oper(vector<int> v)
{
    if (v.size()==1)
        return;
    vector<int> res;
    ans.pb(v);

    int nt=n;
    reverse(v.begin(), v.end());
    for (int i:v)
    {
        for (int j=nt-i+1; j<=nt; j++)
            res.pb(a[j]);
        nt-=i;
    }

    if (nt!=0)
        cout<<"ERROR\n";
    nt=1;
    for (int i:res)
        a[nt++]=i;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    int ___;
//    cin>>___;
//    for (int _=0; _<___; _++)
//    {
//
//    }

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];

    bool ok=true;
    for (int i=1; i<=n; i++)
    {
        if (!ok)
            reverse(a+1, a+n+1);

        vector<int> v;
        if (a[i]!=i)
        {
            int c=-1;
            for (int j=1; j<=n; j++)
                if (a[j]==i)
                    c=j;
            for (int j=1; j<i; j++)
                v.pb(1);
            v.pb(c-i+1);
            if (c<n)
                v.pb(n-c);
        }

        if (!ok)
        {
            reverse(a+1, a+n+1);
            reverse(v.begin(), v.end());
        }
        if (!v.empty())
        {
            oper(v);
            ok=!ok;
        }
    }
    if (!ok)
    {
        vector<int> v(n, 1);
        ans.pb(v);
    }
    cout<<ans.size()<<"\n";
    for (auto& v:ans)
    {
        cout<<v.size()<<" ";
        for (int i:v)
            cout<<i<<" ";
        cout<<"\n";
    }
}