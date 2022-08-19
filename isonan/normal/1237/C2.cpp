#include <set>
#include <cstdio>
#include <algorithm>

struct point{int x,y,z,orig;}num[1000001],stk[1000001],a;
bool operator<(const point &lhs,const point &rhs){return (lhs.x!=rhs.x)?lhs.x<rhs.x:((lhs.y!=rhs.y)?lhs.y<rhs.y:(lhs.z<rhs.z));} 
bool comp(point lhs,point rhs){return lhs.z<rhs.z;}
std::set<point>set;
int n,top,ttop;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&num[i].x,&num[i].y,&num[i].z),num[i].orig=i;
	std::sort(num+1,num+n+1,comp);
	for(int i=1,tem;i<=n;){
		tem=num[i].z;
		while(num[i].z==tem&&i<=n)set.insert(num[i]),++i,++ttop;
		while(ttop+top>1)
			if(top>1)
				printf("%d %d\n",stk[top].orig,stk[top-1].orig),top-=2;
			else{
				point x=*set.begin();
				stk[++top]=x;
				set.erase(x);
				--ttop;
				while(ttop){
					point s=*set.begin();
					if(s.x==x.x&&s.orig)stk[++top]=s,set.erase(s),--ttop;
					else break;
				}
			}
		if(top==1)set.insert(stk[1]),top=0,++ttop;
	}
}