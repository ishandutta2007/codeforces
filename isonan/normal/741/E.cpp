#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

int ns,nt,q,num[100001],ord[100001];
int tax[1000001],tp[4000001],a[4000001],rank[4000001],sa[4000001],m,st[200001][21],Log[200001];
int ans[100001];
char S[100001],T[100001];
void Qsort(){
	for(int i=0;i<=m;i++)tax[i]=0;
	for(int i=1;i<=ns+nt;i++)++tax[rank[i]];
	for(int i=1;i<=m;i++)tax[i]+=tax[i-1];
	for(int i=ns+nt;i;i--)sa[tax[rank[tp[i]]]--]=tp[i];
}
void init(){
	m=1000;
	for(int i=1;i<=ns+nt;i++)rank[i]=a[i],tp[i]=i;
	Qsort();
	for(int w=1,p=0;p<ns+nt;m=p,w<<=1){
		p=0;
		for(int i=1;i<=w;i++)tp[++p]=ns+nt-w+i;
		for(int i=1;i<=ns+nt;i++)if(sa[i]>w)tp[++p]=sa[i]-w;
		Qsort();
		std::swap(rank,tp);
		rank[sa[1]]=p=1;
		for(int i=2;i<=ns+nt;i++)
			rank[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w])?p:++p;
	}
	for(int i=1,k=0;i<=ns+nt;i++){
		int j=sa[rank[i]-1];
		if(!j)continue;
		if(k)--k;
		while(a[i+k]==a[j+k])++k;
		st[rank[i]][0]=k;
	}
	for(int j=1;j<=20;j++)
		for(int i=1;i+(1<<j)-1<=ns+nt;i++)
			st[i][j]=std::min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
	l=rank[l],r=rank[r];
	if(l>r)std::swap(l,r);
	++l;
	int k=Log[r-l+1];
	return std::min(st[l][k],st[r-(1<<k)+1][k]);
}
bool check(int p1,int len1,int p2,int len2){
	if(len1==len2){
		int u=query(p1,p2);
		if(u<len1)return a[p1+u]<a[p2+u];
		return 1;
	}
	bool Xor=(len1>len2);
	if(Xor)std::swap(p1,p2),std::swap(len1,len2);
	int u=query(p1,p2);
//	printf("%d %d\n",u,len1);
	if(u<len1)return Xor^(a[p1+u]<a[p2+u]);
	u=query(p2,p2+len1);
	if(u<len2-len1)return Xor^(a[p2+u]<a[p2+len1+u]);
	u=query(p2+(len2-len1),p1);
	if(u<len1)return Xor^(a[p2+(len2-len1)+u]<a[p1+u]);
	return 1;
}
bool raw_cmp(int a,int b){
	bool Xor=(a>b);
	if(Xor)std::swap(a,b);
//	printf("%d %d %d %d\n",a,b,check(ns+1,nt,a+1,b-a),Xor);
	return Xor^check(ns+1,nt,a+1,b-a);
}
int cmp(int a,int b){if(!~a)return b;if(!~b)return a;return ord[a]<ord[b]?a:b;}
struct que{
	int l,r,x,y,ord;
};
std::vector<que>vec[2000];
int Query(int l,int r){
	if(l>r)return -1;
	int k=Log[r-l+1];
	return cmp(st[l][k],st[r-(1<<k)+1][k]);
}
void init(int len){
	for(int j=1;j<=20;j++)
		for(int i=0;i+(1<<j)-1<=len;i++)
			st[i][j]=cmp(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int main(){
	scanf("%s%s%d",S+1,T+1,&q);
	ns=strlen(S+1),nt=strlen(T+1);
	Log[1]=0;
	for(int i=2;i<=ns+nt;i++)Log[i]=Log[i>>1]+1;
	for(int i=1;i<=ns;i++)a[i]=S[i];
	for(int i=1;i<=nt;i++)a[i+ns]=T[i];
//	printf("%d\n",ns+nt);
//	for(int i=1;i<=ns+nt;i++)printf("%d ",a[i]);putchar('\n');
	init();
//	for(int i=1;i<=ns+nt;i++)printf("%d ",sa[i]);putchar('\n');
	for(int i=0;i<=ns;i++)num[i]=i;
//	raw_cmp(0,ns);
//	return 0;
	std::sort(num,num+ns+1,raw_cmp);
//	for(int i=0;i<=ns;i++)printf("%d ",num[i]);putchar('\n');
	for(int i=0;i<=ns;i++)ord[num[i]]=i;
	int bl=(int)(sqrt(ns+1)/log(ns+1));
	for(int i=0;i<=ns;i++)st[i][0]=i;
	init(ns);
	for(int i=1,l,r,k,x,y;i<=q;i++){
		scanf("%d%d%d%d%d",&l,&r,&k,&x,&y);
		if(k>bl){
			ans[i]=-1;
			int u=(l/k)*k;
			for(int j=u;j<=r;j+=k)
				ans[i]=cmp(ans[i],Query(std::max(j+x,l),std::min(j+y,r)));
		}
		else{
			ans[i]=-1;
			if(k==1)ans[i]=Query(l,r);
			else vec[k].push_back((que){l,r,x,y,i});
		}
	}
	for(int i=2;i<=bl;i++){
		for(int j=0;j<i;j++){
			int len=-1;
			for(int k=j;k<=ns;k+=i)st[++len][0]=k;
			init(len);
			for(int k=0;k<vec[i].size();k++)
				if(vec[i][k].x<=j&&j<=vec[i][k].y){
					int l=(vec[i][k].l/i);
					if((l*i+j)<vec[i][k].l)++l;
					int r=(vec[i][k].r/i);
					if((r*i+j)>vec[i][k].r)--r;
					ans[vec[i][k].ord]=cmp(ans[vec[i][k].ord],Query(l,r));
				}
		}
	}
	for(int i=1;i<=q;i++)printf("%d ",ans[i]);
}