#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

bool DBG=false;

main()
{
    if (!DBG)
    {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    }

    vector<int> p;
    for (int i=2; i<=100500; i++)
    {
        bool ok = true;
        for (int j : p)
        {
            if (i%j ==0)
                ok=false;
            if (!ok or j*j>i)
                break;
        }
        if (ok)
            p.pb(i);
    }

    int ___;
    cin>>___;
    while(___--)
    {
        int n, k;
        cin>>n>>k;
        vector<int> v(n);
        vector<int> nt(n);

        for (int& i: v)
        {
            cin>>i;
            for (int j : p)
            {
                if (j*j > i)
                    break;
                while (i%(j*j)==0)
                    i/=(j*j);
            }
        }
        map<int, int> poss;
        for (int i=n-1; i>=0; i--)
        {
            if (poss.count(v[i]))
                nt[i]=poss[v[i]];
            else
                nt[i]=-1;
            poss[v[i]]=i;
        }

        if (DBG)
        {
            cout<<"DBG1\n";
            for (int i :v)
                cout<<i<<" ";
            cout<<"\n";
            for (int i: nt)
                cout<<i<<" ";
            cout<<"\n";
        }

        vector<vector<int> > jump(n, vector<int>(k+1));
        for (int i=0; i<=k; i++)
            jump[n-1][i]=n;
        for (int i=n-2; i>=0; i--)
        {
            int q = nt[i];
            if (q==-1)
            {
                for (int j=0; j<=k; j++)
                    jump[i][j]=jump[i+1][j];
            }
            else
            {
                bool ok = false;
                for (int j=0; j<=k; j++)
                {
                    if (jump[i+1][j]<q)
                        jump[i][j]=jump[i+1][j];
                    else
                    {
                        if (!ok)
                        {
                            ok=true;
                            jump[i][j]=q;
                        }
                        else
                            jump[i][j]=jump[i+1][j-1];
                    }
                }
            }
        }



        vector<vector<int> > ans(n, vector<int>(k+1, 1e9));
        ans[0][0]=0;
        int res=1e9;
        for (int i=0; i<n; i++)
            for (int j=0; j<=k; j++)
                for (int jmp=0; j+jmp<=k; jmp++)
                {
                    int to = jump[i][jmp];
                    if (to==n)
                        res=min(res, ans[i][j]+1);
                    else
                        ans[to][j+jmp]=min(ans[to][j+jmp], ans[i][j]+1);
                }

        if (DBG)
        {
            cout<<"DBG2\n";
            for (int j=0; j<=k; j++, cout<<"\n")
                for (int i=0; i<n; i++)
                    cout<<jump[i][j]<<" ";
            cout<<"DBG3\n";
            for (int j=0; j<=k; j++, cout<<"\n")
                for (int i=0; i<n; i++)
                    cout<<ans[i][j]<<" ";
            cout<<"ANS\n";
        }

        cout<<res<<"\n";
    }
}