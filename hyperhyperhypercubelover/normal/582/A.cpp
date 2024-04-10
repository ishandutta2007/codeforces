#include<cstdio>
#include<algorithm>
#include<set>

std::multiset<int> S;
int a[555];

int main()
{
    int i,j,n,t;
    scanf("%d",&n);
    for(i=0;i<n*n;i++)
	{
		scanf("%d",&t);
        S.insert(t);
	}
    for(i=0;i<n;i++)
	{
        a[i]=*S.rbegin();
        printf("%d ",a[i]);
        S.erase(S.find(a[i]));
        for(j=0;j<i;j++)
		{
			t=std::__gcd(a[i],a[j]);
			S.erase(S.find(t));
			S.erase(S.find(t));
		}
	}
}