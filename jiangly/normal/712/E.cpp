#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=1e5,Q=1e5;
int n,q;
double p[N];
class segment_tree{
	private:
		struct state{
			double x,y;
			state(double x0=0.0,double y0=0.0):x(x0),y(y0){}
			state operator+(const state&b)const{
				return state(1-(1-x)*(1-b.x)/(1-y*b.x),1-(1-y)*(1-b.y)/(1-y*b.x));
			}
		};
		struct node{
			int l,r;
			node*lchild,*rchild;
			state f;
			node(int a,int b):l(a),r(b),lchild(NULL),rchild(NULL){}
		};
		node*root;
		void update(node*x){
			x->f=x->lchild->f+x->rchild->f;
		}
		void build(node*x){
			if(x->l==x->r){
				x->f=state(1-p[x->l-1],p[x->l-1]);
			}else{
				int mid=(x->l+x->r)>>1;
				x->lchild=new node(x->l,mid);
				x->rchild=new node(mid+1,x->r);
				build(x->lchild);
				build(x->rchild);
				update(x);
			}
		}
		void change(node*x,int pos,double y){
			if(x->l==x->r){
				x->f=state(1-y,y);
			}else{
				int mid=(x->l+x->r)>>1;
				if(pos<=mid){
					change(x->lchild,pos,y);
				}else{
					change(x->rchild,pos,y);
				}
				update(x);
			}
		}
		state query(node*x,int l,int r){
			if(x->l==l&&x->r==r){
				return x->f;
			}else{
				int mid=(x->l+x->r)>>1;
				if(r<=mid){
					return query(x->lchild,l,r);
				}else if(l>mid){
					return query(x->rchild,l,r);
				}else{
					return query(x->lchild,l,mid)+query(x->rchild,mid+1,r);
				}
			}
		}
	public:
		void build(int n){
			root=new node(1,n);
			build(root);
		}
		void change(int pos,double y){
			change(root,pos,y);
		}
		double query(int l,int r){
			return 1-query(root,l,r).x;
		}
}t;
int pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%mod;
		}
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
template<class T>void read(T&x){
	char ch;
	bool sign=0;
	while(!isdigit(ch=getchar())){
		if(ch=='-'){
			sign=1;
		}
	}
	x=ch-'0';
	while(isdigit(ch=getchar())){
		x=x*10+ch-'0';
	}
	if(sign){
		x=-x;
	}
}
int main(){
	read(n);
	read(q);
	for(int i=0;i<n;++i){
		int x,y;
		read(x);
		read(y);
		p[i]=1.0*x/y;
	}
	t.build(n);
	for(int i=0;i<q;++i){
		int opt,d,x,y;
		read(opt);
		switch(opt){
			case 1:
				read(d);
				read(x);
				read(y);
				t.change(d,1.0*x/y);
				break;
			case 2:
				read(x);
				read(y);
				printf("%.10lf\n",t.query(x,y));
				break;
		}
	}
	return 0;
}