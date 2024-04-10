#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
struct bian{
	int next,point,f;
}b[80000];
int a[300],n,totpoin,dst[300],pd[300],p[300],len,B[300][300],tot,x[300],totpoint,inf=1e5;
vector<int>A[300];
void dfs(int k){
	A[tot].push_back(k); pd[k]=1;
	for (int i=1;i<=n;i++) if (B[k][i]&&pd[i]==0) dfs(i);
}
void ade(int k1,int k2,int k3)
{
    len++; b[len].point=k2; b[len].next=p[k1]; b[len].f=k3; p[k1]=len;
}
void add(int k1,int k2,int k3)
{
    ade(k1,k2,k3); ade(k2,k1,0);
}
bool bfs()
{
    int head=1,now=0,i,j;
    memset(dst,0xff,sizeof dst);
    memset(pd,0x00,sizeof pd);
    x[1]=0; pd[0]=1; dst[0]=0;
    while (head>now)
    {
        now++; i=p[x[now]];
        while (i!=-1)
        {
            j=b[i].point;
            if ((b[i].f)&&(!pd[j]))
            {
                pd[j]=1; dst[j]=dst[x[now]]+1;
                if (j==totpoint)
                {
                    return 1;
                }
                head++; x[head]=j;
            }
            i=b[i].next;
        }
    }
    return pd[totpoint];
}
int change(int k1,int k2)
{
    if ((k1==totpoint)||(k2==0)) return k2;
    int num=0,k,i,j;
    i=p[k1];
    while (i!=-1)
    {
        j=b[i].point;
        if ((b[i].f)&&(dst[k1]+1==dst[j]))
        {
            k=change(j,min(k2,b[i].f));
            k2=k2-k; num+=k;
            b[i].f=b[i].f-k; b[i^1].f+=k;
            if (k2==0)
            {
                break;
            }
        }
        i=b[i].next;
    }
    if (!num)
    {
        dst[k1]=-1;
    }
    return num;
}
int dinic(){
    int now=0; while (bfs()) now+=change(0,inf); return now;
}
int check(int k){
	for (int i=2;i*i<=k;i++) if (k%i==0) return 0;
	return 1;
}
int main(){
	scanf("%d",&n); memset(p,0xff,sizeof p); len=-1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) if (a[i]%2) add(0,i,2); else add(i,n+1,2);
	for (int i=1;i<=n;i++)
		if (a[i]%2)
			for (int j=1;j<=n;j++)
				if ((a[j]%2==0)&&(check(a[i]+a[j]))){
					add(i,j,1); 
				}
	totpoint=n+1;
	if (dinic()!=n) {printf("Impossible\n"); return 0;}
	for (int i=1;i<=n;i++)
		if (a[i]%2)
			for (int j=p[i];j!=-1;j=b[j].next)
				if (j%2==0&&b[j].f==0){
					B[i][b[j].point]=1; B[b[j].point][i]=1;
				}
	memset(pd,0x00,sizeof pd);
	for (int i=1;i<=n;i++)
		if (pd[i]==0){tot++; dfs(i);}
	cout<<tot<<endl;
	for (int i=1;i<=tot;i++){
		cout<<A[i].size()<<" ";
		for (int j=0;j<A[i].size();j++) cout<<A[i][j]<<" "; cout<<endl;
	}
	return 0;
}