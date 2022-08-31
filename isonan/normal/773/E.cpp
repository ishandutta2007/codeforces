#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

int n,a[500001],ord[500001];
std::pair<int,int>num[500001];
int siz[5000001],mn[5000001],mn2[5000001];
void update(int root,int l,int r,int e){
	if(l==r){
		siz[root]=1;
		mn[root]=a[l];
		mn2[root]=a[l]+1;
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e);
	else update(root<<1|1,((l+r)>>1)+1,r,e);
	siz[root]=siz[root<<1]+siz[root<<1|1];
	mn[root]=std::min(mn[root<<1]+siz[root<<1|1],mn[root<<1|1]);
	mn2[root]=std::min(mn2[root<<1],mn2[root<<1|1]+siz[root<<1]);
}
int query1(int root,int l,int r,int &s){
	if(mn2[root]+s>=0)return 0;
	if(l==r){
		++s;
		return l;
	}
	if(mn2[root<<1|1]+s+siz[root<<1]<0){
		s+=siz[root<<1];
		return query1(root<<1|1,((l+r)>>1)+1,r,s);
	}
	else{
		return query1(root<<1,l,(l+r)>>1,s);
	}
}
int query2(int root,int l,int r,int el,int er){
	if(el>r||er<l)return (n<<1);
	if(el<=l&&er>=r)return mn[root];
	return std::min(query2(root<<1,l,(l+r)>>1,el,er)+siz[root<<1|1],query2(root<<1|1,((l+r)>>1)+1,r,el,er)); 
}
int read(){
	int x=0;
	char ch=getchar();
	bool f=0;
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
void write(int x){
	if(x<0){
		putchar('-'),write(-x);
		return;
	}
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
	scanf("%d",&n);
	memset(mn,0x3f,sizeof mn);
	memset(mn2,0x3f,sizeof mn2);
	for(int i=1;i<=n;i++){
		num[i].first=read();
		num[i].second=i;
	}
	std::sort(num+1,num+n+1);
	for(int i=1;i<=n;i++)ord[num[i].second]=i,a[i]=num[i].first;
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);putchar('\n');
	for(int i=1;i<=n;i++){
		update(1,1,n,ord[i]);
		int s=0,x=query1(1,1,n,s);
//		printf("%d %d\n",s,x);
		write(std::min(i-(s<<1),query2(1,1,n,x+1,n)));putchar('\n');
	}
}