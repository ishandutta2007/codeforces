#include<bits/stdc++.h>
#define maxl 200010
#define maxn 400010
#define maxm 16000010
#define mid ((l+r)>>1)
using namespace std;
template<typename T> inline void read(T &x)
{
    x=0;char c=getchar();bool flag=false;
    while(!isdigit(c)){if(c=='-')flag=true;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    if(flag)x=-x;
}
int n,q,las,tot=1,tree_cnt;
int f[maxn],ch[maxn][26],len[maxn],bel[maxl],rt[maxn],ls[maxm],rs[maxm],cnt[maxm];
char s[maxl];
struct edge
{
    int to,nxt;
}e[maxn];
int head[maxn],edge_cnt;
void add(int from,int to)
{
    e[++edge_cnt]=(edge){to,head[from]};
    head[from]=edge_cnt;
}
void modify(int l,int r,int pos,int &cur)
{
    if(!cur) cur=++tree_cnt;
    cnt[cur]++;
    if(l==r) return;
    if(pos<=mid) modify(l,mid,pos,ls[cur]);
    else modify(mid+1,r,pos,rs[cur]);
}
int query(int L,int R,int l,int r,int cur)
{
    if(L<=l&&R>=r) return cnt[cur];
    int v=0;
    if(L<=mid) v+=query(L,R,l,mid,ls[cur]);
    if(R>mid) v+=query(L,R,mid+1,r,rs[cur]);
    return v;
}
//int insert(int c,int id)
//{
//    if(ch[las][c]&&len[las]+1==len[ch[las][c]]) return ch[las][c];
//    int p=las,np=++tot;
//    len[np]=len[p]+1;
//    while(p&&!ch[p][c]) ch[p][c]=np,p=f[p];
//    if(!p) f[np]=1;
//    else
//    {
//        int q=ch[p][c];
//        if(len[q]==len[p]+1) f[np]=q;
//        else
//        {
//            int nq=++tot;
//            bool flag=las==p;
//            memcpy(ch[nq],ch[q],sizeof(ch[q]));
//            len[nq]=len[p]+1,f[nq]=f[q],f[q]=f[np]=nq;
//            while(ch[p][c]==q) ch[p][c]=nq,p=f[p];
//            return flag?nq:np;
//        }
//    }
//    return np;
//}
inline void newnq(int p, int q, int c, int np = 0) {
	int nq = ++tot; len[nq] = len[p] + 1;
	memcpy(ch[nq], ch[q], sizeof(ch[q]));
	f[nq] = f[q]; f[q] = f[np] = nq;
	for (; ch[p][c] == q; p = f[p]) ch[p][c] = nq;
}

int insert(int p, int c) {
	if (ch[p][c]) {
		int q = ch[p][c];
		if (len[q] == len[p] + 1) las = q;
		else newnq(p, q, c), las = tot;
		return las;
	}
	int np = ++tot; len[np] = len[p] + 1; las = np;
	for (; p && !ch[p][c]; p = f[p]) ch[p][c] = np;
	if (!p) f[np] = 1;
	else {
		int q = ch[p][c];
		if (len[q] == len[p] + 1) f[np] = q;
		else newnq(p, q, c, np);
	}
	return las;
}



int merge(int x,int y)
{
    if(!x||!y) return x+y;
    int p=++tree_cnt;
    cnt[p]=cnt[x]+cnt[y];
    ls[p]=merge(ls[x],ls[y]);
    rs[p]=merge(rs[x],rs[y]);
    return p;
}
void dfs(int x)
{
    for(int i=head[x];i;i=e[i].nxt)
        dfs(e[i].to),rt[x]=merge(rt[x],rt[e[i].to]);
}
int main()
{
    read(n),read(q);
    for(int i=1;i<=n;++i)
    {
        int lenth;
        scanf("%s",s+1),lenth=strlen(s+1),las=1;
        for(int j=1;j<=lenth;++j)
            las=insert(las, s[j] - 'a'),modify(1,n,i,rt[las]);
        bel[i]=las;
    }
    for(int i=2;i<=tot;++i) add(f[i],i);
    dfs(1);
    while(q--)
    {
        int l,r,k;
        read(l),read(r),read(k);
        printf("%d\n",query(l,r,1,n,rt[bel[k]]));
    }
    return 0;
}