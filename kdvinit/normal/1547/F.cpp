/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int GCD(int x, int y)
{
    if(y==0) return x;
    else return GCD(y, x%y);
}

class Segment_Tree1
{
private:
    int st_n;      //Size of array
    int *st_t;     //Segment Tree

public:
    //Kindly change only this part
    /***It can be any Associative operator (eg: +, *, max, min, gcd, xor)***/
    int combine(int xx, int yy) { return GCD(xx, yy); }

    void build(int st_a[], int st_v, int st_tl, int st_tr)      //Builds the main Segment Tree
    {
        if(st_tl==st_tr) st_t[st_v]=st_a[st_tl];
        else
        {
            int st_tm = (st_tl+st_tr)/2;
            build(st_a, 2*st_v, st_tl, st_tm);
            build(st_a, 2*st_v+1, st_tm+1, st_tr);
            st_t[st_v] = combine(st_t[2*st_v], st_t[2*st_v+1]);
        }
    }

    Segment_Tree1(int st_array[], int st_array_size) { st_n = st_array_size; st_t = new int[(4*st_n)]; build(st_array, 1, 1, st_n); }     //Constructor
    ~Segment_Tree1() { delete[] st_t; }        //Destructor

    int get_query(int st_v, int st_tl, int st_tr, int st_l, int st_r)
    {
        if(st_l==st_tl && st_r==st_tr) return st_t[st_v];
        int st_tm = (st_tl+st_tr)/2;
        if(st_l<=st_tm && st_tm<st_r) return combine(get_query(2*st_v, st_tl, st_tm, st_l, st_tm), get_query(2*st_v+1, st_tm+1, st_tr, st_tm+1, st_r));
        else if(st_tm<st_l) return get_query(2*st_v+1, st_tm+1, st_tr, st_l, st_r);
        else return get_query(2*st_v, st_tl, st_tm, st_l, st_r);
    }

    int query(int st_l, int st_r)     //Combine value of a[l...r]
    {
        if(st_l>st_r || st_l<1 || st_r>st_n) { cout<<"Invalid Query\n"; return -1; }
        return get_query(1, 1, st_n, st_l, st_r);
    }

    void get_update(int st_v, int st_tl, int st_tr, int st_pos, int st_new_val)
    {
        if(st_tl==st_tr) st_t[st_v]=st_new_val;
        else
        {
            int st_tm = (st_tl+st_tr)/2;
            if(st_pos<=st_tm) get_update(2*st_v, st_tl, st_tm, st_pos, st_new_val);
            else get_update(2*st_v+1, st_tm+1, st_tr, st_pos, st_new_val);
            st_t[st_v] = combine(st_t[2*st_v], st_t[2*st_v+1]);
        }
    }

    void update(int st_pos, int st_new_val)   //update a[pos]=new_val
    {
        //Note that this would not change the value in the original array
        if(st_pos<1 || st_pos>st_n) cout<<"Invalid Update\n";
        else get_update(1, 1, st_n, st_pos, st_new_val);
    }
};

/**
Change the combine function as per your need
The opertor used should be associative (eg: +, *, max, min, gcd, xor)

There are only 2 functions for user
    1) query(l, r) gets the combine value of a[l...r]
    2) update(pos, new_val) changes a[pos] = new_val
Note the update would only update in tree and not in the original array
**/

void solve()
{
    int n;
    cin>>n;

    int a[n+1], g=0;
    for(int i=1; i<=n; i++) { cin>>a[i]; g=GCD(g, a[i]); }

    int all1=1;
    for(int i=1; i<=n; i++)
    {
        a[i]/=g;
        if(a[i]!=1) all1=0;
    }

    if(all1) { cout<<0<<endl; return; }

    int b[2*n+1];
    for(int i=1; i<=n; i++) b[i]=a[i], b[n+i]=a[i];

    Segment_Tree1 st1(b, (2*n));

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==1) continue;
        int l=i, r=(2*n);
        while(l+1!=r)
        {
            int mid = (l+r)/2;
            g = st1.query(i, mid);
            if(g==1) r=mid;
            else l=mid;
        }
        int tmp = r-i;
        ans = max(ans, tmp);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}