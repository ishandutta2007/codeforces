#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e3+10;
const LL mod=1e9+7;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
struct link{
	int L[N],R[N];
	void del(int x){
		R[L[x]]=R[x];
		L[R[x]]=L[x];
	}
}S,s;
int n,K,L;
struct P{int x,y,c,ny;}a[N];
bool cmpx(P x,P y){return x.x<y.x;}
bool cmpy(P x,P y){return x.y<y.y;}
int sy[N],las[N];

#define ls ch[0]
#define rs ch[1]

int col[N];
int f[N],t[N];


struct node{
	int l,r,mid;
	int sum,mn,mx,lazy;
	node *ch[2];
	node(int x,int y):l(x),r(y),mid(l+r>>1),sum(0){
		if(x<y){
			ls=new node(x,mid);
			rs=new node(mid+1,y);
		}
		else ls=rs=NULL;
	}
	void update(int c){
		sum=1ll*(sy[r]-sy[l-1])*c%mod;
		lazy=mn=mx=c;
	}
	void pushup(){
		sum=(ls->sum+rs->sum)%mod;
		mn=min(ls->mn,rs->mn);
		mx=max(ls->mx,rs->mx);
	}
	void init(){
		if(l==r){update(f[l]);return;}
		ls->init();rs->init();lazy=0;
		pushup();
	}
	void change(int x,int c){
		if(mn>=c) return;
		if(mx<=c&&l==x){
			update(c);
			return;
		} 
		if(lazy){
			if(ls) {
				ls->update(lazy);
				rs->update(lazy);
			}
			lazy=0;
		}
		if(x<=mid) ls->change(x,c);
		rs->change(max(mid+1,x),c);
		pushup();
	}
}*root=NULL;

LL ans=0;

int main(){
	scanf("%d%d%d",&n,&K,&L);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
	}
	sort(a+1,a+1+n,cmpy);
	a[0].x=a[0].y=-1;a[n+1].x=a[n+1].y=L;
	for(int i=0;i<=n+1;++i) {sy[i]=a[i].y;a[i].ny=i;}
	for(int i=1;i<=n;++i){
		int &it=las[a[i].c];
		if(it) {s.R[it]=i;s.L[i]=it;}
		s.R[i]=n+1;it=i;
	}
	sort(a+1,a+1+n,cmpx);
	root=new node(1,n);
//	cout<<"y"<<endl;
	for(int i=1;i<=n;++i){
		//cout<<i<<endl;
		if(a[i].x!=a[i-1].x){
			for(int j=0;j<i;++j) col[a[j].ny]=0;
			for(int j=i;j<=n;++j) col[a[j].ny]=a[j].c;
			for(int l=1,r=1,tot=0;l<=n;++l){
				for(;r<=n&&tot<K;++r){
					if(col[r]&&!t[col[r]]) ++tot;
					t[col[r]]++;
				} 
				f[l]=(tot<K?L:sy[r-1]);
				--t[col[l]];
				if(col[l]&&!t[col[l]]) --tot;
			}
			root->init();S=s;
			for(int j=n;j>=1;j--){
				ans+=1ll*(1ll*(sy[n]+1)*L%mod-root->sum+mod)%mod*(a[j+1].x-a[j].x)%mod*(a[i].x-a[i-1].x)%mod;
				int p=a[j].ny; 
				root->change(S.L[p]+1,sy[S.R[p]]); 
				S.del(p);
			}
		}
		s.del(a[i].ny); 
	}
	ans=(ans%mod+mod)%mod;
	cout<<ans<<endl;
	return 0;
}