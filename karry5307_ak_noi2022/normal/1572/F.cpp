#include<cstdio>
#include<algorithm>

using namespace std;

const int INF=1e9;

int n,q;

struct SegmentBeat
{
	struct nd
	{
		long long sum,add;
		int maxn,maxcnt,sec,addval;
	}t[800000];
	void update_sum(int k){t[k].sum=t[k<<1].sum+t[k<<1|1].sum;}
	void update_maxn(int k)
	{
		t[k].maxn=max(t[k<<1].maxn,t[k<<1|1].maxn),t[k].sec=-INF,t[k].maxcnt=0;
		if(t[k<<1].maxn==t[k].maxn)t[k].maxcnt+=t[k<<1].maxcnt,t[k].sec=max(t[k].sec,t[k<<1].sec);else t[k].sec=max(t[k].sec,t[k<<1].maxn);
		if(t[k<<1|1].maxn==t[k].maxn)t[k].maxcnt+=t[k<<1|1].maxcnt,t[k].sec=max(t[k].sec,t[k<<1|1].sec);else t[k].sec=max(t[k].sec,t[k<<1|1].maxn);
	}
	void addtag_sum(int k,int l,int r,long long val){t[k].sum+=(r-l+1)*val,t[k].add+=val;}
	void addtag_maxn(int k,int l,int r,int val){t[k].maxn=min(t[k].maxn,val),t[k].addval=min(t[k].addval,val);}
	void spread_sum(int k,int l,int r){if(l==r)return;int mid=(l+r)>>1;addtag_sum(k<<1,l,mid,t[k].add),addtag_sum(k<<1|1,mid+1,r,t[k].add);t[k].add=0;}
	void spread_maxn(int k,int l,int r){if(l==r)return;int mid=(l+r)>>1;addtag_maxn(k<<1,l,mid,t[k].addval),addtag_maxn(k<<1|1,mid+1,r,t[k].addval);t[k].addval=INF;}
	
	void build(int l,int r,int k=1)
	{
		t[k].add=0,t[k].addval=INF;if(l==r){t[k].sum=1,t[k].maxn=l,t[k].maxcnt=1,t[k].sec=-INF;return;}
		int mid=(l+r)>>1;build(l,mid,k<<1),build(mid+1,r,k<<1|1);update_sum(k),update_maxn(k);
	}
	void modify_sum(int x,int y,long long val,int l,int r,int k=1)
	{
		//printf("IN MODIFY_SUM: %d %d %lld %d %d %lld\n",x,y,val,l,r,t[k].sum);
		spread_sum(k,l,r);if(x>r||y<l)return;if(x<=l&&r<=y){addtag_sum(k,l,r,val);/*printf("OUT MODIFY_SUM: %d %d %lld %d %d %lld\n",x,y,val,l,r,t[k].sum);*/return;}
		int mid=(l+r)>>1;modify_sum(x,y,val,l,mid,k<<1),modify_sum(x,y,val,mid+1,r,k<<1|1);update_sum(k);
		//printf("OUT MODIFY_SUM: %d %d %lld %d %d %lld\n",x,y,val,l,r,t[k].sum);
	}
	void modify_maxn(int x,int y,int val,int l,int r,int k=1)
	{
		spread_maxn(k,l,r);if(x>r||y<l)return;
		if(x<=l&&r<=y)
		{
			//printf("MODIFY_MAXN: %d %d %d %d %d\n",l,r,val,t[k].maxn,t[k].sec);
			if(t[k].maxn<=val)return;
			if(t[k].sec<val)
			{
				//printf("MODIFY: %d %d %d\n",val+1,t[k].maxn,-t[k].maxcnt);
				modify_sum(val+1,t[k].maxn,-t[k].maxcnt,1,n);
				addtag_maxn(k,l,r,val);return;
			}
		}
		int mid=(l+r)>>1;modify_maxn(x,y,val,l,mid,k<<1),modify_maxn(x,y,val,mid+1,r,k<<1|1);update_maxn(k);
	}
	void modify_point(int pos,int val,int l,int r,int k=1)
	{
		spread_maxn(k,l,r);
		if(l==r){/*printf("MODIFY: %d %d %d\n",l,t[k].maxn,val);*/modify_sum(l,t[k].maxn,-1,1,n);t[k].maxn=val;modify_sum(l,t[k].maxn,+1,1,n);return;}
		int mid=(l+r)>>1;if(pos<=mid)modify_point(pos,val,l,mid,k<<1);else modify_point(pos,val,mid+1,r,k<<1|1);update_maxn(k);
	}
	long long query_sum(int x,int y,int l,int r,int k=1)
	{
		spread_sum(k,l,r);if(x>r||y<l)return 0;if(x<=l&&r<=y){return t[k].sum;}
		int mid=(l+r)>>1;return query_sum(x,y,l,mid,k<<1)+query_sum(x,y,mid+1,r,k<<1|1);
	}
	long long query_maxn(int pos,int l,int r,int k=1)
	{
		spread_sum(k,l,r);if(l==r)return t[k].maxn;
		int mid=(l+r)>>1;return pos<=mid?query_maxn(pos,l,mid,k<<1):query_maxn(pos,mid+1,r,k<<1|1);
	}
}T;

int main()
{
	scanf("%d%d",&n,&q);T.build(1,n);
	//for(int i=1;i<=n;i++)printf("%lld ",T.query_sum(i,i,1,n));puts("");
	while(q--)
	{
		int op=0,x=0,y=0;scanf("%d%d%d",&op,&x,&y);
		if(op==1){if(x>1)T.modify_maxn(1,x-1,x-1,1,n);T.modify_point(x,y,1,n);}
		else{printf("%lld\n",T.query_sum(x,y,1,n));}
		//for(int i=1;i<=n;i++)printf("%lld ",T.query_sum(i,i,1,n));puts("");
		//for(int i=1;i<=n;i++)printf("%lld ",T.query_maxn(i,1,n));puts("");
	}
}