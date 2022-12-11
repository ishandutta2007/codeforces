#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;struct bian{
    int next,point,f,w;
}b[500000];
int len,n,m,x[500000],p[600],d[600],inf=100000000,after[600],pd[600],totpoint,cost;
char getin(){
    char ch=getchar();
    for (;ch<'A'||ch>'Z';ch=getchar());
    return ch;
}
void ade(int k1,int k2,int k3,int k4){
    len++;
    b[len].point=k2;
    b[len].next=p[k1];
    p[k1]=len;
    b[len].f=k3;
    b[len].w=k4;
}
void add(int k1,int k2,int k3,int k4){
    ade(k1,k2,k3,k4); ade(k2,k1,0,-k4);
}
bool spfa(){
    memset(after,0xff,sizeof after);
    memset(pd,0x00,sizeof pd);
    memset(d,0x3f,sizeof d);
    int head=1,now=0; x[1]=0; d[0]=0; pd[0]=1;
    for (;head>now;){
        now++;
        for (int i=p[x[now]];i!=-1;i=b[i].next){
            int j=b[i].point;
            if (b[i].f>0&&d[x[now]]+b[i].w<d[j]){
                after[j]=i; d[j]=d[x[now]]+b[i].w;
                if (pd[j]==0){
                    head++; x[head]=j; pd[j]=1;
                }
            }
        }
        pd[x[now]]=0;
    }
    if (after[totpoint]==-1) return 0; else return 1;
}
int change(){
    int i=totpoint,j=after[i],k=inf;
    for (;j!=-1;){
        k=min(k,b[j].f);
        i=b[j^1].point; j=after[i];
    }
    i=totpoint; j=after[i];
    for (;j!=-1;){
        b[j].f-=k; b[j^1].f+=k;
        cost+=b[j].w*k;
        i=b[j^1].point; j=after[i];
    }
    return k;
}
int dinic(){
    int num=0;
    for (;spfa();) num+=change();
    return num;
}
char s[1000],ch[1000];
int main(){
	scanf("%d",&n); scanf("%s",s+1); len=-1;
	memset(p,0xff,sizeof p);
	totpoint=n+1;
	for (int i=1;i<=n;i++) add(i,i+1,inf,0);
	scanf("%d",&m);
	for (;m;m--){
		int k1; scanf("%s%d",ch+1,&k1); int len=strlen(ch+1);
		for (int i=1;i<=n-len+1;i++){
			int flag=0;
			for (int j=1;j<=len;j++) if (ch[j]!=s[i+j-1]){
				flag=1; break;
			}
			if (flag==0) add(i,i+len,1,-k1);
		}
	}
	scanf("%d",&m); add(0,1,m,0);
	dinic(); printf("%d\n",-cost);
	return 0;
}