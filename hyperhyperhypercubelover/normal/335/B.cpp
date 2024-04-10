#include<cstdio>
#include<cstring>

int d[3000][3000];
int v[3000][3000];

char str[50001];

int count[26];

void print(int i,int j,int k)
{
if(i==j&&k<100)printf("%c",str[i]);
else if(i<j)
{
if(v[i][j]==1)print(i,j-1,k);
else if(v[i][j]==-1)print(i+1,j,k);
else
{
if(k<100)printf("%c",str[i]);
print(i+1,j-1,k+2);
if(k<100)printf("%c",str[j]);
}
}
}

int main()
{
int i,j,n;
scanf("%s",str);
n=strlen(str);
if(n<=3000)
{
for(i=0;i<n;i++)d[i][i]=1;
for(i=1;i<n;i++)for(j=i;j<n;j++)
{
if(str[j-i]==str[j])d[j-i][j]=d[j-i+1][j-1]+2;
else if(d[j-i+1][j]>d[j-i][j-1])
{
d[j-i][j]=d[j-i+1][j];
v[j-i][j]=-1;
}
else
{
d[j-i][j]=d[j-i][j-1];
v[j-i][j]=1;
}
}
print(0,n-1,0);
}
else
{
for(i=0;i<n;i++)count[str[i]-'a']++;
for(i=0;i<26;i++)if(count[i]>=100)break;
for(j=0;j<100;j++)printf("%c",i+'a');
}
}