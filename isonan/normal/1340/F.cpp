#include <cstdio>
#include <cstdlib>

const int P1=1000000007,P2=998244353;
int qsm(int a,int b,int P){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%P;
		a=1ll*a*a%P;
		b>>=1;
	}
	return ans;
}
int Pow[100001][2],s[100001];
inline int mul(const int &a,const int &b,const int &P){return 1ll*a*b%P;}
inline int add(int a,const int &b,const int &P){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b,const int &P){a-=b;return (a<0)?a+P:a;}
int val[100001];
struct hash{
	int h1,h2,len;
	hash(int a=0,int b=0,int c=0){h1=a,h2=b,len=c;}
	void set(int x){h1=1ll*val[x]%P1,h2=1ll*val[x]%P2;len=1;}
	hash operator+(hash a){return (hash){(1ll*h1*Pow[a.len][0]+a.h1)%P1,(1ll*h2*Pow[a.len][1]+a.h2)%P2,a.len+len};}
	bool operator==(hash a){return h1==a.h1&&h2==a.h2&&len==a.len;}
}sum[6000001];
int ch[6000001][2],pri[6000001],cnt,stk[6000001],top,rem[6000001];
int cha[6000001];
void pushup(int x){
	sum[x].set(cha[x]);
	sum[x]=sum[ch[x][0]]+sum[x]+sum[ch[x][1]]; 
}
int id(int y){
	int u;
	if(top)u=stk[top--];
	else u=++cnt;
	ch[u][0]=ch[u][1]=0;
	rem[u]=y;
	return u;
}
int Newnode(int x,int y){
	int cnt=id(y);
//	if(cnt%100000==0)fprintf(stderr,"%d\n",cnt);
	cha[cnt]=x;
	pri[cnt]=(1ll*rand()*rand())%2000000;
	pushup(cnt);
	return cnt;
}
int copy(int x,int y){
	int cnt=id(y);
//	if(cnt%100000==0)fprintf(stderr,"%d\n",cnt);
	ch[cnt][0]=ch[x][0];
	ch[cnt][1]=ch[x][1];
	cha[cnt]=cha[x];
	pri[cnt]=pri[x];
	sum[cnt]=sum[x];
	return cnt;
}
struct point{
	int L,R;
	bool bad;
	point(){L=R=bad=0;}
}se[800001];
void split(int now,int &x,int &y,int s,int Y){
	if(!now)x=y=0;
	else{
		int u=copy(now,Y);
		if(sum[ch[u][0]].len+1<=s)x=u,split(ch[u][1],ch[u][1],y,s-sum[ch[u][0]].len-1,Y);
		else y=u,split(ch[u][0],x,ch[u][0],s,Y);
		pushup(u);
	}
}
int merge(int a,int b,int y){
	if(!a||!b)return a|b;
	int u;
	if(pri[a]<pri[b]){
		u=copy(a,y);
		ch[u][1]=merge(ch[u][1],b,y);
	}
	else{
		u=copy(b,y);
		ch[u][0]=merge(a,ch[u][0],y);
	}
	pushup(u);
	return u;
}
void debug(int x){
	if(!x)return;
	debug(ch[x][0]);
	printf("(%d %d)",cha[x],val[cha[x]]);
	debug(ch[x][1]);
	pushup(x);
}
void clear(int x,int t){
	if(!x)return;
	if(rem[x]==t)stk[++top]=x;
	else return;
	clear(ch[x][0],t);
	clear(ch[x][1],t);
}
point merge(point a,point b,int y){
	if(a.bad)return a;
	if(b.bad)return b;
	point c=point();
	c.bad=0;
	int len1=sum[a.L].len,len2=sum[b.R].len;
	if(len1<len2){
		int t1,t2;
		split(b.R,t1,t2,len2-len1,y);
//		debug(a.L);putchar('\n');
//		debug(t1);putchar('\n');
		if(sum[a.L]==sum[t2]){
			c.R=merge(t1,a.R,y);
			c.L=b.L;
		}else c.bad=1;
		if(~y)clear(t2,y);
	}
	else{
		int t1,t2;
		split(a.L,t1,t2,len1-len2,y);
//		debug(t2);putchar('\n');
//		debug(b.R);putchar('\n');
//		printf("%d %d\n",sum[b.R].h1,sum[t2].h1);
		if(sum[b.R]==sum[t2]){
			c.L=merge(t1,b.L,y);
			c.R=a.R;
		}else c.bad=1;
		if(~y)clear(t2,y);
	}
//	puts("merge");
//	debug(c.L);putchar('\n');
//	debug(c.R);putchar('\n');
//	printf("%d %d\n",sum[c.L].h1,sum[c.R].h1);
	return c;
}
void build(int root,int l,int r){
	if(l==r){
		if(s[l]>0)se[root].L=Newnode(s[l],root);
		else se[root].R=Newnode(-s[l],root);
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	clear(se[root].L,root);
	clear(se[root].R,root);
	se[root]=merge(se[root<<1],se[root<<1|1],root);
}
void upd(int root,int l,int r,int e,int x){
	if(l==r){
		se[root]=point();
		if(x>0)se[root].L=Newnode(x,root);
		else se[root].R=Newnode(-x,root);
		return;
	}
	if((l+r)>>1>=e)upd(root<<1,l,(l+r)>>1,e,x);
	else upd(root<<1|1,((l+r)>>1)+1,r,e,x);
	clear(se[root].L,root);
	clear(se[root].R,root);
	se[root]=merge(se[root<<1],se[root<<1|1],root);
//	printf("upd %d %d %d\n",root,l,r);
//	debug(se[root].L);putchar('\n');
//	debug(se[root].R);putchar('\n');
}
point query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return point();
	if(el<=l&&er>=r)return se[root];
	return merge(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er),-1);
}
int n,k;
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	srand(19260817);
	for(int i=0;i<2;i++){
		Pow[0][i]=1;
		for(int j=1;j<=100000;j++)Pow[j][i]=1ll*Pow[j-1][i]*57843296%(i?P2:P1);
	}
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)val[i]=1ll*i*23;
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	build(1,1,n);
	int q;
	scanf("%d",&q);
//	int cnt=0;
	for(int i=1,opt,a,b;i<=q;i++){
		scanf("%d%d%d",&opt,&a,&b);
		if(opt==1)upd(1,1,n,a,b),s[a]=b;
		else{
			auto now=query(1,1,n,a,b);
			puts((now.bad||now.L||now.R)?"No":"Yes");
//			clear(now.L,-1);
//			clear(now.R,-1);
			while(rem[cnt]==-1&&cnt)--cnt;
//			++cnt;
//			printf("%d\n",cnt);
		}
//		for(int j=1;j<=n;j++)printf("%d ",s[j]);putchar('\n');
//		if(cnt==19)break;
	}
//	fprintf(stderr,"%d %d\n",cnt,top);
}
//6 3
//1 2 3 -3 -2 -1
//100
//1 2 -1
//1 1 2
//1 2 2
//1 6 -2
//2 1 6