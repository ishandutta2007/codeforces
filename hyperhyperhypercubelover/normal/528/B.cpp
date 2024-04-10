#include<cstdio>
#include<algorithm>

std::pair<int,int> a[222222];
int t[444444];
int d[444444];

int T[444444];

void upd(int x,int y){while(x<444444){T[x]=std::max(T[x],y);x+=x&-x;}}
int get(int x){int y=0;while(x){y=std::max(y,T[x]);x-=x&-x;}return y;}

int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&j,&k);
		a[i].first=j+k;
        a[i].second=j-k;
        t[i]=a[i].first;
        t[i+n]=a[i].second;
	}
	std::sort(a,a+n);
	std::sort(t,t+n+n);
    for(i=0;i<n;i++)
	{
		a[i].first=std::lower_bound(t,t+n+n,a[i].first)-t+1;
		a[i].second=std::lower_bound(t,t+n+n,a[i].second)-t+1;
	}
	for(i=0;i<n;i++)upd(a[i].first,get(a[i].second)+1);
	printf("%d",get(444443));
}