#include<bits/stdc++.h>
using namespace std;
char c[5005];
int n,i,j,k,l[26],o,m,a[26][5005],ans,b[26];
int main()
{
	scanf("%s",c);
	n=strlen(c);
	for(i=0;i<n;i++)a[c[i]-'a'][l[c[i]-'a']++]=i;
	for(i=0;i<26;i++)
	{
		for(j=m=0;j<n;j++)
		{
			memset(b,0,sizeof(b));
			for(k=0;k<l[i];k++)
			{
				o=a[i][k]+j;
				if(o>=n)o-=n;
				b[c[o]-'a']++;
			}
			for(k=o=0;k<26;k++)o+=b[k]==1;
			m=max(m,o);
		}
		ans+=m;
	}
	printf("%.10lf\n",(double)ans/n);
	return 0;
}