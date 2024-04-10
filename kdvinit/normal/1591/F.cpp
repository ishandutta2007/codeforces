/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 998244353;
const int N = 2e5+100;
int w[N];

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
    inline int combine(int xx, int yy) { return (xx+yy)%mod; }

    void build(int a[], int v, int tl, int tr)
    {
        lazy[v]=0;    marked[v]=false;  len[v]=(w[tr]-w[tl-1])%mod;
        if(tl==tr) t[v]=(a[tl]*(w[tl]-w[tl-1]))%mod;
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
        t[v*2]=(lazy[v]*len[2*v])%mod; lazy[v*2]=lazy[v]; marked[v*2]=true;
        t[v*2+1]=(lazy[v]*len[2*v+1])%mod; lazy[v*2+1]=lazy[v]; marked[v*2+1]=true;
        lazy[v]=0;  marked[v]=false;
    }

    void get_update(int v, int tl, int tr, int l, int r, int new_val)
    {
        if(l==tl && r==tr) { t[v]=(new_val*len[v])%mod; lazy[v]=new_val; marked[v]=true; return; }
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
        if(l>r || l<1 || r>n) return; //cout<<"Invalid query for Update\n";
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


void solve()
{
    int n;
    cin>>n;

    set<int> stt;
    int a[n+1];
    for(int i=1; i<=n; i++) { cin>>a[i]; stt.insert(a[i]); }

    int cnt=0;
    map<int, int> comp, rev;
    for(int x: stt) { comp[x]=(++cnt); rev[cnt]=x; }

    comp[0]=0;
    rev[0]=0;
    for(int i=0; i<=cnt; i++) w[i]=rev[i];

    //for(int i=0; i<=cnt; i++) cout<<i<<" -> "<<rev[i]<<endl;

    int mx = cnt;
    for(int i=1; i<=n; i++) a[i]=comp[a[i]];

    int b[mx+1]={0};
    Segment_Tree5 st(b, mx);

    st.update(1, a[1], 1);

    int del=0, sn=1;
    for(int i=2; i<=n; i++)
    {
        int tot = ((del*w[mx])%mod + (sn*st.query(1, mx)))%mod;
        sn*=-1;
        del=(tot-del)%mod;
        st.update(a[i]+1, mx, del*sn*(-1));
    }

    int ans = ((del*w[mx])%mod + (sn*st.query(1, mx)))%mod;
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}