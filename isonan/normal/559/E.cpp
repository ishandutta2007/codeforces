#include <bits/stdc++.h>

int n,orig[310],f[110][310];
struct point{
	int a,b,c;
}num[101];
bool cmp(point a,point b){
	return a.b<=b.b;
}
int main(){
	scanf("%d",&n);
	for(int i=1,a,l;i<=n;i++){
		scanf("%d%d",&a,&l);
		orig[(i*3)-2]=a-l;
		orig[(i*3)-1]=a;
		orig[(i*3)-0]=a+l;
		num[i]=(point){a-l,a,a+l};
	}
	std::sort(orig+1,orig+(n*3)+1);
	int lim=std::unique(orig+1,orig+(n*3)+1)-orig-1;
	#define get(x)x=std::lower_bound(orig+1,orig+lim+1,x)-orig
	for(int i=1;i<=n;i++)get(num[i].a),get(num[i].b),get(num[i].c);
	std::sort(num+1,num+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<lim;j++){
			if(num[i].b<=j&&num[i].c>j){
				f[i+1][num[i].c]=std::max(f[i+1][num[i].c],f[i][j]+orig[num[i].c]-orig[j]);
				ans=std::max(ans,f[i][j]+orig[num[i].c]-orig[j]);
			}
			f[i][j+1]=std::max(f[i][j+1],f[i][j]);
			f[i+1][j]=std::max(f[i+1][j],f[i][j]);
			ans=std::max(ans,f[i][j]);
			int x=j;
			for(int k=i;k<=n;k++){
				if(num[k].a<=j){
					int v=std::max(x,num[k].b);
					if(v>j){
						f[k+1][v]=std::max(f[k+1][v],f[i][j]+orig[v]-orig[j]);
						ans=std::max(ans,f[i][j]+orig[v]-orig[j]);
					}
				}
				x=std::max(x,num[k].c);
			}
		}
	printf("%d\n",ans);
}