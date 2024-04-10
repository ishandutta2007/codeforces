#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int n;
int st[maxn];
int res[maxn];
inline int query(int x,int y,int z){
	printf("? %d %d %d\n",x,y,z);fflush(stdout);
	return read();
}
int main(){
	int T;
	T=read();
	while(T--){
		int B=0;
		n=read();
		for(int i=1;i<=n;i++)res[i]=0;
		for(int i=1;i<=n;i+=3)st[++B]=query(i,i+1,i+2);
		int z=0,o=0,p0=0,p1=0;
		for(int i=1;i<=B;i++)if(!st[i])z=i;else o=i;
		int a=3*o-2,b=3*o-1,c=3*o;
		int cnt1=0,cnt3=0,pos1=0,pos3=0;
		for(int i=3*z-2;i<=3*z;i++){
			int u=query(i,a,b),v=query(i,b,c);
			if(u+v<=1)cnt1++,pos1=i;else cnt3++,pos3=i;
		}
		if(cnt3==3){
			p1=a;res[a]=res[b]=res[c]=1;
			a=3*z-2,b=3*z-1,c=3*z;
			if(!query(a,b,p1)){
				p0=a;
				if(query(a,c,p1))res[c]=1;
			}
			else{
				p0=c;
				if(query(a,c,p1))res[a]=1;else res[b]=1;
			}
		}
		else if(cnt3==1){
			p0=pos1,p1=pos3;res[p1]=1;
			if(query(p0,a,b))res[a]=res[b]=1,res[c]=query(p0,p1,c);
			else{
				res[c]=1;
				if(query(p0,p1,a))res[a]=1;else res[b]=1;
			}
		}
		else{
			p0=3*z-2;
			if(!query(p0,a,b)){
				p1=c,res[p1]=1;
				if(!query(p0,p1,a))res[b]=1;else res[a]=1;
			}
			else{
				p1=a;res[a]=res[b]=1;
			}
		}
		for(int i=1;i<=B;i++){
			a=3*i-2;b=3*i-1;c=3*i;
			if(i!=o&&i!=z){
				if(st[i]){
					if(!query(a,b,p0)){
						res[c]=1;
						if(query(a,p0,p1))res[a]=1;
						else res[b]=1;
					}
					else{
						res[a]=res[b]=1;
						res[c]=query(c,p0,p1);
					}
				}
				else{
					if(query(a,b,p1)){
						if(!query(a,p0,p1))res[b]=1;
						else res[a]=1;
					}
					else{
						if(query(c,p0,p1))res[c]=1;
					}
				}
			}
		}
		printf("! ");
		int ans=0;
		for(int i=1;i<=n;i++)if(!res[i])ans++;
		printf("%d ",ans);
		for(int i=1;i<=n;i++)if(!res[i])printf("%d ",i);
		printf("\n");fflush(stdout);
	}
    return 0;
}