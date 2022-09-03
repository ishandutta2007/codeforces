#include<cstdio>
#include<algorithm>

char a[2222222];
char s[4444444];
int d[4444444];
int l[2222222];
int r[2222222];
long long t[2222222];

const int mod=51123987;

int main()
{
	long long res=0;
	int i,j,k,n;
	scanf("%d%s",&n,a);
    for(i=0;i<n+n+1;i++)
	{
		if(i&1)s[i]=a[i/2];
        else s[i]=' ';
	}
    j=0;
	for(i=0;i<n+n+1;i++)
	{
		d[i]=std::min(d[j+j-i],std::max(0,j+d[j]-i));
		while(i-d[i]>=0&&i+d[i]<n+n+1&&s[i-d[i]]==s[i+d[i]])d[i]++;
        if(i+d[i]>j+d[j])j=i;
        res+=d[i]/2;
        l[(i+1)/2]++;l[(i-d[i]+1)/2]--;
        r[i/2+1]++;r[(i+d[i]+1)/2]--;
	}
	res%=mod;
	res=res*(res-1)/2%mod;
	for(i=2222222;i--;t[i]=(t[i+1]+l[i])%mod)l[i]+=l[i+1];
	for(i=0;++i<2222222;res-=r[i]*t[i+1]%mod)r[i]+=r[i-1];
	printf("%I64d",(res%mod+mod)%mod);
}