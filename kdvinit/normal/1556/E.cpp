/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

class Segment_Tree1
{
private:
    int st_n;      //Size of array
    int *st_t;     //Segment Tree

public:
    //Kindly change only this part
    /***It can be any Associative operator (eg: +, *, max, min, gcd, xor)***/
    inline int combine(int xx, int yy) { return max(xx, yy); }

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

class Segment_Tree2
{
private:
    int st_n;      //Size of array
    int *st_t;     //Segment Tree

public:
    //Kindly change only this part
    /***It can be any Associative operator (eg: +, *, max, min, gcd, xor)***/
    inline int combine(int xx, int yy) { return min(xx, yy); }

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

    Segment_Tree2(int st_array[], int st_array_size) { st_n = st_array_size; st_t = new int[(4*st_n)]; build(st_array, 1, 1, st_n); }     //Constructor
    ~Segment_Tree2() { delete[] st_t; }        //Destructor

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

void solve()
{
    int n, q;
    cin>>n>>q;

    int a[n+2]={0}, b[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    for(int i=1; i<=n; i++) a[i]-=b[i];

    for(int i=n-1; i>=1; i--) a[i]+=a[i+1];

    Segment_Tree1 st1(a, n);
    Segment_Tree2 st2(a, n);

    while(q--)
    {
        int l, r;
        cin>>l>>r;

        int sum = a[l]-a[r+1];
        int mn = st2.query(l, r)-a[r+1];
        int mx = st1.query(l, r)-a[r+1];

        if(sum!=0 || mn<0) cout<<-1<<"\n";
        else cout<<mx<<"\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}