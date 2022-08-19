#include <cstdio>
#include <random>

std::mt19937 rnd(19260817);
const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int t,x[200001],y[200001];
int key[200001],pri[200001],lson[200001],rson[200001],cnt;
int lazy[200001];
void pushdown(int x,int y){
	if(!x)return;
	key[x]+=y;
	lazy[x]+=y;
}
void spread(int x){
	if(lazy[x]){
		pushdown(lson[x],lazy[x]);
		pushdown(rson[x],lazy[x]);
		lazy[x]=0;
	}
}
void split(int now,int &x,int &y,int v){
	spread(now);
	if(!now)x=y=0;
	else{
		if(key[now]<v)x=now,split(rson[now],rson[now],y,v);
		else y=now,split(lson[now],x,lson[now],v);
	}
}
int merge(int a,int b){
	if(!a||!b)return a|b;
	spread(a),spread(b);
	if(pri[a]<pri[b]){
		rson[a]=merge(rson[a],b);
		return a;
	}
	else{
		lson[b]=merge(a,lson[b]);
		return b;
	}
}
int _mul[400001],invmul[400001];
int C(int n,int m){
	if(n<m||m<0)return 0;
	return mul(mul(_mul[n],invmul[m]),invmul[n-m]);
}
int n,m;
int main(){
	scanf("%d",&t);
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=400000;++i)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=400000;++i)invmul[i]=mul(invmul[P%i],P-P/i);
	for(int i=2;i<=400000;++i)invmul[i]=mul(invmul[i],invmul[i-1]);
	for(int i=1;i<=200000;++i)pri[i]=rnd();
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&m);
		int root=0;
		cnt=0;
		for(int i=1;i<=m;++i){
			scanf("%d%d",x+i,y+i);
			int t1,t2;
			split(root,t1,t2,y[i]);
			int tem=t2;
			while(tem&&lson[tem])tem=lson[tem];
			if(!tem||key[tem]!=y[i]){
				++cnt;
				lson[cnt]=rson[cnt]=0;
				key[cnt]=y[i];
				lazy[cnt]=0;
				t2=merge(cnt,t2);
			}
			pushdown(t2,1);
			root=merge(t1,t2);
		}
		int c=n-cnt;
		printf("%d\n",C(c+n-1,c-1));
	}
}