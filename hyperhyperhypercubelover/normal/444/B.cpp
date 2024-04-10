#include<cstdio>
#include<algorithm>
#include<vector>

int x;

int a[100000];
int b[100000];
int n,d;

std::pair<int,int> A[100000];
int C[100000],Cn;
int r[100000];

unsigned long long getNextX()
{
    x = (1LL * x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
	int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        std::swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        std::swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main()
{
	int i,j;
	scanf("%d%d%d",&n,&d,&x);
    initAB();
    for(i=0;i<n;i++)
	{
        A[i].first=a[i];
        A[i].second=i;
	}
	std::sort(A,A+n);
	if(d<300)
	{
		for(i=0;i<n;i++)
		{
			if(b[i])C[Cn++]=i;
		}
		for(i=n-1;i>=0;i--)
		{
			for(j=0;j<Cn;j++)if(A[i].second+C[j]<n&&!r[A[i].second+C[j]])r[A[i].second+C[j]]=A[i].first;
		}
	}
	else
	{
        for(i=0;i<n;i++)C[Cn++]=i;
        for(i=n-1;i>=0;i--)
		{
			j=0;
			while(j<Cn)
			{
				if(C[j]-A[i].second>=0&&b[C[j]-A[i].second])
				{
					r[C[j]]=A[i].first;
					C[j]=C[--Cn];
				}
				else j++;
			}
		}
	}
	for(i=0;i<n;i++)printf("%d\n",r[i]);
}