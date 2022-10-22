#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define N 100005
#define M 200005
using namespace std;

struct edge
{
    int to,next;
    edge(){}
    edge(int to,int next)
    {
        this->to=to;
        this->next=next;
    }
}ed[M];

vector<int>vt[N];
int head[N],lnum,esum,index,top,bccnum;
int dfn[N],low[N],mark[M],bj[N],st[M],belong[M],isCut[N],num[N];
pair<int,int>E[M];

inline void addline(int from,int to)
{
    ed[lnum]=edge(to,head[from]);
    head[from]=lnum++;
}

void tarjan(int root,int fa)
{//
                            //E[]
    dfn[root]=low[root]=++index; //
    int child=0;
//dfn[root]<=low[v] 
    for(int i=head[root];~i;i=ed[i].next)
	{ //root
        int v=ed[i].to;
        if(mark[i]) continue;
        mark[i]=mark[i^1]=1;
        st[++top]=i;//continue
         if(!dfn[v])
		 { //vv
            child++;
            tarjan(v,root);
            low[root]=min(low[root],low[v]); //low
            if(dfn[root]<=low[v])
			{
                isCut[root]=1;          //
                bccnum++;//N++
                for(;;){
                    int j=st[top--];
            //bj[]bcc
            //E[]esumtarjan
                    if(bj[ed[j].to]!=bccnum){
                        bj[ed[j].to]=bccnum;
                        num[bccnum]++;
                        E[++esum]=make_pair(ed[j].to,bccnum);
                    }
                    if(bj[ed[j^1].to]!=bccnum){
                        bj[ed[j^1].to]=bccnum;
                        num[bccnum]++;
                        E[++esum]=make_pair(ed[j^1].to,bccnum);
                    }
                    belong[(j>>1)+1]=bccnum;//bcc
                    if(i==j)break;
                }
            }
        }
        else low[root]=min(low[root],dfn[v]);
    //elsev
	 }
	if(root==fa && child<2)isCut[root]=0;
	//20
}

void init()
{
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(mark,0,sizeof(mark));
    memset(belong,0,sizeof(belong));
    memset(isCut,0,sizeof(isCut));
	top=0;
	lnum=0;
	index=0;
	bccnum=0;
	esum=0;
}

vector<int>ans;

int main()
{
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addline(u,v);
        addline(v,u);
    }
    for(int i=1;i<=n;i++)
    	if(!dfn[i])
    		tarjan(i,i);
    for(int i=1;i<=m;i++)
        vt[belong[i]].push_back(i);
    for(int i=1;i<=bccnum;i++)
        if(vt[i].size()==num[i])
            for(int j=0;j<vt[i].size();j++)
                ans.push_back(vt[i][j]);
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    printf("\n");
}