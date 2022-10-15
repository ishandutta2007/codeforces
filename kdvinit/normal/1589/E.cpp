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
        if(l>r || l<1 || r>n) return -1;
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
    int n;
    cin>>n;

    int a[n+1], b[n+1]={0};
    for(int i=1; i<=n; i++) cin>>a[i];

    map<int, int> odd, even;
    int s[n+1];

    Segment_Tree1 sto(b, n);
    Segment_Tree1 ste(b, n);

    int ans=0;
    int cnt[n+1]={0};

    s[0]=0;
    for(int i=1; i<=n; i++)
    {
        s[i]=a[i]-s[i-1];
        int j = (i+1)/2;

        if(i%2==1) sto.update(j, s[i]);
        else ste.update(j, s[i]);

        int ind = 0;
        if(i%2==1)
        {
            ind  = max(ind, odd[s[i]]);
            ind  = max(ind, even[-s[i]]);
        }
        else
        {
            ind  = max(ind, even[s[i]]);
            ind  = max(ind, odd[-s[i]]);
        }

        if(ind==0 && s[i]!=0)
        {
            if(i%2==1) odd[s[i]]=i;
            else even[s[i]]=i;
            continue;
        }


        int pos=1, l, r;
        if(i%2==1)
        {
            int oddmin, evenmin;
            if(ind%2==1)
            {
                l=(ind+1)/2;
                r=(i/2);
                evenmin=ste.query(l, r);
                oddmin=sto.query(l+1, r+1);
                evenmin+=s[ind];
                oddmin-=s[ind];
            }
            else
            {
                l=(ind)/2;
                r=(i/2);
                evenmin=ste.query(l+1, r);
                oddmin=sto.query(l+1, r+1);
                evenmin-=s[ind];
                oddmin+=s[ind];
            }

            if(evenmin<0 || oddmin<0) pos=0;
            else pos=1;

            if(a[i]==0) pos=1;
        }
        else
        {
            int oddmin, evenmin;
            if(ind%2==1)
            {
                l=(ind+1)/2;
                r=(i/2);
                evenmin=ste.query(l, r);
                oddmin=sto.query(l+1, r);
                evenmin+=s[ind];
                oddmin-=s[ind];
            }
            else
            {
                l=(ind)/2;
                r=(i/2);
                evenmin=ste.query(l+1, r);
                oddmin=sto.query(l+1, r);
                evenmin-=s[ind];
                oddmin+=s[ind];
            }

            if(evenmin<0 || oddmin<0) pos=0;
            else pos=1;

            if(a[i]==0) pos=1;
        }

        if(pos==1) cnt[i]=cnt[ind]+1;
        ans+=cnt[i];

        if(i%2==1) odd[s[i]]=i;
        else even[s[i]]=i;
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