// Hydro submission #633ea1b7bda22aa9892adc9b@1665049016488
// 873E Awards For Contestants
#include <bits/stdc++.h>
#define int long long
#define SIZE 3005
#define all(x) x.begin(), x.end()
#define debug(x) cout<<#x<<":"<<x<<endl;
using namespace std;

struct node
{
	int x, p;	
};

bool cmp(node a, node b)
{
	return a.x>b.x;
}

struct segmentTreeNode
{
	int l, r;
	node v;
};

inline int read()
{
    int k=0, f=1;
    char c=getchar();
    while(c<'0' || c>'9')
    {
        if(c=='-') f=-1; c=getchar();
    }
    while(c>='0' && c<='9')
    {
        k=k*10+c-48; c=getchar();
    }
    return k*f;
}

inline void write(int n)
{
    if(n==0) putchar('0');
    stack<int> S;
    while(n)
        S.push(n%10), n/=10;
    while(!S.empty())
    {
        int x=S.top(); S.pop();
        putchar(x+48);
    }
}

int n;

node a[SIZE];
int res[SIZE];
segmentTreeNode t[SIZE*4];
class segmentTree
{
public:
	void build(int p, int l, int r)
	{
		t[p].l=l; t[p].r=r;
		if(l==r)
		{
			t[p].v.x=a[l].x-a[l+1].x; t[p].v.p=l;
			return;
		}
		
		int mid=(l+r)/2;
		build(p*2, l, mid);
		build(p*2+1, mid+1, r);
		
		if(t[p*2].v.x>t[p*2+1].v.x)
		{
			t[p].v.x=t[p*2].v.x;
			t[p].v.p=t[p*2].v.p;
		}
		else
		{
			t[p].v.x=t[p*2+1].v.x;
			t[p].v.p=t[p*2+1].v.p;
		}
	}
	
	node query(int p, int l, int r)
	{
		if(l<=t[p].l && t[p].r<=r)
			return t[p].v;
			
		int mid=(t[p].l+t[p].r)/2;
		node val={-1, -1};
		if(l<=mid)
		{
			node w=query(p*2, l, r);
			if(w.x>val.x) val.x=w.x, val.p=w.p;
		}
		if(r>mid)
		{
			node w=query(p*2+1, l, r);
			if(w.x>val.x) val.x=w.x, val.p=w.p;
		}
		return val;
	}
};

#define upd m1=t1, m2=t2, m3=t3, mi1=i, mi2=i+j, mi3=w.p

signed main()
{
	n=read();
	for(int i=1; i<=n; i++) a[i].x=read(), a[i].p=i;
	a[n+1].x=0;
	sort(a+1, a+1+n, cmp);
	segmentTree st;
	st.build(1, 1, n);
	int m1=0, m2=0, m3=0, mi1, mi2, mi3;
	for(int i=1; i<=n; i++)
		for(int j=1; i+j<n; j++)
		{
			if(i>2*j || j>2*i) continue;
			int L=i+j+max(1.0, ceil(max(i, j)/2.0));
			int R=i+j+min(n-i-j, 2*min(i, j));
			if(L>R) continue;
			node w=st.query(1, L, R);
			int t1=a[i].x-a[i+1].x, t2=a[i+j].x-a[i+j+1].x;
			int t3=w.x;
			if(t1>m1) upd;
			else if(t1==m1)
			{
				if(t2>m2) upd;
				else if(t2==m2)
					if(t3>m3) upd;
			}
		}
	int i;
	for(i=1; i<=mi1; i++) res[a[i].p]=1;
	for(; i<=mi2; i++) res[a[i].p]=2;
	for(; i<=mi3; i++) res[a[i].p]=3;
	for(; i<=n; i++) res[a[i].p]=-1;
	for(int i=1; i<=n; i++) 
	{
		if(res[i]<0) printf("-1 ");
		else write(res[i]), putchar(' ');
	}

    return 0;
}