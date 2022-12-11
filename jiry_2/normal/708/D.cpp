#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
struct bian{
    int next,point,f,w;
}b[10000];
const int inf=1e9; 
int len,n,m,cost,x[500000],p[110],d[110],after[110],pd[110],totpoint,num[110],totnum;
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
//	cout<<"add "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<endl;
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
    if (d[totpoint]>=0) return 0; else return 1;
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
int main(){
	int prew=0; len=-1;
	memset(p,0xff,sizeof p);
	scanf("%d%d",&n,&m);
	for (;m;m--){
		int u,v,c,f;
		scanf("%d%d%d%d",&u,&v,&c,&f);
		if (f<=c){
			add(v,u,f,1);
			add(u,v,c-f,1);
			add(u,v,inf,2);
		} else {
			prew+=f-c;
			add(v,u,c,1);
			add(u,v,f-c,0);
			add(u,v,inf,2);
		}
		f=min(f,c);
		num[u]-=f; num[v]+=f;
	}
	totpoint=n+1; int ou=0,en=0;
	for (int i=2;i<n;i++)
		if (num[i]>0){
			add(0,i,num[i],-210); ou+=num[i]; prew+=210*num[i];
		} else if (num[i]<0){
			add(i,totpoint,-num[i],-210); en-=num[i]; prew-=210*num[i];
		}
	add(0,1,inf,0); add(n,totpoint,inf,0);
	add(1,totpoint,inf,0); add(0,n,inf,0);
	totnum=0;
	dinic();
	printf("%d\n",cost+prew);
	return 0;
}