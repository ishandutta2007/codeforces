#include <algorithm>
#include <cstdio>
#include <set>

std::set<int>set;
std::set<int>::iterator it;
int n,size[100001],fa[100001],stk[100001],top,S[100001];
struct point{
	int size,ord;
}num[100001];
bool cmp(point a,point b){return a.size<b.size;}
void solve(int l,int r,int x){
	if(l>r)return;
	printf("%d\n",r-l+1);
	for(int i=l;i<=r;i++)printf("%d ",S[i]);
	printf("\n1\n%d\n%d\n",1,x);
	fflush(stdout);
	int tem;
	scanf("%d",&tem);
	if(!tem)return;
	if(l==r){
		stk[++top]=S[l];
		return;
	}
	solve(l,(l+r)>>1,x);
	solve(((l+r)>>1)+1,r,x);
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		printf("%d\n",n-1);
		for(int j=2;j<=n;j++)
			printf("%d ",j);
		printf("\n1\n%d\n%d\n",1,i);
		fflush(stdout);
		scanf("%d",size+i);
		num[i]=(point){size[i],i};
	}
	num[1]=(point){n,1};
	std::sort(num+1,num+n+1,cmp);
	for(int i=1;i<=n;i++){
		int s=0;
		for(it=set.begin();it!=set.end();++it)S[++s]=*it;
		top=0;
		solve(1,s,num[i].ord);
		for(int j=1;j<=top;j++)
			fa[stk[j]]=num[i].ord,set.erase(stk[j]);
		set.insert(num[i].ord);
	}
	puts("ANSWER");
	for(int i=2;i<=n;i++)printf("%d %d\n",i,fa[i]);
}