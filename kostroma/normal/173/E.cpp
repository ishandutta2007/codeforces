#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <queue>
#include <memory.h>

using namespace std;

/*
CAUTION: IS INT REALLY INT, BUT NOT LONG LONG?
REAL SOLTION AFTER MAIN FUNCTION
*/

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pi;
typedef vector <li> vli;
typedef pair <li, li> pli;

void solve();
int main() 
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

//#define int li

int n, k, m;

struct man
{
    int r, a, id, id1;
    man(){}
    bool operator < ( const man &b ) const { return (r>b.r) || (r==b.r && id1<b.id1); }
};

man people[100500];

const int shift=1<<17;
int tree[2*shift+6];
void modify (int l, int val)
{
    tree[l]=val;
    for (int i=l/2; i>0; i>>=1)
        tree[i]=tree[2*i]+tree[2*i+1];
}
void add (int l, int val)
{
    tree[l]+=val;
    for (int i=l/2; i>0; i>>=1)
        tree[i]=tree[2*i]+tree[2*i+1];
}
int sum (int l, int r)
{
    if (l>r)
        return 0;
    if (l%2)
        return tree[l]+sum(l+1,r);
    if (r%2==0)
        return tree[r]+sum(l, r-1);
    return sum(l>>1, r>>1);
}

int ids[100500];

int num[100500];

int tree1[2*shift+6];
int rmq (int l, int r)
{
    if (l>r)
        return 0;
    if (l%2)
        return max(tree1[l], rmq(l+1, r));
    if (r%2==0)
        return max(tree1[r], rmq(l, r-1));
    return rmq(l/2, r/2);
}

void modify1 (int l, int val)
{
    tree1[l]=max(val, tree1[l]);
    for (int i=l/2; i>0; i>>=1)
        tree1[i]=max(tree1[2*i], tree1[2*i+1]);
}

void add1 (int l, int val)
{
    tree1[l]+=val;
    for (int i=l/2; i>0; i>>=1)
        tree1[i]=tree1[2*i]+tree1[2*i+1];
}

vector <int> resps;

int bp (int val)
{
    int l=0, r=resps.size();
    while (l+1<r)
    {
        int mm=l+r; mm/=2;
        if (resps[mm]>val)
            r=mm;
        else
            l=mm;
    }
    return l;
}

vector <int> ages;

int bp1 (int val)
{
    int l=0, r=ages.size();
    while (l+1<r)
    {
        int mm=l+r; mm/=2;
        if (ages[mm]>val)
            r=mm;
        else
            l=mm;
    }
    return l;
}

struct query
{
    int mn, mx, R, id;
    bool operator < ( const query &b ) const { return (R>b.R) || (R==b.R && id<b.id); }
};

query qrs[100500];

int ans[100500];

bool cmp (man q, man w)
{
    return (q.a<w.a) || (q.a==w.a && q.id<w.id);
}

set <man> s;

void solve()
{  
    cin>>n>>k;
    for (int i=0; i<n; i++)
        cin>>people[i].r, people[i].id=i;
    for (int i=0; i<n; i++)
        resps.pb(people[i].r);
    sort (all(resps));
    resps.resize( unique(all(resps)) - resps.begin() );
    for (int i=0; i<n; i++)
        people[i].r=bp(people[i].r);
    for (int i=0; i<n; i++)
        cin>>people[i].a, ages.pb(people[i].a);
    sort (all(ages));
    ages.resize( unique(all(ages)) - ages.begin() );
    sort (people, people+n, &cmp);
    for (int i=0; i<n; i++)
        ids[people[i].id]=i, people[i].id1=i, s.insert(people[i]);
    
    /*for (int i=0; i<n; i++)
        cout<<people[i].a<<' '<<people[i].r<<endl;*/
    
    queue <int> q;
    for (int i=0; i<n; i++)
    {
        int cur=people[i].a;
        while (!q.empty() && people[q.front()].a<cur-k)
        {
            int now=q.front();
            q.pop();
            add(shift+people[now].r, -1);
        }
        int w=i;
        while (i<n && people[i].a==cur)
        {
            add(people[i].r+shift, 1);
            q.push(i);
            i++;
        }
        for(;w<i; w++)
            num[w]+=sum(shift, shift+people[w].r);
        if (i<n)
            i--;
    }
    
    while (!q.empty())
    {   
        int now=q.front();
        q.pop();
        add(shift+people[now].r, -1);
    }
    for (int i=n-1; i>=0; i--)
    {
        int cur=people[i].a;
        while (!q.empty() && people[q.front()].a>cur+k)
        {
            int now=q.front();
            q.pop();
            add(shift+people[now].r, -1);
        }
        int w=i;
        while (i>=0 && people[i].a==cur)
            num[i]+=sum(shift, shift+people[i].r), i--;
        for (;w>i; w--)
        {
            add(people[w].r+shift, 1);
            q.push(w);
        }
        if (i>=0)
            i++;
    }
    
   /*for (int i=0; i<n; i++)
        cout<<num[i]<<' ';
    cout<<endl;*/
    
    cin>>m;
    for (int i=0; i<m; i++)
    {
        int qq, ww;
        cin>>qq>>ww;
        qq--; ww--;
        
        //cout<<qq<<' '<<ww<<"  "<<ids[qq]<<' '<<ids[ww]<<endl;
        
        qrs[i].R=max(people[ids[qq]].r, people[ids[ww]].r);
        pair <int, int> now1=mp(people[ids[qq]].a-k, people[ids[qq]].a+k);
        pair <int, int> now2=mp(people[ids[ww]].a-k, people[ids[ww]].a+k);
        now1.first=max(now1.first, now2.first);
        now2.second=min(now2.second, now1.second);
        
        //cout<<now1.first<<' '<<now2.second<<endl;
        
        qrs[i].mn=now1.first;
        qrs[i].mx=now2.second;
        qrs[i].id=i;
    }
    
   /* for (int i=0; i<m; i++)
        cout<<qrs[i].mn<<' '<<qrs[i].mx<<' '<<qrs[i].R<<endl;*/
    
    sort (qrs, qrs+m);
    for (int i=0; i<m; i++)
    {
        int now=qrs[i].R;
        while (!s.empty())
        {
            man cr=*(s.begin());
            if (cr.r<now)
                break;
            //cout<<cr.id1<<endl;
            s.erase(s.begin());
            modify1( shift+bp1(people[cr.id1].a), num[cr.id1] );
            //cout<<bp1(people[cr.id1].a)<<endl;
        }
        int cur1=bp1(qrs[i].mn);
        if (ages[cur1]<qrs[i].mn)
            cur1++;
        int cur2=bp1(qrs[i].mx);
        if (ages[cur2]>qrs[i].mx)
            cur2--;
        
        //cout<<qrs[i].mn<<' '<<cur1<<"   "<<qrs[i].mx<<' '<<cur2<<endl;
        
        ans[qrs[i].id]=rmq(cur1+shift, cur2+shift);
    }
    for (int i=0; i<m; i++)
    {
        if (ans[i]>0)
        cout<<ans[i]<<endl;
        else
            cout<<"-1\n";
    }
}