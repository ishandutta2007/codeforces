#include<cstdio>

char a[111111];
char b[111111];

int main()
{
    int i,j,k,n,r=0;
    scanf("%d%s%s",&n,a,b);
	for(i=0;a[i]==b[i];i++);
	for(j=n-1;a[j]==b[j];j--);
	for(k=i;k<j&&a[k]==b[k+1];k++);
	if(k==j)r++;
	for(k=i;k<j&&a[k+1]==b[k];k++);
	if(k==j)r++;
	printf("%d",r);
}