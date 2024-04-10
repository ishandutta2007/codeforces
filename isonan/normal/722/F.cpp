#include <cstdio>
#include <vector>
 
long long gcd(long long a,long long b){return (!b)?a:gcd(b,a%b);}
void exgcd(long long a,long long b,long long &x,long long &y){
	if(!b){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	long long t=x;
	x=y;
	y=t-(a/b)*y;
}
typedef long long ll;
typedef unsigned long long ull;
inline ll ksc(ll x,ll y,ll p){
    ll z=(long double)x/p*y;
    ll res=(ull)x*y-(ull)z*p;
    return (res+p)%p;
}
struct point{
	long long p,x;
	point operator+(point a){
		if(!~p||!~a.p)return (point){-1,0};
		if(!p)return a;
		if(!a.p)return *this;
		long long New=gcd(p,a.p),X,Y;
//		printf("(%lld %lld)+(%lld %lld)->",p,x,a.p,a.x);
		if((x-a.x)%New){
//			puts("-1"); 
			return (point){-1,0};
		} 
		exgcd(p,a.p,X,Y);
		X*=(a.x-x)/New;
		New=p*(a.p/New);
		X=((X%New)+New)%New;
		X=ksc(X,p,New);
		X+=x;
		X=((X%New)+New)%New;
//		printf("%lld %lld\n",X,Y);
//		printf("(%lld %lld)\n",New,X);
		return (point){New,X};
	}
}se[500001],a[100001];
int tag[500001],now;
void New(int root){
	if(tag[root]<now)tag[root]=now,se[root]=(point){0,0};
}
void update(int root,int l,int r,int e,point &tem){
	New(root);
	if(l==r)return (void)(se[root]=tem);
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e,tem),New(root<<1|1);
	else update(root<<1|1,((l+r)>>1)+1,r,e,tem),New(root<<1);
	se[root]=se[root<<1]+se[root<<1|1];
}
point query(int root,int l,int r,int el,int er){
	New(root);
	if(el>r||er<l)return (point){0,0};
	if(el<=l&&er>=r)return se[root];
	return query(root<<1,l,(l+r)>>1,el,er)+query(root<<1|1,((l+r)>>1)+1,r,el,er);
}
int n,m,len[100001];
std::vector<std::pair<int,int> >vec[100001];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,tem;i<=n;i++){
		scanf("%d",len+i);
		for(int j=0;j<len[i];j++){
			scanf("%d",&tem);
			vec[tem].push_back(std::make_pair(i,j));
		}
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		++now;
		for(int j=0;j<vec[i].size();++j)update(1,0,n-1,j,a[j]=(point){len[vec[i][j].first],vec[i][j].second});
		for(int j=0,ext=0;j<vec[i].size();j++){
			ext=std::max(ext,j);
			point now=query(1,0,n-1,j,ext);
			while(ext+1<vec[i].size()&&vec[i][ext+1].first==vec[i][ext].first+1){
				point tem=now+a[ext+1];
//				putchar('&');
				if(~tem.p)now=tem,++ext;
				else break;
			}
//			printf("%d %d %lld %lld\n",j,ext,now.p,now.x);
			ans=std::max(ans,ext-j+1);
		}
		printf("%d\n",ans);
	}
}