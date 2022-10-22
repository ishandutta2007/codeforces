#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=4e5+9;
int n,m,x,top=0;
int a[M],b[M],c[M],d[M],s[M],h[M];
struct P{
	int o,l;
};
vector<P>v[M];
void prepa(int&n,int *A,int *C){
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	A[0]=x+1;
	A[++n]=x+1;
	for(int i=0;i<=n;++i){
		int ma=0;
		while(top&&A[s[top]]>A[i]){
			int y=C[s[top]];
			C[s[top]]=min(C[s[top]],ma);
			ma=max(ma,y);
			top--;
		}
		C[i]=max(A[i],ma);
		s[++top]=i;
		if(i==n){
			ma=0;
			while(top){
				int y=C[s[top]];
				C[s[top]]=min(C[s[top]],ma);
				ma=max(ma,y);
				top--;
			}
		}
	}
}
void add(int i){
	for(;i<M;i+=i&-i)h[i]++;
}
int sum(int i,int rex=0){
	for(;i;i-=i&-i)rex+=h[i];
	return rex;
}
int main(){
	scanf("%d%d%d",&n,&m,&x);
	prepa(n,a,c);
	prepa(m,b,d);
	for(int i=0;i<=n;++i){
		if(c[i]==0)continue;
		v[max(x-c[i],0)].eb(P{-1,max(x-a[i]+1,1)});
		v[max(x-a[i],0)].eb(P{1,max(x-a[i]+1,1)});
	}
	for(int i=0;i<=m;++i){
		if(d[i])v[b[i]].eb(P{0,d[i]});
	}
	long long ans=0;
	for(int i=1;i<M;++i){
		for(auto o:v[i]){
			if(!o.o)add(o.l);
		}
		for(auto o:v[i]){
			if(o.o)ans+=o.o*(sum(M-1)-sum(o.l-1));
		}
	}
	printf("%lld\n",ans);
	return 0;
}