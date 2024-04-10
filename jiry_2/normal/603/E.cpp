#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct tree{
	int l,r,size,extra,w,where,father;
}t[500000];
struct bian{
	int u,v,w;
	void scan(){
		scanf("%d%d%d",&u,&v,&w);
	}
}b[310000];
int n,m,f[110000],size[110000],rev[500000],a[310000],R,rem;
int compare(int k1,int k2){
	return b[k1].w<b[k2].w;
}
void reverse(int k){
	rev[k]^=1; swap(t[k].l,t[k].r);
}
void pushdown(int k){
	if (rev[k]){
		rev[k]=0; reverse(t[k].l); reverse(t[k].r);
	}
}
void change(int k){
	t[k].size=t[t[k].l].size+t[t[k].r].size+t[t[k].l].extra+t[t[k].r].extra+(t[k].w==0);
	if (t[t[t[k].l].where].w>t[t[t[k].r].where].w) t[k].where=t[t[k].l].where; else t[k].where=t[t[k].r].where;
	if (t[t[k].where].w<t[k].w) t[k].where=k;
}
void zig(int k){
	int f=t[k].father; pushdown(f); pushdown(k); 
	if (t[t[f].father].l==f) t[t[f].father].l=k; else if (t[t[f].father].r==f) t[t[f].father].r=k;
	t[k].father=t[f].father; t[f].l=t[k].r; t[t[f].l].father=f; t[k].r=f; t[f].father=k;
	change(f);
}
void zag(int k){
	int f=t[k].father; pushdown(f); pushdown(k); 
	if (t[t[f].father].l==f) t[t[f].father].l=k; else if (t[t[f].father].r==f) t[t[f].father].r=k;
	t[k].father=t[f].father; t[f].r=t[k].l; t[t[f].r].father=f; t[k].l=f; t[f].father=k;
	change(f);
}
int splay_root(int k){
	return t[k].father&&(t[t[k].father].l==k||t[t[k].father].r==k);
}
void splay(int k){
	pushdown(k); 
	while (splay_root(k)){
		int f1=t[k].father,f2=t[f1].father;
		if (!splay_root(f1)){
			if (t[f1].l==k) zig(k); else zag(k);
			break;
		}
		pushdown(f2);
		if (t[f1].l==k){
			if (t[f2].l==f1) zig(f1),zig(k); else zig(k),zag(k);
		} else if (t[f2].l==f1) zag(k),zig(k); else zag(f1),zag(k);
	}
	change(k);
}
int access(int k){
	int now=0;
	while (k){
		splay(k); t[k].extra+=t[t[k].r].size+t[t[k].r].extra-t[now].size-t[now].extra;
		t[k].r=now; change(k); now=k; k=t[k].father;
	}
	return now;
}
void makeroot(int k){
	reverse(access(k)); splay(k);
}
void link(int k1,int k2){
	makeroot(k1); makeroot(k2); t[k1].father=k2; t[k2].extra+=t[k1].size+t[k1].extra;
}
void cut(int k1,int k2){
//	cout<<"cut "<<k1<<" "<<k2<<endl;
	makeroot(k1); access(k2); splay(k2);
	t[k2].l=0; t[k1].father=0; change(k2);
}
int findfather(int k1){
	if (f[k1]==k1) return k1; f[k1]=findfather(f[k1]); return f[k1];
}
void insert(int k){
	int k1=b[k].u,k2=b[k].v;
	if (findfather(k1)!=findfather(k2)){
		int k3=findfather(k1),k4=findfather(k2);
		if ((size[k3]&1)&&(size[k4]&1)) rem-=2;
		f[k3]=k4; size[k4]+=size[k3];
	} else {
		makeroot(k1); int k3=t[access(k2)].where;
	//	cout<<"linnk "<<k<< " "<<k3-n<<endl;
		if (t[k3].w<=b[k].w) return; //cout<<"cu"<<endl;
		cut(k3,b[k3-n].u); cut(k3,b[k3-n].v);
	}
	t[k+n]=(tree){0,0,0,0,b[k].w,k+n,0};
	link(k+n,k1); link(k+n,k2);
}
int check(int k1){
	k1+=n; 
	makeroot(findfather(b[k1-n].u)); access(k1); splay(k1); 
//	cout<<endl<<endl;
//	cout<<"check "<<k1<<" "<<findfather(b[k1-n].u)<<" "<<t[t[k1].r].size<<" "<<t[t[k1].r].extra<<" "<<t[k1].extra<<endl;
//	for (int i=1;i<=n+m;i++) cout<<t[i].w<<" "<<t[i].l<<" "<<t[i].r<<" "<<t[i].father<<" "<<t[i].size<<" "<<t[i].extra<<endl;
	return (t[t[k1].r].size+t[t[k1].r].extra+t[k1].extra)&1;
}
int getans(){
	while (R&&check(a[R])==0) R--;
	return b[a[R]].w;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		b[i].scan(); a[i]=i;
	}
	sort(a+1,a+m+1,compare); rem=n;
	for (int i=1;i<=n;i++) f[i]=i,size[i]=1,t[i]=(tree){0,0,1,0,0,0,0};
	R=m;
	for (int now=1;now<=m;now++){
		insert(now);
		if (rem==0) printf("%d\n",getans()); else printf("-1\n");
	//	for (int i=0;i<=n+now;i++) cout<<i<<" "<<t[i].w<<" "<<t[i].l<<" "<<t[i].r<<" "<<t[i].father<<" "<<t[i].size<<" "<<t[i].extra<<endl;
	}
	return 0;
}