/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

//Segment_Tree5
//Range Query And Range Update (replace all in a[l....r] with new_val)
//Can only perform addition (with or without modulo)
//Use .update(l, r, new_val) and .query(l, r)
class Segment_Tree5
{
private:
    int n;      //Size of array (1 Indexed)
    int *t;     //Segment Tree
    int *lazy;
    int *len;
    bool *marked;

public:
    //Kindly note it can only do addition (with or without modulo)
    inline int combine(int xx, int yy) { return (xx+yy); }

    void build(int a[], int v, int tl, int tr)
    {
        lazy[v]=0;    marked[v]=false;  len[v]=(tr-tl+1);
        if(tl==tr) t[v]=a[tl];
        else
        {
            int tm = (tl+tr)/2;
            build(a, 2*v, tl, tm);
            build(a, 2*v+1, tm+1, tr);
            t[v] = combine(t[2*v], t[2*v+1]);
        }
    }

    Segment_Tree5(int arr[], int siz) { n=siz; t=new int[(4*n)]; lazy=new int[(4*n)]; len=new int[(4*n)]; marked=new bool[(4*n)]; build(arr, 1, 1, n); }
    ~Segment_Tree5() { delete[] t; delete[] lazy; delete[] len; delete[] marked; }

    void push(int v)
    {
        if(marked[v]==false) return;
        t[v*2]=(lazy[v]*len[2*v]); lazy[v*2]=lazy[v]; marked[v*2]=true;
        t[v*2+1]=(lazy[v]*len[2*v+1]); lazy[v*2+1]=lazy[v]; marked[v*2+1]=true;
        lazy[v]=0;  marked[v]=false;
    }

    void get_update(int v, int tl, int tr, int l, int r, int new_val)
    {
        if(l==tl && r==tr) { t[v]=(new_val*len[v]); lazy[v]=new_val; marked[v]=true; return; }
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

    void update(int l, int r, int new_val)      //replaces all elements in a[l...r] with new_val
    {
        //Note that this would not change the value in the original array
        if(l>r || l<1 || r>n) return;
        else get_update(1, 1, n, l, r, new_val);
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

int st_find(int n, Segment_Tree5& st, int x)
{
    int y = st.query(n, n);
    if(y>=x) return n;

    int l=0;        //always>=x
    int r=n;        //always<x

    while(l+1!=r)
    {
        int mid = (l+r)/2;
        y = st.query(mid, mid);
        if(y>=x) l=mid;
        else r=mid;
    }
    return l;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int b[n+1]={0}, c[n+1]={0};
    b[1]=a[1];  c[1]=1;

    for(int i=2; i<=n; i++)
    {
        b[i]=a[i];
        if(b[i-1]>b[i]) c[i]=1;
        else b[i]=b[i-1];
    }

    Segment_Tree5 sb(b, n);
    Segment_Tree5 sc(c, n);

    int ans;
    for(int i=1; i<=m; i++)
    {
        int j, d;
        cin>>j>>d;

        a[j]-=d;
        if(a[j]>=sb.query(j, j))
        {
            ans = sc.query(1, n);
            cout<<ans<<" ";
            continue;
        }


        int r = st_find(n, sb, a[j]);
        sb.update(j, r, a[j]);
        sc.update(j, j, 1);
        sc.update(j+1, r, 0);

        ans = sc.query(1, n);
        cout<<ans<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}