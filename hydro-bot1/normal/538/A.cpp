// Hydro submission #61b9da0fdfddad484d77fc3a@1639569935459
#include<bits/stdc++.h>
using namespace std;
char s[1005],t[1005],y[1005];
int main()
{
  int i,len,tmp,j,k,x;
  scanf("%s",s);
  strcpy(t,"CODEFORCES");
  if (strcmp(s,t)==0){printf("YES\n"); return 0; }
  len=strlen(s);
  for (i=0;i<len;i++)
    for (j=i;j<len;j++)
    {
      x=-1;
      for (k=0;k<len;k++)
        if (k<i||k>j) y[++x]=s[k];
      y[x+1]='\0';
      if (strcmp(y,t)==0){printf("YES\n"); return 0; }
    }
  printf("NO\n");
  return 0;
}