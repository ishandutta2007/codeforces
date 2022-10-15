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
        if(l>r || l<1 || r>n) return 0;
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
    int n, k;
    cin>>n>>k;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    map<int, int> mp;
    set<int> st;

    for(int i=1; i<=n; i++)
    {
        int x = a[i];
        mp[x]++;
        st.insert(x);
    }

    int totd = st.size();

    for(int i=0; i<=n; i++) st.insert(i);
    int m = st.size();

    vector<pair<int, int>> sp;
    for(int x: st)
    {
        sp.push_back({mp[x], x});
    }

    sort(sp.begin(), sp.end());

    map<int, int> ind;
    for(int i=0; i<sp.size(); i++)
    {
        int x = sp[i].second;
        ind[x]=i+1;
    }

    int dbef[n+1]={0};

    if(mp[0]) dbef[0]=1;
    for(int i=1; i<=n; i++)
    {
        dbef[i]=dbef[i-1];
        if(mp[i]) dbef[i]++;
    }

    int ans = totd;

    int lol[m+1]={0};
    Segment_Tree1 st1(lol, m);      //values
    Segment_Tree1 st2(lol, m);      //count

    for(int x: st)
    {
        if(x<=n) continue;
        int i = ind[x];
        st1.update(i, mp[x]);
        if(mp[x]!=0) st2.update(i, 1);
    }

    for(int mx=n; mx>=0; mx--)
    {
        int daft = totd - dbef[mx];
        int db = dbef[mx];
        if(mp[mx]) db--;

        int nd = mx - db;

        if(mp[mx]>k || nd>k)
        {
            int i = ind[mx];
            st1.update(i, mp[mx]);
            if(mp[mx]!=0) st2.update(i, 1);
            continue;
        }

        int xx = k-mp[mx];

        int l=0;
        int r=m+1;

        while(l+1!=r)
        {
            int mid = (l+r)/2;
            int ps = st1.query(1, mid);

            if(ps<=xx) l=mid;
            else r=mid;
        }

        int rpos = daft;
        if(l!=0) rpos = st2.query(l+1, m);

        int td = mx + rpos;
        if(mx==0 && rpos==0) td++;

        int tmp = td - mx;
        ans = min(ans, tmp);

//        cout<<"mx = "<<mx<<endl;
//        cout<<mx<<" "<<rpos<<" "<<daft<<" "<<xx<<" -> "<<tmp<<endl;
//
//        if(mx==3)
//        {
//            cout<<"Special"<<endl;
//
//            for(int ii=1; ii<=m; ii++) cout<<st1.query(ii, ii)<<" ";
//            cout<<endl;
//
//            for(int ii=1; ii<=m; ii++) cout<<st2.query(ii, ii)<<" ";
//            cout<<endl;
//        }

        int i = ind[mx];
        st1.update(i, mp[mx]);
        if(mp[mx]!=0) st2.update(i, 1);
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