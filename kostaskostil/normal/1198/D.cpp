#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

int n;
vector<vector<int> > a;

int p[2500];
int mnx[2500];
int mny[2500];
int mxx[2500];
int mxy[2500];
void init()
{
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            int q=n*i+j;
            p[q]=q;
            mnx[q]=mxx[q]=i;
            mny[q]=mxy[q]=j;
        }
}
int get(int v)
{
    if (v==p[v])
        return v;
    return p[v]=get(p[v]);
}
void upd(int u, int v)
{
    u=get(u);
    v=get(v);
    if (rand()%2)
        swap(u, v);
    p[v]=u;
    mnx[u]=min(mnx[u], mnx[v]);
    mny[u]=min(mny[u], mny[v]);
    mxx[u]=max(mxx[u], mxx[v]);
    mxy[u]=max(mxy[u], mxy[v]);
    int l=max(mxx[u]-mnx[u], mxy[u]-mny[u]);
    mxx[u]=max(mxx[u], l);
    mxy[u]=max(mxy[u], l);
    mnx[u]=min(mnx[u], n-1-l);
    mny[u]=min(mny[u], n-1-l);
}
int calc(set<int> &s)
{
    int ans=0;
    for (int i:s)
        ans+=max(mxx[i]-mnx[i], mxy[i]-mny[i])+1;
    return ans;
}
int setrand(set<int> &s)
{
    int c=rand()%s.size();
    for (int i:s)
    {
        if (c==0)
            return i;
        c--;
    }
}
int dist(int i, int j)
{
    return abs(mxx[i]+mnx[i] - mxx[j]-mnx[j])+
           abs(mxy[i]+mny[i] - mxy[j]-mny[j]);
}

int try_()
{
    set<int> s;
    init();
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (a[i][j])
                s.insert(n*i+j);
    if (s.size()==0)
        return 0;

    int ans=1e9;
    while (true)
    {
        while (true)
        {
            int q=s.size();
            for (int i:s)
                for (int j:s)
                    if (i!=j)
            {
                if ( ((mnx[i]<=mxx[j]+1) and (mxx[i]>=mnx[j]-1)) and
                     ((mny[i]<=mxy[j]+1) and (mxy[i]>=mny[j]-1)) )
                        upd(i, j);
            }
            s.clear();
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    if (a[i][j])
                        s.insert(get(n*i+j));
            if (s.size()==q)
                break;
        }
        ans=min(ans, calc(s));
        if (s.size()==1)
            break;

        int s1=setrand(s);
        int s2=setrand(s);
        while (s1==s2)
            s1=setrand(s), s2=setrand(s);
        for (int i=1; i<=20; i++)
        {
            int x1=setrand(s);
            int x2=setrand(s);
            if (x1==x2)
                continue;
            if (dist(x1, x2) < dist(s1, s2))
                s1=x1, s2=x2;
        }
        upd(s1, s2);

        s.clear();
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (a[i][j])
                    s.insert(get(n*i+j));

    }
    return ans;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    cin>>n;
    a.resize(n);
    for (int i=0; i<n; i++)
        a[i].resize(n);

    for (int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        for (int j=0; j<n; j++)
            a[i][j]=(s[j]=='#');
    }
    int ans=n;
    while (clock()*1.0/CLOCKS_PER_SEC < 0.5)
        ans=min(ans, try_());
    cout<<ans<<"\n";
}