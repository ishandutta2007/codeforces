#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

struct Node{ int value, index; };

Node combine(Node xx, Node yy)
{
    if(xx.value>yy.value) return xx;
    else return yy;
}

class Segment_Tree3
{
private:
    int n;      //Size of array
    Node *t;     //Segment Tree
    Node *lazy;
    bool *marked;

public:
    //Kindly change only this part
    //It can be either max or min

    void build(int v, int tl, int tr)      //Builds the main Segment Tree
    {
        marked[v]=false;
        if(tl==tr) t[v].value=0, t[v].index=-1;
        else
        {
            int tm = (tl+tr)/2;
            build(2*v, tl, tm);
            build(2*v+1, tm+1, tr);
            t[v] = combine(t[2*v], t[2*v+1]);
        }
    }

    Segment_Tree3(int siz) { n = siz; t = new Node[(4*n)]; lazy = new Node[(4*n)]; marked = new bool[(4*n)]; build(1, 1, n); }     //Constructor
    ~Segment_Tree3() { delete[] t; delete[] lazy; delete[] marked; }        //Destructor

    void push(int v)
    {
        if(marked[v]==false) return;
        t[v*2] = lazy[v]; lazy[v*2] = lazy[v]; marked[v*2] = true;
        t[v*2+1] = lazy[v]; lazy[v*2+1] = lazy[v]; marked[v*2+1] = true;
        marked[v]=false;
    }

    void get_update(int v, int tl, int tr, int l, int r, Node new_val)
    {
        if(l==tl && r==tr) { t[v]=new_val; lazy[v]=new_val; marked[v]=true; return; }
        push(v); int tm = (tl+tr)/2;
        if(l<=tm && tm<r)
        {
            get_update(2*v, tl, tm, l, tm, new_val);
            get_update(2*v+1, tm+1, tr, tm+1, r, new_val);
        }
        else if(tm<l) get_update(2*v+1, tm+1, tr, l, r, new_val);
        else get_update(2*v, tl, tm, l, r, new_val);
        t[v] = combine(t[2*v], t[2*v+1]);
    }

    void update(int l, int r, Node new_val)   //add (addend) to all elements of range a[l...r]
    {
        //Note that this would not change the value in the original array
        if(l>r || l<1 || r>n) cout<<"Invalid query for Update\n";
        else get_update(1, 1, n, l, r, new_val);
    }

    Node get_query(int v, int tl, int tr, int l, int r)
    {
        if(l==tl && r==tr) return t[v];
        push(v);  int tm = (tl+tr)/2;
        if(l<=tm && tm<r) return combine(get_query(2*v, tl, tm, l, tm), get_query(2*v+1, tm+1, tr, tm+1, r));
        else if(tm<l) return get_query(2*v+1, tm+1, tr, l, r);
        else return get_query(2*v, tl, tm, l, r);
    }

    Node query(int l, int r)     //Combine value of a[l...r]
    {
        if(l>r || l<1 || r>n) { cout<<"Invalid Query\n"; }
        return get_query(1, 1, n, l, r);
    }
};

void solve()
{
    int n, m, cnt=0;
    cin>>n>>m;

    array<int, 3> trip[m+1];
    set<int> comp; map<int, int> ni;

    for(int i=1; i<=m; i++)
    {
        int j, l, r; cin>>j>>l>>r;
        trip[i]={j, l, r};
        comp.insert(l); comp.insert(r);
    }

    for(int x: comp) ni[x]=(++cnt);

    vector<pair<int, int>> seg[n+1];
    for(int i=1; i<=m; i++)
    {
        int j = trip[i][0]; int l = ni[trip[i][1]]; int r = ni[trip[i][2]];
        seg[j].push_back({l, r});
    }

    Segment_Tree3 st(cnt);

    Node ans;   ans.value=-1; ans.index=-1;
    int prv[n+1];

    for(int i=1; i<=n; i++)
    {
        Node cur; cur.value=-1, cur.index=-1;
        for(pair<int, int> x: seg[i])
        {
            int l = x.first;
            int r = x.second;
            cur = combine(cur, st.query(l, r));
            //cout<<"getting from: "<<l<<" "<<r<<endl;
        }

        //cout<<i<<" -> "<<cur.value<<", "<<cur.index<<endl;

        cur.value++; prv[i]=cur.index;
        cur.index=i;

        ans = combine(ans, cur);

        for(pair<int, int> x: seg[i])
        {
            int l = x.first;
            int r = x.second;
            st.update(l, r, cur);
            //cout<<"maximising: "<<l<<" "<<r<<endl;
        }
    }

    int lst=ans.index;

    set<int> ind;
    for(int i=1; i<=n; i++) ind.insert(i);

    while(lst!=-1) { ind.erase(lst); lst = prv[lst]; }

    cout<<ind.size()<<endl;
    for(int x: ind) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}