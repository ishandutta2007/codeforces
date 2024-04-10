/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define endl "\n"

int n, m;
vector < array<int, 3> > edges;

const int mxn = 1000;

int parent[mxn];
int siz[mxn];

//use make_set, find_set and union_sets properly
void make_set(int v)
{
    parent[v] = v;
    siz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b) return true;
    if (siz[a] < siz[b]) swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
    return false;
}

int ff;

int eval(int x)
{
    for(int i=1; i<=n; i++) make_set(i);
    priority_queue<array<int, 4>> pq;

    for(auto e: edges)
    {
        int w = abs(e[0]-x);

        int y = -1;
        if(e[0]>=x) y=1;

        pq.push({-w, -y, e[1], e[2]});
    }

    int cost=0;
    ff=0;

    while(!pq.empty())
    {
        auto e = pq.top();
        pq.pop();

        int w = -e[0];
        int u = e[2];
        int v = e[3];

        if(union_sets(u, v)) continue;
        ff-=e[1];
        cost+=w;
    }

    return cost;
}

vector<int> ww, dp, fact;
int lst, nn;

long long int fast_eval(int x)
{
    if(x>=lst) return (dp[nn-1]+((x-ww[nn-1])*(n-1)));
    int i = lower_bound(ww.begin(), ww.end(), x) - ww.begin();
    //cout<<x<<" => "<<i<<" "<<ww[i]<<" "<<dp[i]<<" "<<fact[i]<<endl;

    long long int tmp = (ww[i]-x);
    tmp = tmp*fact[i];

    long long int cost = dp[i] + tmp;
    return cost;
}

void solve()
{
    cin>>n>>m;
    set<int> st;

    for(int i=1; i<=m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back({w, u, v});
        st.insert(w);
        ww.push_back(w);
    }

    sort(ww.begin(), ww.end());

    for(int i=0; i+1<m; i++)
    {
        int base = ww[i];
        int upp = ww[i+1];
        for(int j=0; j<=i; j++)
        {
            for(int k=i+1; k<m; k++)
            {
                int cura = ww[i] - ww[j];
                int curb = ww[k] - ww[i];
                //cout<<ww[i]<<" ==> "<<ww[j]<<" " <<ww[k]<<endl;
                if(cura>=curb) continue;
                int del = (curb - cura +1)/2;
                int nw = base + del;
                //cout<<ww[i]<<" ==> "<<ww[j]<<" " <<ww[k]<<" -> "<<nw<<endl;
                if(nw<upp) st.insert(nw);
            }
        }
    }

    set<int> st2;
    for(int x: st)
    {
        if(x>0) st2.insert(x-1);
        st2.insert(x);
        //st2.insert(x+1);
    }

    ww.clear();
    for(int x: st2) ww.push_back(x);

    lst = ww.back();
    nn = ww.size();

//    cout<<"ww:"<<endl;
//    for(int i=0; i<nn; i++) cout<<ww[i]<<" ";
//    cout<<endl<<endl;

    for(int i=0; i<ww.size(); i++)
    {
        int x = ww[i];
        int y = eval(x);
        dp.push_back(y);
        fact.push_back(ff);
    }

    long long int p, k, a, b, c, lst;
    cin>>p>>k>>a>>b>>c;

    long long int xr=0;

/*
3 3
1 2 50
2 3 100
1 3 150
5 5 1 1 1
71 50 3 1 0
*/

    for(int i=1; i<=p; i++)
    {
        long long int x; cin>>x;  lst=x;
        long long int y = fast_eval(x);
        xr^=y;
        //cout<<i<<" -> "<<x<<" "<<y<<endl;
    }

    for(int i=p+1; i<=k; i++)
    {
        long long int x = (lst*a + b)%c;      lst=x;
        long long int y = fast_eval(x);
        xr^=y;
        //cout<<i<<" -> "<<x<<" "<<y<<endl;
    }

    cout<<xr<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}