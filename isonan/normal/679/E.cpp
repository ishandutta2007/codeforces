#include <cstdio>
#include <algorithm>

long long lazy[3][1000001],t[100001];
int L[1000001],n,q;
struct info{
	long long v,mn;
	int pos;
}se[1000001];
bool same[1000001];
long long Pow[10],top;
inline long long up(const long long &x){
	return *std::upper_bound(Pow,Pow+top,x);
}
void add(int x,long long y){
	se[x].v+=y;
	se[x].mn-=y;
	if(lazy[1][x]){
		lazy[1][x]+=y;
		lazy[2][x]-=y;
	}
	else lazy[0][x]+=y;
}
void set(int x,long long y,long long z){
	se[x]=(info){y,z,L[x]};
	lazy[1][x]=y;
	lazy[2][x]=z;
}
void spread(int x){
	if(lazy[0][x]){
		add(x<<1,lazy[0][x]);
		add(x<<1|1,lazy[0][x]);
		lazy[0][x]=0;
	}
	if(lazy[1][x]){
		set(x<<1,lazy[1][x],lazy[2][x]);
		set(x<<1|1,lazy[1][x],lazy[2][x]);
		lazy[1][x]=0;
	}
}
info merge(info a,info b){return (a.mn<=b.mn)?a:b;} 
void pushup(int root){
	se[root]=merge(se[root<<1],se[root<<1|1]);
	same[root]=same[root<<1]&same[root<<1|1]&(se[root<<1].v==se[root<<1|1].v);
}
void build(int root,int l,int r){
	L[root]=l;
	if(l==r){
		se[root]=(info){t[l],up(t[l])-t[l],l};
		same[root]=1;
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	pushup(root);
}
void set(int root,int l,int r,int el,int er,long long y,long long z){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		set(root,y,z);
		return;
	}
	spread(root);
	set(root<<1,l,(l+r)>>1,el,er,y,z);
	set(root<<1|1,((l+r)>>1)+1,r,el,er,y,z);
	pushup(root);
}
long long last1,last2;
bool good;
void check(int root,int l,int r){
	if(se[root].mn>0)return;
	if(same[root]){
		if(se[root].v!=last1)
			last2=up(last1=se[root].v);
		set(root,last1,last2-last1);
		good|=last2==last1*42ll;
		return;
	}
	spread(root);
	check(root<<1,l,(l+r)>>1); 
	check(root<<1|1,((l+r)>>1)+1,r);
	pushup(root);
}
void add(int root,int l,int r,int el,int er,long long x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		add(root,x);
		check(root,l,r);
		return;
	}
	spread(root);
	add(root<<1,l,(l+r)>>1,el,er,x);
	add(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	pushup(root);
}
long long get(int root,int l,int r,int e){
	if(l==r)return se[root].v;
	spread(root);
	if((l+r)>>1>=e)return get(root<<1,l,(l+r)>>1,e);
	else return get(root<<1|1,((l+r)>>1)+1,r,e);
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(long long x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
	Pow[0]=1;
	for(int i=1;i<10;i++)Pow[i]=Pow[i-1]*42ll;
	top=10;
	n=read(),q=read();
	for(int i=1;i<=n;i++)t[i]=read();
	build(1,1,n);
	for(int i=1,opt,a,b,x;i<=q;i++){
		opt=read();
		if(opt==1){
			write(get(1,1,n,read()));
			putchar('\n');
		}
		else if(opt==2){
			a=read(),b=read(),x=read();
			set(1,1,n,a,b,x,up(x)-x);
		}
		else{
			a=read(),b=read(),x=read();
			for(;;){
				good=0;
				add(1,1,n,a,b,x);
				if(!good)break;
			}
		}
	}
}