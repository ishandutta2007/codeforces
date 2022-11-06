//Problem D
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],m2,l[N],r[N],b[N],c[N],f;
struct seg{int v,n,f;}s[N<<1];
bool cmp(seg a,seg b){
    if(a.v!=b.v)return a.v<b.v;
    return a.f<b.f;
}
//==============================================================================
priority_queue<int>p,q;
void add(int v){p.push(v);}
void del(int v){q.push(v);}
int query(){
    while(!q.empty()&&p.top()==q.top())p.pop(),q.pop();
    if(p.empty())return 0;return p.top();
}
//==============================================================================
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)l[i]=n;
    for(int i=1;i<=n;i++){
        int x=a[i];
        l[x]=min(l[x],i);
        r[x]=max(r[x],i);
    }
    //for(int i=1;i<=m;i++)printf("%d %d\n",l[i],r[i]);
    for(int i=1;i<=m;i++)if(r[i])s[++m2]=(seg){l[i],i,0},s[++m2]=(seg){r[i],i,1};
    sort(s+1,s+m2+1,cmp);
    for(int i=1,j=1;i<=n;i++){
        while(j<=m2&&s[j].v==i&&s[j].f==0)add(s[j++].n);
        int v=query();//printf("\n");
        if(a[i]&&a[i]<v){printf("NO");return 0;}
        while(j<=m2&&s[j].v==i&&s[j].f==1)del(s[j++].n);
    }
	int f=1,v=0;
	for(int i=1;i<=n;i++)if(a[i]==m)f=0;
	for(int i=1;i<=n;i++){if(a[i])b[i]=a[i];else b[i]=b[i-1];}
	for(int i=n;i;i--){if(a[i])c[i]=a[i];else c[i]=c[i+1];}
	//for(int i=1;i<=n;i++)printf("%d %d\n",b[i],c[i]);
	
	if(f){
		for(int i=1;i<=n;i++)if(!a[i]){v=i,f=0;break;}
	}
	for(int i=1;i<=n;i++)if(!a[i]){
		if(c[i])a[i]=c[i];
		else if(b[i])a[i]=b[i];
		else a[i]=m;
	}
	a[v]=m;
	if(f){printf("NO");return 0;}
    printf("YES\n");

	for(int i=1;i<=n;i++)printf("%d ",a[i]);
    return 0;
}