#include<cstdio>

int a[111111];

bool check(int s,int e,int t)
{
	if(e-s==1)return t==a[s];
    if(t==0)
	{
        if(a[e-1]==1)return false;
        return check(s,e-1,1);
	}
	if(a[e-1]==1)return true;
	if(a[e-2]==0)return true;
    int i;
    for(i=e-2;i>=s&&a[i];i--);
    if(i<s)return false;
    return true;
}

void print(int s,int e,int t)
{
    if(e-s==1)
	{
		printf("%d",a[s]);
		return;
	}
	if(t==0)
	{
		printf("(");
		print(s,e-1,1);
		printf(")->0");
		return;
	}
	int i,j;
	if(a[e-1]==1)
	{
		for(i=s+1;i<e;i++)printf("(");
		printf("%d",a[s]);
        for(i=s+1;i<e;i++)printf("->%d)",a[i]);
        return;
	}
	if(a[e-2]==0)
	{
		if(e-s>2)
		{
			for(i=s+1;i<e-2;i++)printf("(");
			printf("%d",a[s]);
			for(i=s+1;i<e-2;i++)printf("->%d)",a[i]);
			printf("->");
		}
        printf("(0->0)");
        return;
	}
    for(i=e-2;i>=0&&a[i];i--);
    if(i>0)
	{
		for(j=s+1;j<i;j++)printf("(");
		printf("%d",a[s]);
		for(j=s+1;j<i;j++)printf("->%d)",a[j]);
		printf("->");
	}
    printf("(0->");
    s=i+1;
    for(i=s+1;i<e;i++)printf("(");
    printf("%d",a[s]);
    for(i=s+1;i<e;i++)printf("->%d)",a[i]);
    printf(")");
}

int main()
{
	int i,j,k,n;
	scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    if(!check(0,n,0))puts("NO");
    else
	{
		puts("YES");
		print(0,n,0);
	}
}