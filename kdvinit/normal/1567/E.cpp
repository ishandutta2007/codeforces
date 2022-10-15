/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

//Segment_Tree1
//Range Query And Node Update (replace a[pos] = new_val)
//For any associative operator (+, *, max, min, gcd, xor)
//Use .update(pos, new_val) and .query(l, r)

struct Node
{
    long long int cnt;
    int pre, suf, ff, ll, all;
};

class Segment_Tree1
{
private:
    int n;      //Size of array
    Node *t;     //Segment Tree

public:
    //Kindly change only this part
    Node combine(Node xx, Node yy)
    {
        Node zz;
        zz.ff=xx.ff;    zz.ll=yy.ll;    zz.all=0;
        zz.cnt = (xx.cnt+yy.cnt);   zz.pre=xx.pre;      zz.suf=yy.suf;

        if(xx.ll>yy.ff) return zz;

        long long int tmp = xx.suf;
        tmp*=yy.pre;
        zz.cnt+=tmp;

        if(xx.all!=0 && yy.all!=0) zz.all=(xx.all+yy.all);
        if(xx.all!=0) zz.pre=xx.all+yy.pre;
        if(yy.all!=0) zz.suf=yy.all+xx.suf;

        return zz;
    }

    void single_node(int v, int val)
    {
        t[v].cnt=1; t[v].pre=1; t[v].suf=1;
        t[v].all=1; t[v].ff=val; t[v].ll=val;
    }

    void build(int a[], int v, int tl, int tr)
    {
        if(tl==tr) single_node(v, a[tl]);
        else
        {
            int tm = (tl+tr)/2;
            build(a, 2*v, tl, tm);
            build(a, 2*v+1, tm+1, tr);
            t[v] = combine(t[2*v], t[2*v+1]);
        }
    }

    Segment_Tree1(int arr[], int siz) { n = siz; t = new Node[(4*n)]; build(arr, 1, 1, n); }
    ~Segment_Tree1() { delete[] t; }

    Node get_query(int v, int tl, int tr, int l, int r)
    {
        if(l==tl && r==tr) return t[v];
        int tm = (tl+tr)/2;
        if(l<=tm && tm<r) return combine(get_query(2*v, tl, tm, l, tm), get_query(2*v+1, tm+1, tr, tm+1, r));
        else if(tm<l) return get_query(2*v+1, tm+1, tr, l, r);
        else return get_query(2*v, tl, tm, l, r);
    }

    long long int query(int l, int r)     //Combine value of a[l...r]
    {
        if(l>r || l<1 || r>n) { cout<<"Invalid Query\n"; return -1; }
        return get_query(1, 1, n, l, r).cnt;
    }

    void get_update(int v, int tl, int tr, int pos, int new_val)
    {
        if(tl==tr) single_node(v, new_val);
        else
        {
            int tm = (tl+tr)/2;
            if(pos<=tm) get_update(2*v, tl, tm, pos, new_val);
            else get_update(2*v+1, tm+1, tr, pos, new_val);
            t[v] = combine(t[2*v], t[2*v+1]);
        }
    }

    void update(int pos, int new_val)   //update a[pos]=new_val
    {
        //Note that this would not change the value in the original array
        if(pos<1 || pos>n) cout<<"Invalid Update\n";
        else get_update(1, 1, n, pos, new_val);
    }
};

void solve()
{
    int n, q;
    cin>>n>>q;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    Segment_Tree1 st(a, n);

    while(q--)
    {
        int ty, l, r;
        cin>>ty>>l>>r;
        if(ty==1) st.update(l, r);
        else cout<<st.query(l, r)<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}