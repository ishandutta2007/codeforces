/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
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
    inline int combine(int xx, int yy) { return xx+yy; }

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

void solve()
{
    int n, q;
    cin>>n>>q;

    int cx[n+1]={0}, cy[n+1]={0};
    Segment_Tree1 stx(cx, n);
    Segment_Tree1 sty(cy, n);

    while(q--)
    {
        int t; cin>>t;

        if(t==1)
        {
            int x, y; cin>>x>>y;
            cx[x]++;
            cy[y]++;

            if(cx[x]==1) stx.update(x, 1);
            if(cy[y]==1) sty.update(y, 1);

        }
        if(t==2)
        {
            int x, y; cin>>x>>y;
            cx[x]--;
            cy[y]--;

            if(cx[x]==0) stx.update(x, 0);
            if(cy[y]==0) sty.update(y, 0);
        }
        if(t==3)
        {
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;

            int l1 = x2-x1+1;
            int c1 = stx.query(x1, x2);

            int l2 = y2-y1+1;
            int c2 = sty.query(y1, y2);

            if(l1==c1 || l2==c2) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}