#include<bits/stdc++.h>
using namespace std;
#define int long long
long long tree[1200005];
long long lazy[1200005];
const int pot=(1<<19);
void push(int w,int l,int r)
{
    tree[w]+=lazy[w];
    if(l!=r)
    {
        lazy[2*w]+=lazy[w];
        lazy[2*w+1]+=lazy[w];
    }
    lazy[w]=0;
}
void ins_pom(int w,int a,int b,int l,int r,int war)
{
    if(lazy[w]!=0)
        push(w,l,r);
    if(r<a || l>b)
        return;
    if(l>=a && r<=b)
    {
        tree[w]+=war;
        if(l!=r)
        {
            lazy[2*w]+=war;
            lazy[2*w+1]+=war;
        }
        return;
    }
    ins_pom(2*w,a,b,l,(l+r)/2,war);
    ins_pom(2*w+1,a,b,(l+r)/2+1,r,war);
    tree[w]=max(tree[2*w],tree[2*w+1]);
}
long long check_pom(int w,int a,int b,int l,int r)
{
    if(lazy[w]!=0)
        push(w,l,r);
    if(r<a || l>b)
        return -1e18;
    if(l>=a && r<=b)
        return tree[w];
    return max(check_pom(2*w,a,b,l,(l+r)/2) , check_pom(2*w+1,a,b,(l+r)/2+1,r));
}
void ins(int a,int b,int c)
{
    a+=10;
    b+=10;
    ins_pom(1,a,b,1,pot,c);
}
long long check(int a,int b)
{
    a+=10;
    b+=10;
    return check_pom(1,a,b,1,pot);
}
int h[1000005];
int tab[1000005];
vector<int> v;
void solve()
{
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        cin>>h[x];
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    v.push_back(0);
    for(int x=1;x<=a;x++)
    {
        ins(x-1,x-1,tab[x]);
        while(h[v.back()] > h[x])
        {
            int pom1 = v[v.size() - 2] , pom2 = v.back()-1;
            ins(pom1,pom2,-tab[v.back()]);
            ins(pom1,pom2,tab[x]);
            v.pop_back();
        }
        v.push_back(x);
        ins(x,x,check(0,x-1));
    }
    cout<<check(a,a);
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    t = 1;
    while(t--)
        solve();
	return 0;
}