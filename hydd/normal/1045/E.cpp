#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> ans;
int n;
struct point{
	int x,y;
	point(int _x=0,int _y=0){ x=_x; y=_y;}
	bool operator<(const point &a) const{ return atan2(y,x)<atan2(a.y,a.x);}
};
point operator+(const point &a,const point &b){ return point(a.x+b.x,a.y+b.y);}
point operator-(const point &a,const point &b){ return point(a.x-b.x,a.y-b.y);}
int dot(const point &a,const point &b){ return a.x*b.x+a.y*b.y;}
int cross(const point &a,const point &b){ return a.x*b.y-a.y*b.x;}
int dist2(const point &a,const point &b){ return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
bool isleft(const point &a,const point &b,const point &c){ 
	int tmp=cross(b-a,c-a);
	return tmp>0;
}
int area(const point &a,const point &b,const point &c){
	return abs(cross(b-a,c-a));
}
int isinside(const point &a,const point &b,const point &c,const point &x){
	return area(a,b,c)==area(a,b,x)+area(b,c,x)+area(c,a,x);
}
struct node{
	point p;
	int pos,col;
} a[110000],s[110000]; int top;
vector<node> tmp,tmp1,tmp2;
int fa[110000];
int findset(int u){
	if (u!=fa[u]) fa[u]=findset(fa[u]);
	return fa[u];
}
void Union(int u,int v){
	int x=findset(u),y=findset(v);
	if (x==y) return;
	ans.push_back(pii(u,v));
	fa[x]=fa[y];
}
vector<node> divide(const node &a,const node &b,const node &c,const vector<node> &vec){
	vector<node> res;
	for (node p:vec)
		if (p.pos!=a.pos&&p.pos!=b.pos&&p.pos!=c.pos&&isinside(a.p,b.p,c.p,p.p)) res.push_back(p);
	return res;
}
void solve(node a,node b,node c,vector<node> vec){
	if (a.col!=c.col) swap(a,c);
	else if (a.col!=b.col) swap(a,b);
	if (findset(b.pos)!=findset(c.pos)) Union(b.pos,c.pos);
	
	bool flag=true; node p;
	for (node u:vec)
		if (u.col==a.col){ flag=false; p=u;}
	if (flag){
		for (node u:vec)
			if (findset(b.pos)!=findset(u.pos)) Union(b.pos,u.pos);
		return;
	}
	solve(a,b,p,divide(a,b,p,vec));
	solve(a,c,p,divide(a,c,p,vec));
	solve(b,c,p,divide(b,c,p,vec));
}
bool cmp(const node &a,const node &b){ return a.p<b.p;}
int main(){
	scanf("%d",&n); int p=0;
	for (int i=0;i<n;i++) fa[i]=i;
	for (int i=0;i<n;i++){
		scanf("%d%d%d",&a[i].p.x,&a[i].p.y,&a[i].col); a[i].pos=i;
		if (a[i].p.y<a[p].p.y||(a[i].p.y==a[p].p.y&&a[i].p.x<a[p].p.x)) p=i;
	}
	swap(a[0],a[p]); point O=a[0].p; 
	for (int i=0;i<n;i++) a[i].p=a[i].p-O;
	
	sort(a+1,a+n,cmp);
	top=0;
	for (int i=0;i<n;i++){
		while (top>=2&&!isleft(s[top-1].p,s[top].p,a[i].p)) top--;
		s[++top]=a[i];
	}
	s[0]=s[top];
	int cnt=0;
	for (int i=1;i<=top;i++) cnt+=(s[i].col!=s[i-1].col);
	if (cnt>2){ puts("Impossible"); return 0;}
	tmp.clear();
	for (int i=0;i<n;i++) tmp.push_back(a[i]);
	if (!cnt){
		bool flag=true;
		int col=s[1].col,pos=-1;
		for (int i=0;i<n;i++)
			if (a[i].col!=col){
				flag=false;
				pos=i;
			}
		if (flag){
			printf("%d\n",n-1);
			for (int i=1;i<n;i++) printf("0 %d\n",i);
			return 0;
		}
		for (int i=1;i<=top;i++)
			solve(s[i],s[i-1],a[pos],divide(s[i],s[i-1],a[pos],tmp));
	} else{
		int x=-1,y=-1;
		for (int i=1;i<=top;i++)
			if (s[i].col!=s[i-1].col){
				if (x==-1) x=i;
				else y=i;
			}
		for (int i=x;i<y;i++) tmp1.push_back(s[i]);
		for (int i=y;i<=top;i++) tmp2.push_back(s[i]);
		for (int i=1;i<x;i++) tmp2.push_back(s[i]);
		for (int i=0;i+1<(int)tmp1.size();i++)
			solve(tmp1[i],tmp1[i+1],tmp2[0],divide(tmp1[i],tmp1[i+1],tmp2[0],tmp));
		for (int i=0;i+1<(int)tmp2.size();i++)
			solve(tmp2[i],tmp2[i+1],tmp1[0],divide(tmp2[i],tmp2[i+1],tmp1[0],tmp));
	}
	printf("%d\n",ans.size());
	for (pii u:ans) printf("%d %d\n",u.first,u.second);
	return 0;
}