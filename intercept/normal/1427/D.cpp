#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int M=59;
int n,q=0;
int a[M],f[M],s[M],b[M],d[M];
struct P{
	int k,c[4];
};
vector<P>ans;
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
bool pd(){
	bool bol=0;
	for(int i=1;i<=n;++i)f[i]=i,s[i]=1,b[a[i]]=i;
	for(int i=1;i<=n;++i){
		if(a[i]!=i)bol=1;
		if(a[i]==a[i-1]+1&&i!=1){
			int x=find(i-1);
			f[i]=x;
			s[x]++;
		}
	}
	return bol;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	while(pd()){
		q++;
		for(int i=2;i<=n;++i){
			if(b[i]<b[i-1]){
				int x=b[i],y=find(b[i-1]);
				int k=4,a1=x-1,a2=y-x,a3=s[y],a4=n-a1-a2-a3;
				if(a1==0)k--;
				if(a4==0)k--;
				ans.pb(P{k,a1,a2,a3,a4});
				for(int j=1;j<=a4;++j)d[j]=a[j+a1+a2+a3];
				for(int j=1;j<=a3;++j)d[j+a4]=a[j+a1+a2];
				for(int j=1;j<=a2;++j)d[j+a4+a3]=a[j+a1];
				for(int j=1;j<=a1;++j)d[j+a4+a3+a2]=a[j];
				for(int j=1;j<=n;++j)a[j]=d[j];
				break;
			}
		}
	}
	printf("%d\n",q);
	for(auto o:ans){
		printf("%d ",o.k);
		for(int i=0;i<4;++i){
			if(o.c[i])printf("%d ",o.c[i]);
		}
		printf("\n");
	}
	return 0;
}