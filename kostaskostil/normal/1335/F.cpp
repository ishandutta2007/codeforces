#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second

const int nmax=1e6+100;

int a[nmax];
int nt[nmax];
int used[nmax];
vector<int> g[nmax];
vector<int> cyc;
bool debug=false;

void dfs(int v)
{
    if (debug)
    cout<<v<<" ";
    used[v]=1;
    int to=nt[v];
    if (used[to]==2)
    {
        used[v]=2;
        return;
    }
    if (used[to]==1)
    {
        if (debug)
        cout<<"<-here ";
        cyc.pb(to);
        used[v]=2;
        return;
    }
    dfs(to);
    used[v]=2;
    return;
}

vector<bool> if1;

void dfs1(int v, int r, int l, int d)
{
    if (a[v]==1)
        if1[l%d]=true;
    for (int i:g[v])
        if (i!=r)
            dfs1(i, r, l+1, d);
}

pair<int, int> analize(int v)
{
//    cout<<"here\n";
    int c=1;
    int to=nt[v];
    while (to!=v)
    {
        to=nt[to], c++;
//        cout<<to<<" "<<v<<"\n";
    }
    if1.assign(c, false);
    dfs1(v, v, 0, c);
    int cnt=0;
    for (bool b:if1)
        if (b)
            cnt++;
    return {c, cnt};
}

string rnd(int n, string s){
    string ans;
    for (int i=0; i<n; i++)
        ans.pb(s[rand()%s.size()]);
    return ans;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int i=0; i<t; i++)
    {
        int n, m;
        cin>>n>>m;
        cyc.clear();
        for (int i=0; i<n*m; i++)
            g[i].clear(), used[i]=0;
        for (int i=0; i<n; i++)
        {
            string s;
//            s=rnd(m, "01");
            cin>>s;
            for (int j=0; j<m; j++)
                a[i*m+j]=('1'-s[j]);
        }
        for (int i=0; i<n; i++)
        {
            string s;
//            if (i==0) s=rnd(m, "LRD");
//            if (i==n-1) s=rnd(m, "LRU");
//            if (s[0]=='L') s[0]='R';
//            if (s[m-1]=='R') s[m-1]='L';
            cin>>s;
            for (int j=0; j<m; j++)
            {
                int from=i*m+j;
                int to=from;
                if (s[j]=='U') to-=m;
                if (s[j]=='D') to+=m;
                if (s[j]=='L') to--;
                if (s[j]=='R') to++;
                g[to].pb(from);
                nt[from]=to;
            }
        }
        n*=m;
        for (int i=0; i<n; i++)
            if (used[i]==0)
            {
                dfs(i);
                if (debug)
                    cout<<"\n";
            }
        if (debug)
        {
            cout<<"CYC\n";
            for (int i:cyc)
                cout<<i<<" ";
            cout<<"\n";
            cout<<"Ended cycles\n";
        }
        int a1=0, a2=0;
        for (int i:cyc)
        {
            auto pa=analize(i);
            a1+=pa.fi;
            a2+=pa.se;
        }
        cout<<a1<<" "<<a2<<"\n";
    }
    return 0;
}