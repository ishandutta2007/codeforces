/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

//Segment_Tree1
//Range Query And Node Update (replace a[pos] = new_val)
//For any associative operator (+, *, max, min, gcd, xor)
//Use .update(pos, new_val) and .query(l, r)
class Segment_Tree1
{
private:
    int n;      //Size of array
    int *t;     //Segment Tree

public:
    //Kindly change only this part
    inline int combine(int xx, int yy) { return min(xx, yy); }

    void build(int a[], int v, int tl, int tr)
    {
        if(tl==tr) t[v]=a[tl];
        else
        {
            int tm = (tl+tr)/2;
            build(a, 2*v, tl, tm);
            build(a, 2*v+1, tm+1, tr);
            t[v] = combine(t[2*v], t[2*v+1]);
        }
    }

    Segment_Tree1(int array[], int array_size) { n = array_size; t = new int[(4*n)]; build(array, 1, 1, n); }
    ~Segment_Tree1() { delete[] t; }

    int get_query(int v, int tl, int tr, int l, int r)
    {
        if(l==tl && r==tr) return t[v];
        int tm = (tl+tr)/2;
        if(l<=tm && tm<r) return combine(get_query(2*v, tl, tm, l, tm), get_query(2*v+1, tm+1, tr, tm+1, r));
        else if(tm<l) return get_query(2*v+1, tm+1, tr, l, r);
        else return get_query(2*v, tl, tm, l, r);
    }

    int query(int l, int r)     //Combine value of a[l...r]
    {
        if(l>r || l<1 || r>n) { cout<<"Invalid Query\n"; return -1; }
        return get_query(1, 1, n, l, r);
    }

    void get_update(int v, int tl, int tr, int pos, int new_val)
    {
        if(tl==tr) t[v]=new_val;
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


void solve()
{
    int n, q;
    cin>>n>>q;

    int mr[n+1];
    for(int i=1; i<=n; i++) mr[i]=n+1;

    int val[n+1];
    for(int i=1; i<=n; i++) val[i]=1;

    Segment_Tree5 st1(val, n);
    Segment_Tree1 st2(mr, n);

    while(q--)
    {
        int t; cin>>t;

        if(t==0)
        {
            int l, r, x;
            cin>>l>>r>>x;

            if(x==0)
            {
                st1.update(l, r, 0);
            }
            else
            {
                mr[l]=min(mr[l], r);
                st2.update(l, mr[l]);
            }
        }
        else
        {
            int j; cin>>j;

            int cur = st1.query(j, j);
            if(cur==0)
            {
                cout<<"NO"<<endl;
                continue;
            }

            cur = st1.query(1, j)-1;

            int mnl;
            int mxr;

            if(cur==0) mnl=1;
            else
            {
                int l=0, r=j-1;       //(1, l)<cur && (1, r)==cur
                while(l+1<r)
                {
                    int mid=(l+r)/2;
                    if(st1.query(1, mid)==cur) r=mid;
                    else l=mid;
                }
                mnl=r+1;
            }

            cur++;
            int cur2 = st1.query(1, n);

            if(cur==cur2) mxr=n;
            else
            {
                int l=j, r=n;       //(1, l)<cur && (1, r)==cur
                while(l+1<r)
                {
                    int mid=(l+r)/2;
                    if(st1.query(1, mid)==cur) l=mid;
                    else r=mid;
                }
                mxr=l;
            }

            int tmpr = st2.query(mnl, j);

            if(tmpr<=mxr) cout<<"YES"<<endl;
            else cout<<"N/A"<<endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}