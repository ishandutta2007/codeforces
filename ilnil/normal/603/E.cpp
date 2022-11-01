#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define _(x)((x)&1)
using namespace std;
const int N=1e5+5;
int n,m,cnt,ds,x,y,l;
int u[N*3],v[N*3],le[N*3];
struct nod{
	int l;
	nod(int p=0){l=p;}
	bool operator<(const nod &b)const{return le[l]<le[b.l]||le[l]==le[b.l]&&l<b.l;}
	bool operator==(const nod &b)const{return l==b.l;}
};
struct heap{
	priority_queue<nod>a,b;
	void push(nod x){a.push(x);}
	void pop(nod x){if(x==a.top())a.pop();else b.push(x);};
	bool empty(){return a.size()==b.size();}
	nod top(){
		for(;!b.empty()&&b.top()==a.top();)b.pop(),a.pop();
		return a.top();
	}
}A;
struct lct{
	lct *s[2],*f;
	int T,t,a,mx;
	bool is,r;
	void up(){
		T=t+s[0]->T+s[1]->T;
		mx=max(a,s[0]->mx);
		mx=max(mx,s[1]->mx);
	}
	void rv(){swap(s[0],s[1]);s[0]->r^=1;s[1]->r^=1;r=0;}
	void ro(){
		lct *y=f;bool z=f->s[1]==this;
		(y->s[z]=s[!z])->f=y;
		f=y->f;y->is?f->s[f->s[1]==y]=this:0;
		(s[!z]=y)->f=this;swap(is,y->is);y->up();
	}
}t[N*4],*d[N*2];
void cl(lct *x){
	for(;d[++ds]=x,x->is;)x=x->f;
	for(;ds;--ds)
		if(d[ds]->r)d[ds]->rv();
}
void sp(lct *x){
	for(cl(x);x->is;x->ro())
		if(x->f->is)(x->f->s[1]==x)==(x->f->f->s[1]==x->f)?x->f->ro():x->ro();
	x->up();
}
void ac(lct *x){
	lct *y=t,*xx=x;
	for(;x!=t;x->up(),y=x,x=x->f){
		sp(x);
		x->t+=x->s[1]->T-y->T;
		x->s[1]->is=0;
		(x->s[1]=y)->is=1;
	}
	sp(xx);
}
void mr(lct *x){
	ac(x);x->r^=1;
}
lct* find_mx(lct *x){
	for(;;){
		if(x->mx==x->a)return x;
		x=x->s[x->mx==x->s[1]->mx];
	}
}
void cut(lct *x){
	sp(x);
	x->s[0]->f=x->s[1]->f=t;
	x->s[0]->is=x->s[1]->is=0;
}
void link(int x,int y,int z){
	t[x].f=t[y].f=t+z;
	t[z].t=t[z].T=t[x].T+t[y].T;
	t[z].mx=t[z].a=l;
	t[z].f=t[z].s[0]=t[z].s[1]=t;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;cnt=n;
	fo(i,1,n)t[i].t=t[i].T=1,t[i].s[0]=t[i].s[1]=t[i].f=t;
	for(;m;--m){
		cin>>x>>y>>l;
		if(x>y)swap(x,y);
		u[m]=x;v[m]=y;le[m]=l;
		if(m==1){
			int kk=0;
		}
		mr(t+x);mr(t+y);sp(t+x);
		if(t[y].is){
			if(l<t[x].mx){
				lct *w=find_mx(t+x);
				cut(w);
				int wz=w-t-n;
				A.pop(nod(wz));
				A.push(nod(m));
				mr(t+x);mr(t+y);
				link(x,y,n+m);
			}
		}else{
			cnt+=_(t[x].T+t[y].T)-_(t[x].T)-_(t[y].T);
			A.push(nod(m));
			link(x,y,n+m);
		}
		for(;!cnt&&!A.empty();){
			nod a=A.top();
			x=v[a.l];y=u[a.l];
			mr(t+x);ac(t+y);
			if(!_(t[y].T)&&!_(t[x].T)){
				A.pop(a);
				cut(t+n+a.l);
			}else break;
		}
		printf("%d\n",cnt?-1:le[A.top().l]);
	}
}