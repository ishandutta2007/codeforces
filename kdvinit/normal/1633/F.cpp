/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

//Segment_Tree4
//Range Query And Range Update (multiplies "mul" to all of a[l....r])
//Can only perform summation
//Use .update(l, r, mul) and .query(l, r)
class Segment_Tree4
{
private:
    int n;      //Size of array
    int *t;     //Segment Tree
    int *lazy;

public:
    //Kindly change only this part
    inline int combine(int xx, int yy) { return (xx+yy); }

    void build(int a[], int v, int tl, int tr)
    {
        lazy[v]=1;
        if(tl==tr) t[v]=a[tl];
        else
        {
            int tm = (tl+tr)/2;
            build(a, 2*v, tl, tm);
            build(a, 2*v+1, tm+1, tr);
            t[v] = combine(t[2*v], t[2*v+1]);
        }
    }

    Segment_Tree4(int arr[], int siz) { n=siz; t=new int[(4*n)]; lazy=new int[(4*n)]; build(arr, 1, 1, n); }
    ~Segment_Tree4() { delete[] t; delete[] lazy;}

    void push(int v)
    {
        t[v*2] *= lazy[v];
        lazy[v*2] *= lazy[v];
        t[v*2+1] *= lazy[v];
        lazy[v*2+1] *= lazy[v];
        lazy[v] = 1;
    }

    void get_update(int v, int tl, int tr, int l, int r, int mul)
    {
        if(l==tl && r==tr) { t[v]*=mul; lazy[v]*=mul; return; }
        push(v); int tm = (tl+tr)/2;
        if(l<=tm && tm<r)
        {
            get_update(2*v, tl, tm, l, tm, mul);
            get_update(2*v+1, tm+1, tr, tm+1, r, mul);
        }
        else if(tm<l) get_update(2*v+1, tm+1, tr, l, r, mul);
        else get_update(2*v, tl, tm, l, r, mul);
        t[v] = combine(t[2*v], t[2*v+1]);
    }

    void update(int l, int r, int mul)   //add (addend) to all elements of range a[l...r]
    {
        //Note that this would not change the value in the original array
        if(l>r || l<1 || r>n) cout<<"Invalid query for Update\n";
        else get_update(1, 1, n, l, r, mul);
    }

    int get_query(int v, int tl, int tr, int l, int r)
    {
        if(l==tl && r==tr) return t[v];
        push(v);  int tm = (tl+tr)/2;
        if(l<=tm && tm<r) return combine(get_query(2*v, tl, tm, l, tm), get_query(2*v+1, tm+1, tr, tm+1, r));
        else if(tm<l) return get_query(2*v+1, tm+1, tr, l, r);
        else return get_query(2*v, tl, tm, l, r);
    }

    int query(int l, int r)     //Combine value of a[l...r]
    {
        if(l>r || l<1 || r>n) { cout<<"Invalid Query\n"; return -1; }
        return get_query(1, 1, n, l, r);
    }
};

const int N = 2e5 + 100;
vector<pair<int, int>> adj[N];

int parent[N], depth[N], heavy[N], head[N], pos[N], weight[N], parity[N], act[N], weight2[N];
int cur_pos;

int dfs(int v)
{
    int siz = 1;
    int max_c_size = 0;
    for (auto x: adj[v])
    {
        int c = x.first;
        int w = x.second;

        if (c==parent[v]) continue;
        parent[c]=v, depth[c]=depth[v]+1, weight[c]=w;

        int c_size = dfs(c);
        siz += c_size;
        if (c_size > max_c_size) max_c_size=c_size, heavy[v]=c;
    }
    return siz;
}

void decompose(int v, int h)
{
    head[v]=h, pos[v]=++cur_pos;
    weight2[pos[v]]=weight[v];

    if (heavy[v] != -1) decompose(heavy[v], h);
    for (auto x: adj[v])
    {
        int c = x.first;
        if (c==parent[v] || c==heavy[v]) continue;
        decompose(c, c);
    }
}

void init(int n)
{
    for(int i=1; i<=n; i++) heavy[i]=-1, parity[i]=1, act[i]=0;
    cur_pos=0;

    parent[1]=-1, weight[1]=0, parity[1]=-1, act[1]=1;
    dfs(1);
    decompose(1, 1);
}

int ver_left, sum_tot;

void query1(int n, Segment_Tree4& st1, Segment_Tree4& st2)
{
    int v; cin>>v;
    act[v]=1;

    ver_left--;
    sum_tot+=v;

    int sum_left = ((n*(n-1))/2)-sum_tot;

    int cur=v;
    while(cur!=-1)
    {
        int h = head[cur];
        st1.update(pos[h], pos[cur], -1);
        st2.update(pos[h], pos[cur], -1);
        cur = parent[h];
    }

    int ver_dif = st1.query(1, n) - ver_left;
    int sum_even = (st2.query(1, n) - sum_left + sum_tot)/2;
    int sum_odd = sum_tot-sum_even;

    if(ver_dif==0) cout<<sum_odd<<endl;
    else cout<<0<<endl;
}

void query2(int n, Segment_Tree4& st1, Segment_Tree4& st2)
{
    int ver_dif = st1.query(1, n) - ver_left;

    if(ver_dif!=0) cout<<0<<endl;
    else
    {
        vector<int> edge;
        for(int i=1; i<=n; i++)
        {
            if(act[i]==0) continue;
            if(st1.query(pos[i], pos[i])==1) continue;
            edge.push_back(weight[i]);
        }
        sort(edge.begin(), edge.end());
        cout<<edge.size()<<" ";
        for(int x: edge) cout<<x<<" ";
        cout<<endl;
    }
}

void solve()
{
    int n; cin>>n;

    for(int i=1; i<n; i++)
    {
        int x, y;
        cin>>x>>y;
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
    }

    init(n);

    Segment_Tree4 st1(parity, n);
    Segment_Tree4 st2(weight2, n);

    ver_left = n-1;
    sum_tot = 1;

    while(1)
    {
        int typ;
        cin>>typ;

        if(typ==1) query1(n, st1, st2);
        if(typ==2) query2(n, st1, st2);
        if(typ==3) break;
    }
}

int32_t main()
{
    solve();
    return 0;
}