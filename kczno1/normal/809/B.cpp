#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define ll long long

int n,k,a1;

char s[5];
int f(int x)
{
	return min(abs(x-2),abs(x-3));
}
bool xiaodeng(int x,int y)
{
	printf("%d %d %d\n",1,x,y);
	fflush(stdout);
	scanf("%s",s);
	return s[0]=='T';
//	return f(x)<=f(y);
}

void check(int a2)
{
    if(a2<1||a2>n)return ;
	if(xiaodeng(a2,a1)) 
	{
		printf("%d %d %d\n",2,a1,a2);fflush(stdout);
		exit(0);
	}
}

#define mid (l+r>>1)
int erfen(int l,int r)
{
	if(l>=r) return l;
	while(l!=r)
		if(xiaodeng(mid,mid+1)) r=mid;
		else l=mid+1;
	return l;
}

int main()
{
	//freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	scanf("%d%d",&n,&k);
	a1=erfen(1,n);
	check(a1+1);check(erfen(a1+2,n));
	check(a1-1);check(erfen(1,a1-2));
}