#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int N=10000+5;
vector<int>lk[N];
bool ban[N];
vector<pii>ans;
set<pii>ans_set;
void ans_push(int x,int y)
{
    if(x>y)swap(x,y);
    pii p={x,y};
    if(ans_set.count(p))return ;
    ans_set.insert(p);
    ans.push_back(p);
}
int fa[N],sz[N],bsz[N];
vector<int>block[N];

void work(int rt)
{
    vector<int>q;
    fa[rt]=0;q.push_back(rt);
    rep(head,0,int(q.size())-1)
    {
        int x=q[head];
        sz[x]=1;bsz[x]=0;
        for(auto y:lk[x])
        if(!ban[y]&&y!=fa[x])
        {
            fa[y]=x;q.push_back(y);
        }
    }
    int n=q.size();
    if(n<=4)return ;
    int g=min(n,int(sqrt(n)*1.5));
    vector<int>big;
    per(head,n-1,1)
    {
        int x=q[head];
        if(sz[x]>=g||bsz[x]>1)
        {
            big.push_back(x);
            sz[x]=0;
            bsz[x]=1;
        }
        sz[fa[x]]+=sz[x];
        bsz[fa[x]]+=bsz[x];
    }
    big.push_back(rt);
    int m=big.size();
    rep(i,0,m-1)
    {
        ban[big[i]]=1;
        rep(j,i+1,m-1)ans_push(big[i],big[j]);
    }
    rep(head,1,n-1)
    {
        int x=q[head];
        if(!ban[x])
        {
            int y=fa[x];
            while(!ban[y])y=fa[y];
            ans_push(x,y);   
            block[y].push_back(x);
        }
    }
    rep(head,1,n-1)
    {
        int x=q[head];
        if(ban[x])
        {
            int y=fa[x];
            while(!ban[y])y=fa[y];
            for(auto z:block[y])ans_push(x,z);
        }
    }   
    for(auto x:q)
    if(!ban[x])work(x);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
    int n,k;
    cin>>n>>k;
    rep(i,1,n-1)
    {
        int x=read(),y=read();
        lk[x].push_back(y);
        lk[y].push_back(x);
        if(x>y)swap(x,y);
        ans_set.insert({x,y});
    }
    work(1);
    printf("%d\n",int(ans.size()));
    for(auto pr:ans)printf("%d %d\n",pr.first,pr.second);
}