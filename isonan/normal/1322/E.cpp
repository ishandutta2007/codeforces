#include <algorithm>
#include <cassert> 
#include <cstdio>
#include <set>

int n,ans[500001],t[500001],i,type[500001],fin;
std::pair<int,int>num[500001];
int v[3][2][4000001];
std::set<int>rest;
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
void pushup(int x){
	for(register int i=0,j;i<3;++i)for(j=0;j<2;++j)
		v[i][j][x]=(j?min:max)(v[i][j][x<<1],v[i][j][x<<1|1]);
}
void update(int root,int l,int r,int e){
	if(l==r){
		for(int i=0;i<3;++i)
			(i==type[e])?v[i][0][root]=0,v[i][1][root]=n+1:(v[i][0][root]=v[i][1][root]=e);
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e);
	else update(root<<1|1,((l+r)>>1)+1,r,e);
	pushup(root);
}
int get(int root,int l,int r,int el,int er,int x,int y){
	if(el>r||er<l)return y?n+1:0;
	if(el<=l&&er>=r)return v[x][y][root];
	return (y?min:max)(get(root<<1,l,(l+r)>>1,el,er,x,y),get(root<<1|1,((l+r)>>1)+1,r,el,er,x,y));
}
void gettp(int x){
	if(x<1||x>n)return;
	type[x]=((t[x+1]==t[x])||(t[x-1]==t[x])||x==1||x==n)*(t[x]+1);
	update(1,1,n,x);
}
void check(int l,int r){
	std::set<int>::iterator now;
	for(;;){
		now=rest.lower_bound(l);
		if(now==rest.end())return;
		if(*now>r)return;
		ans[*now]=num[i].first;
		rest.erase(now);
	}
}
int tag[500001],now;
void solve(const int &x){
	if(x<1||x>n||tag[x]==now)return;
	int l=get(1,1,n,1,x-1,type[x],0)+1;
	if(tag[l]==now)return;
	int r=get(1,1,n,x+1,n,type[x],1)-1;
	tag[x]=tag[l]=now;
	if(type[x]==2)check(l,r);
	else if(!type[x]){
		fin=std::max(fin,(r-l+2)>>1);
		if((r-l+1)%2){
			if(t[l-1])check(l,r);
		}
		else if(t[l-1])check(l,(l+r)>>1);
		else check(((l+r)>>1)+1,r);
	}
}
void build(int root,int l,int r){
	for(int i=0;i<3;i++)v[i][1][root]=n+1;
	if(l==r)return;
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
}
std::vector<int>vec;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)num[i].first=read(),num[i].second=i,rest.insert(i);
	build(1,1,n);
	t[0]=t[n+1]=-1;
	type[0]=type[n+1]=-1;
	std::sort(num+1,num+n+1);
	int last=n+1;
	for(int i=1;i<=n;i++)type[i]=1;
	for(i=n;i;--i){
		int ind=num[i].second;
		t[ind]=1;
		gettp(ind);
		gettp(ind-1);
		gettp(ind+1);
		vec.push_back(ind);
		if(type[ind]==type[ind+1]){
			vec.push_back(ind+2);
		}else 
		vec.push_back(ind+1);
		if(type[ind]==type[ind-1]){
			vec.push_back(ind-2);
		}else 
		vec.push_back(ind-1);
		if(num[i-1].first==num[i].first)continue;
//		printf("%d\n",num[i].first);
		++now;
//		for(int j=1;j<=n;j++)printf("%d ",t[j]);putchar('\n');
//		for(int j=1;j<=n;j++)printf("%d ",type[j]);putchar('\n');
		while(!vec.empty()){
			solve(vec.back());
			vec.pop_back(); 
		}
		last=i;
//		printf("%d\n",i);
	}
	printf("%d\n",fin);
	for(int i=1;i<=n;i++)write(ans[i]),putchar(' ');
}