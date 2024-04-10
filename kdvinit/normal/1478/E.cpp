/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5+1;

const int32_t maxn=N;
template<typename NODE,typename UPDATE>
struct segtree{
	bool built=false,lazy[4*maxn];
	NODE zero=NODE(),t[4*maxn];
	UPDATE noop=UPDATE(),upds[4*maxn];
	int32_t tl[4*maxn],tr[4*maxn];
	inline void pushdown(int32_t v)
	{
		if(lazy[v]){
			apply(v*2,upds[v]);
			apply(v*2+1,upds[v]);
			lazy[v]=0;
			upds[v]=noop;
		}
	}
	inline void apply(int32_t v,UPDATE &val)
	{
		if(tl[v]!=tr[v]){
			lazy[v]=1;
			upds[v].combine(val,tl[v],tr[v]);
		}
		val.apply(t[v],tl[v],tr[v]);
	}
	template<typename T>
	void build(T a, int32_t v, int32_t l, int32_t r) {
		tl[v]=l;
		tr[v]=r;
		if (l == r) {
			t[v]=a[l];
			return;
		} else {
			int32_t tm = (l + r) / 2;
			build(a, v*2, l, tm);
			build(a, v*2+1, tm+1, r);
			t[v].merge(t[v*2],t[v*2+1]);
		}
	}
	NODE query(int32_t v, int l, int r) {
		if (l > tr[v] || r < tl[v])
			return zero;
		if (l <= tl[v] && tr[v] <= r) {
			return t[v];
		}
		pushdown(v);
		NODE a,b,ans;
		a=query(v*2, l, r);
		b=query(v*2+1, l, r);
		ans.merge(a,b);
		return ans;
	}
	void rupd(int32_t v, int l, int r, UPDATE &val)
	{
		if(l > tr[v] || r < tl[v])
			return;
		if(l <= tl[v] && tr[v] <= r)
		{
			apply(v,val);
			return;
		}
		pushdown(v);
		rupd(v*2,l,r,val);
		rupd(v*2+1,l,r,val);
		t[v].merge(t[v*2],t[v*2+1]);
	}
	template<typename T>
	int descent_right(int l, T x, int32_t v, NODE &prev) {
		if (l > tr[v]) // node is completely out of range
			return len;
		if(l <= tl[v]){ // node is completely in range
			NODE cur;
			cur.merge(prev,t[v]);
			if (!cur.check(x)){ // go further right than this node
				swap(prev,cur); // merging this node's contribution
				return len;
			}
			if (tl[v]==tr[v]) {
				return tr[v];
			}
		}
		pushdown(v);
		int ans=descent_right(l, x, v*2, prev); // trying to find in left child
		if(ans!=len)return ans; // found in left child
		return descent_right(l, x, v*2+1, prev); // finding in right child
	}
	template<typename T>
	int descent_left(int r, T x, int32_t v, NODE &prev) {
		if (r < tl[v]) // node is completely out of range
			return -1;
		if(r >= tr[v]){ // node is completely in range
			NODE cur;
			cur.merge(t[v],prev);
			if (!cur.check(x)){ // go further left than this node
				swap(cur,prev); // merging this node's contribution
				return -1;
			}
			if (tl[v]==tr[v]) {
				return tl[v];
			}
		}
		pushdown(v);
		int ans=descent_left(r, x, v*2+1, prev); // trying to find in right child
		if(ans!=-1)return ans; // found in right child
		return descent_left(r, x, v*2, prev); // finding in left child
	}

	int len=maxn;
	void clear(){
		fill(t,t+4*len,zero);
		fill(lazy,lazy+4*len,false);
		fill(upds,upds+4*len,noop);
		built = false;
	}
	template<typename T>
	void build(T a){
		build(a,1,0,len-1);
		built=true;
	}
	template<typename T>
	int descent_right(int l, T x){ // minimum r such that [l...r].check(x) == true, returns segtree.len if not found
		NODE prev=zero;
		return descent_right(l,x,1,prev);
	}
	template<typename T>
	int descent_left(int r, T x){ // maximum l such that [l...r].check(x) == true, returns -1 if not found
		NODE prev=zero;
		return descent_left(r,x,1,prev);
	}
	NODE query(int l,int r){
		if(!built)build(t);
		return query(1,l,r);
	}
	void rupd(int l,int r,UPDATE val){
		if(!built)build(t);
		rupd(1,l,r,val);
	}
};

#define node node1
#define update update1
struct node{
	int cnt[2] = {0,0};
	node(){}
	node(int val){
		cnt[val] = 1;
		cnt[!val] = 0;
	}
	void merge(node &l,node &r)
	{
		for(int i=0;i<2;i++){
			cnt[i] = l.cnt[i] + r.cnt[i];
		}
	}
	bool check(int x){
		return false;
	}
};
struct update{
	int v;
	update(){}
	update(int val){
		v = val;
	}
	void combine(update &other,int32_t tl,int32_t tr){
		v = other.v;
	}
	void apply(node &x,int32_t tl,int32_t tr){
		x.cnt[v] = tr - tl + 1;
		x.cnt[!v] = 0;
	}
};
segtree<node,update> t;
#undef node
#undef update

int l[N];
int r[N];

void solve()
{
    int n,q;
    cin>>n>>q;

    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++)
    {
        char x; cin>>x;
        a[i]=x-48;
    }
    for(int i=1;i<=n;i++)
    {
        char x; cin>>x;
        b[i]=x-48;
        t.rupd(i,i,b[i]);
    }

    int lr[q+1][2];
    for(int i=1;i<=q;i++) cin>>lr[i][0]>>lr[i][1];

    for(int i=q;i>0;i--)
    {
        int l=lr[i][0];
        int r=lr[i][1];

        int len=r-l+1;
        int m=len/2;

        auto z=t.query(l,r);
        int val=z.cnt[1];

        if(len%2==0 && val==m) { cout<<"NO"<<endl; return; }

        if(val<=m) t.rupd(l,r,0);
        else t.rupd(l,r,1);
    }

    for(int i=1;i<=n;i++)
    {
        auto z=t.query(i,i);
        int val=z.cnt[1];
        if(a[i]!=val) { cout<<"NO"<<endl; return; }
    }
    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc; cin>>tc;
    while(tc--) solve();
    return 0;
}