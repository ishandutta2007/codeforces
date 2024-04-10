/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

const int N = 2e5+100;
int f[N+1];

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
        if(l>r || l<1 || r>n) cout<<"Invalid query for Update\n";
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

int fst1(int k, Segment_Tree5& st)
{
    int l=k;
    int r=N;

    while(l+1!=r)
    {
        int mid = (l+r)/2;
        int cur = st.query(l, mid);
        if(cur>0) r=mid;
        else l=mid;
    }

    return r;
}

int fst0(int k, Segment_Tree5& st)
{
    int l=k;
    int r=N;

    while(l+1!=r)
    {
        int mid = (l+r)/2;
        int cur = st.query(l, mid);
        int len = mid-l+1;

        if(cur<len) r=mid;
        else l=mid;
    }

    return r;
}

void sub(int k, Segment_Tree5& st)
{
    int cur = st.query(k, k);
    if(cur==1)
    {
        st.update(k, k, 0);
        return;
    }

    int r = fst1(k, st);
    st.update(r, r, 0);
    st.update(k, r-1, 1);

    return;
}

void add(int k, Segment_Tree5& st)
{
    int cur = st.query(k, k);

    if(cur==0)
    {
        st.update(k, k, 1);
        return;
    }

    int r = fst0(k, st);
    st.update(r, r, 1);
    st.update(k, r-1, 0);

    return;
}

void print_max(Segment_Tree5& st)
{
    int sum=st.query(1, N);

    int l=0;
    int r=N;

    while(l+1!=r)
    {
        int mid = (l+r)/2;
        int cur = st.query(1, mid);
        if(cur==sum) r=mid;
        else l=mid;
    }

    cout<<r<<endl;
    return;
}

void print_st(int n, Segment_Tree5& st)
{
    for(int i=1; i<=n; i++) cout<<st.query(i, i)<<" ";
    cout<<endl;
}

void solve()
{
    int n, q;
    cin>>n>>q;

    for(int i=1; i<=N; i++) f[i]=0;

    int a[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        f[a[i]]++;
    }

    for(int i=1; i<=N; i++)
    {
        int x=f[i]/2;
        f[i]=f[i]%2;
        if(x!=0) f[i+1]+=x;
    }

    Segment_Tree5 st(f, N);

    for(int i=1; i<=q; i++)
    {
        int k, l;
        cin>>k>>l;
        sub(a[k], st);
        add(l, st);
        a[k]=l;
        print_max(st);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}