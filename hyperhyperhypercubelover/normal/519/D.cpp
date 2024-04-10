#include<cstdio>
#include<cstring>
#include<map>

int a[26];
char s[100001];
long long d[100001];

std::map<std::pair<char,long long>,int> M;

int main()
{
	long long res=0;
    int i,n;
    for(i=0;i<26;i++)scanf("%d",&a[i]);
    scanf("%s",s+1);
    n=strlen(s+1);
    for(i=1;i<=n;i++)
	{
		res+=M[std::make_pair(s[i],d[i-1])];
		d[i]=d[i-1]+a[s[i]-'a'];
        M[std::make_pair(s[i],d[i])]=M[std::make_pair(s[i],d[i])]+1;
	}
	printf("%I64d",res);
}