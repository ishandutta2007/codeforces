#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;

const int NMAX=2e5+100;

int n, m, k;
vector<int> g[2*NMAX];
int used[2*NMAX];
int l[2*NMAX];

void bfs()
{
    queue<int> q;
    for (int i=0; i<m+n; i++)
        l[i]=-1;
    for (int i=0; i<n; i++)
        if (used[i]==-1)
            q.push(i), l[i]=0;

    k=1e9;
    while (!q.empty())
    {
        int v=q.front();
        if (l[v]>=k)
            return;

        if (l[v]%2==0)
        {
            for (int i:g[v])
                if (l[i]==-1)
            {
                q.push(i);
                l[i]=l[v]+1;
                if (used[i]==-1)
                    k=l[i];
            }
        }
        else
            if (l[used[v]]==-1)
        {
            if (used[v]==-1)
                cout<<"WARNING\n";
            l[used[v]]=l[v]+1;
            q.push(used[v]);
        }

        q.pop();
    }
}

bool dfs(int v)
{
    if (v==-1)
        return true;
    for (int to:g[v])
        if ((used[to]==-1) or (l[used[to]]==l[v]-2))
            if (dfs(used[to]))
            {
                used[to]=v;
                used[v]=to;
                return true;
            }
    l[v]=-1;
    return false;
}

void SARA()
{
    for (int i=0; i<n+m; i++)
        used[i]=-1;
    while (true)
    {
        bfs();
        if (k==1e9)
            break;
        for (int i=0; i<m+n; i++)
            if ((l[i]==k) and (used[i]==-1))
                dfs(i);
    }
}

void add_edge(int i, int j)
{
    g[i-1].pb(n+j-1);
    g[n+j-1].pb(i-1);
}

int N;
int lt[NMAX];
int rt[NMAX];
set<vector<int> > answers;

void add(vector<int> ans)
{
    answers.insert(ans);
    if (answers.size()>1)
    {
        cout<<"NO\n";
        for (auto it=answers.begin(); it!=answers.end(); it++, cout<<"\n")
            for (int i:*it)
                cout<<i<<" ";
        exit(0);
    }
}

void try_()
{
    for (int i=0; i<2*N; i++)
        g[i].clear();
    vector<int> pr;
    for (int i=1; i<=n; i++)
        pr.pb(i);
    random_shuffle(pr.begin(), pr.end());
    vector<int> bck(n);
    for (int i=0; i<n; i++)
        bck[pr[i]-1]=i+1;

    for (int i=1; i<=N; i++)
    {
        if (rt[i]-lt[i]<6)
            for (int j=lt[i]; j<=rt[i]; j++)
                add_edge(pr[i-1], pr[j-1]);
        else
        {
            set<int> st;
            while (st.size()<5)
                st.insert(rand()%(rt[i]-lt[i]+1) + lt[i]);
            for (int j:st)
                add_edge(pr[i-1], pr[j-1]);
        }
    }

    SARA();
    int q=0;
    for (int i=0; i<n; i++)
        if (used[i]!=-1)
            q++;
    if (q<n)
        return;
    vector<int> ans(n);
    for (int i=0; i<n; i++)
        ans[i]=bck[used[pr[i]-1]-n];
    add(ans);
}

void gridi()
{
    vector<int> ans(n);
    set<pair<pair<int, int>, int> > st;
    set<pair<int, int> > bef;

    for (int i=1; i<=n; i++)
        st.insert({{lt[i], rt[i]}, i-1});
    for (int i=1; i<=n; i++)
    {
        while ( (st.size()>0) and ((*st.begin()).fi.fi <= i) )
        {
            bef.insert({(*st.begin()).fi.se, (*st.begin()).se});
            st.erase(st.begin());
        }
        if (bef.size()==0)
            return;
        ans[(*bef.begin()).se]=i;
        bef.erase(bef.begin());
    }
    add(ans);
}

void gridi2()
{
    for (int i=1; i<=n; i++)
        lt[i]=n+1-lt[i], rt[i]=n+1-rt[i], swap(lt[i], rt[i]);
    vector<int> ans(n);
    set<pair<pair<int, int>, int> > st;
    set<pair<int, int> > bef;

    for (int i=1; i<=n; i++)
        st.insert({{lt[i], rt[i]}, i-1});
    for (int i=1; i<=n; i++)
    {
        while ( (st.size()>0) and ((*st.begin()).fi.fi <= i) )
        {
            bef.insert({(*st.begin()).fi.se, (*st.begin()).se});
            st.erase(st.begin());
        }
        if (bef.size()==0)
        {
            for (int i=1; i<=n; i++)
                lt[i]=n+1-lt[i], rt[i]=n+1-rt[i], swap(lt[i], rt[i]);
            return;
        }
        ans[(*bef.begin()).se]=i;
        bef.erase(bef.begin());
    }

    for (int i=1; i<=n; i++)
        lt[i]=n+1-lt[i], rt[i]=n+1-rt[i], swap(lt[i], rt[i]);
    for (int& i:ans)
        i=n+1-i;
    add(ans);
}

void gridi3()
{
    vector<int> ans(n);
    set<pair<pair<int, int>, int> > st;
    set<pair<int, int> > bef;

    for (int i=1; i<=n; i++)
        st.insert({{lt[i], rt[i]}, -i+1});
    for (int i=1; i<=n; i++)
    {
        while ( (st.size()>0) and ((*st.begin()).fi.fi <= i) )
        {
            bef.insert({(*st.begin()).fi.se, (*st.begin()).se});
            st.erase(st.begin());
        }
        if (bef.size()==0)
            return;
        ans[-(*bef.begin()).se]=i;
        bef.erase(bef.begin());
    }
    add(ans);
}

void gridi4()
{
    for (int i=1; i<=n; i++)
        lt[i]=n+1-lt[i], rt[i]=n+1-rt[i], swap(lt[i], rt[i]);
    vector<int> ans(n);
    set<pair<pair<int, int>, int> > st;
    set<pair<int, int> > bef;

    for (int i=1; i<=n; i++)
        st.insert({{lt[i], rt[i]}, -i+1});
    for (int i=1; i<=n; i++)
    {
        while ( (st.size()>0) and ((*st.begin()).fi.fi <= i) )
        {
            bef.insert({(*st.begin()).fi.se, (*st.begin()).se});
            st.erase(st.begin());
        }
        if (bef.size()==0)
        {
            for (int i=1; i<=n; i++)
                lt[i]=n+1-lt[i], rt[i]=n+1-rt[i], swap(lt[i], rt[i]);
            return;
        }
        ans[-(*bef.begin()).se]=i;
        bef.erase(bef.begin());
    }

    for (int i=1; i<=n; i++)
        lt[i]=n+1-lt[i], rt[i]=n+1-rt[i], swap(lt[i], rt[i]);
    for (int& i:ans)
        i=n+1-i;
    add(ans);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    cin>>N;
    for (int i=1; i<=N; i++)
        cin>>lt[i]>>rt[i];
    n=m=N;
/*
4
2 4
1 3
1 2
2 3
*/
    gridi();
    gridi2();
    gridi3();
    gridi4();
    while (clock()*1.0/CLOCKS_PER_SEC < 0.5)
        try_();
    cout<<"YES\n";
    if (answers.empty())
        cout<<1/0;
    for (int i:(*answers.begin()))
        cout<<i<<" ";
    cout<<"\n";
    return 0;
}