#include<bits/stdc++.h>
using namespace std;
int a[500005];
struct pr{
int l,r,id;
inline bool operator<(const pr &p)const{
	return l<p.l;
}
}p[500005];

struct in{
	int r,id;
inline bool operator<(const in &p)const{
	return r>p.r;
}
};
priority_queue<in> q;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		int i,b;
		for(i=1;i<=n;++i){
			scanf("%d",&b);
			if(b)p[i]=(pr){i/(1+b)+1,i/b,i};
			else p[i]=(pr){i+1,n,i};
			//if(b)printf("%d in %d %d\n",i,i/(1+b)+1,i/b);
			//else printf("%d in %d %d\n",i,i+1,n);
		}
		sort(p+1,p+n+1);
		while(!q.empty())q.pop();
		int j=1;
		//for(i=1;i<=n;++i)printf("%d %d %d\n",p[i].l,p[i].r,p[i].id);
		for(i=1;i<=n;++i){
			while(j<=n&&p[j].l==i){
				q.push((in){p[j].r,p[j].id});
				++j;
			}
			in ii=q.top();
			a[ii.id]=i;
			q.pop();
		}
		for(i=1;i<=n;++i)printf("%d ",a[i]);
		printf("\n");
	}	return 0;
}