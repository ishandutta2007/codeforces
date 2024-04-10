#include<bits/stdc++.h>
const int N=2e5+4;
const int INF=1e8;
using namespace std;


int n,m;
int id[N];
int a[N];
#define lowbit(x) ((x)&(-x))
int tr[N];
void add(int i,int x){
	for(;i<=n+10;i+=lowbit(i))
		tr[i]+=x;
}

int qy(int i){
	int x=0;
	for(;i;i-=lowbit(i)){
		x+=tr[i];
	}
	return x;
}
bool cmp(const int i,const int j){
	return a[i]>a[j];
}
int main()
{
	scanf("%d%d",&n,&m);
	int flag=1;
	int fir=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		id[i]=i;
		if(a[i]==m)flag=0;
		if(a[i]==0&&fir==0)fir=i;
	}
	if(flag)
	{
		if(fir==0){
			printf("NO\n");
			return 0;
		}
		a[fir]=m;
	}
	sort(id+1,id+n+1,cmp);
	int l=1;
	int r=1;
	for(int i=m;i;i--){
		if(l>n)continue;
		if(a[id[l]]!=i)continue;
		int mn=INF,mx=0;
		for(r=l;r<=n&&a[id[r]]==i;r++){
			//cout<<id[r];
			mn=min(mn,id[r]);
			mx=max(mx,id[r]);
			if(qy(id[r])){
				printf("NO\n");
				return 0;
			}
		}
		l=r;
		//cout<<mx<<mn;
		//cout<<'h';
		add(mn,1);
		add(mx+1,-1);
	}
	printf("YES\n");
	a[0]=1;
	for(int i=1;i<=n;i++){
		if(a[i])printf("%d ",a[i]);
		else{
			a[i]=a[i-1];
			printf("%d ",a[i]);
		}
	}
}