#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>

std::set<std::pair<int,int> > S;
char s[55555];
int a[55555];
int b[55555];

int main()
{
	long long res=0;
	int i,n,now;
	scanf("%s",s);
    n=strlen(s);
    for(i=0;i<n;i++)if(s[i]=='?')scanf("%d%d",&a[i],&b[i]);
    now=0;
    for(i=0;i<n;i++)
	{
		if(s[i]=='(')now++;
		else if(s[i]==')')now--;
		else
		{
			s[i]=')';
			res+=b[i];
			now--;
            S.insert(std::make_pair(a[i]-b[i],i));
		}
		if(now<0)
		{
			if(S.empty())
			{
				puts("-1");
				return 0;
			}
			now+=2;
            res+=S.begin()->first;
            s[S.begin()->second]='(';
            S.erase(S.begin());
		}
	}
	if(now!=0)
	{
		puts("-1");
		return 0;
	}
	printf("%I64d\n%s",res,s);
}