#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

const int nmax=200500;

int n;
string s;
int t[nmax];
int a[nmax];

int get(int v)
{
    int s=0;
    for (int i=v; i>0; i&=(i+1), i--)
        s+=t[i];
    return s;
}

void upd(int v, int val)
{
    for (int i=v; i<=n; i|=(i+1))
        t[i]+=val;
}

vector<pair<int, int> > ans;

void del(int l, int r)
{
//    cout<<l<<" "<<r<<"\n";
    int lx, rx;
    lx=get(l);
    rx=get(r);
    ans.pb({lx, rx});
    upd(r+1, -(rx-lx+1));
}

void init()
{
    for (int i=1; i<=n; i++)
        t[i]=0;
    for (int i=1; i<=n; i++)
        upd(i, 1);
    ans.clear();
}

int cnt[26];
set<int> non;
set<pair<int, int> > stx[26];
set<pair<int, int> > scnt;
set<pair<pair<int, int>, int> > st;

void add(int i, int c)
{
    scnt.erase({cnt[i], i});
    cnt[i]+=c;
    if (cnt[i]>0)
        scnt.insert({cnt[i], i});
}

void cut(int l1, int r1, int v1, int l2, int r2, int v2)
{
    non.erase(v1);
    non.erase(v2);

    stx[v1].erase({l1, r1});
    stx[v2].erase({l2, r2});
    st.erase({{l1, r1}, v1});
    st.erase({{l2, r2}, v2});

    del(r1, l2);

    add(v1, -1);
    add(v2, -1);

    if (r1>l1+1)
    {
        stx[v1].insert({l1, r1-1});
        st.insert({{l1, r1-1}, v1});
    }
    if (r2>l2+1)
    {
        stx[v2].insert({l2+1, r2});
        st.insert({{l2+1, r2}, v2});
    }
    if (stx[v1].size()>0)
        non.insert(v1);
    if (stx[v2].size()>0)
        non.insert(v2);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        st.clear();
        non.clear();
        scnt.clear();
        for (int i=0; i<26; i++)
            stx[i].clear(), cnt[i]=0;
        cin>>s;
        n=s.size();
        init();
        for (int i=0; i<n; i++)
            a[i+1]=s[i]-'a';
        int l=1;
        for (int i=2; i<=n; i++)
            if (a[i]!=a[i-1])
            {
                if (l<i-1)
                {
                    st.insert({{l, i-1}, a[i-1]});
                    stx[a[i-1]].insert({l, i-1});
                    cnt[a[i-1]]+=i-1-l;
                }
                l=i;
            }
        if (l<n)
        {
            st.insert({{l, n}, a[n]});
            stx[a[n]].insert({l, n});
            cnt[a[n]]+=n-l;
        }
        for (int i=0; i<26; i++)
            if (cnt[i]>0)
                scnt.insert({cnt[i], i}), non.insert(i);
        while (non.size()>1)
        {
            int v=(*prev(scnt.end())).se;
            pair<int, int> pa=*stx[v].begin();
            int l=pa.fi, r=pa.se;
            int l2, r2, v2;

            bool f=false;

            auto it=st.lower_bound({{l+1, 0}, 0});
            if (it==st.end())
            {
                it=prev(prev(it));
                f=true;
            }
            l2=(*it).fi.fi;
            r2=(*it).fi.se;
            v2=(*it).se;
            if (v!=v2)
            {
                if (!f)
                    cut(l, r, v, l2, r2, v2);
                else
                    cut(l2, r2, v2, l, r, v);
            }
            else
            {
                it=st.lower_bound({{l+1, 0}, 0});
                f=false;
                if (v==v2)
                {
                    f=true;
                    l2=-1;
                    for (int i=0; i<26; i++)
                        if (i!=v)
                    {
                        auto it2=stx[i].lower_bound({l+1, 0});
                        if (it2==stx[i].begin())
                            continue;
                        it2=prev(it2);
                        if ((*it2).fi>l2)
                        {
                            l2=(*it2).fi;
                            r2=(*it2).se;
                            v2=i;
                        }
                    }
                    if (v!=v2)
                    {
                        auto itx=stx[v].lower_bound({l2, r2});
                        l=(*itx).fi;
                        r=(*itx).se;
                    }
                }
                if (v==v2)
                {
                    f=false;
                    l2=n+1;
                    for (int i=0; i<26; i++)
                        if (i!=v)
                    {
                        auto it2=stx[i].lower_bound({l+1, 0});
                        if (it2==stx[i].end())
                            continue;
                        if ((*it2).fi<l2)
                        {
                            l2=(*it2).fi;
                            r2=(*it2).se;
                            v2=i;
                        }
                    }
                    auto itx=prev(stx[v].lower_bound({l2, r2}));
                    l=(*itx).fi;
                    r=(*itx).se;
                }
                if (!f)
                    cut(l, r, v, l2, r2, v2);
                else
                    cut(l2, r2, v2, l, r, v);
            }
        }
        for (int i:non)
            for (auto pa:stx[i])
                for (int q=pa.fi; q<pa.se; q++)
                    del(q, q);
        del(1, n);
        cout<<ans.size()<<"\n";
        for (auto pa:ans)
            cout<<pa.fi<<" "<<pa.se<<"\n";
    }
}