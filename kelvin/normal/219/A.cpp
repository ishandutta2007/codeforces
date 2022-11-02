#include <cstdio>
#include <cstring>
#define MAXL 1050

int k,l;
char s[MAXL];

int c[200],zl;
char z[MAXL];

bool solve() {
   for(int i=0;i<l;i++)
      c[s[i]]++;
   zl=0;
   for(int i='a';i<='z';i++) {
      if(c[i]%k) return 0;
      int t=c[i]/k;
      for(int j=0;j<t;j++)
         z[zl++]=i;
   }
   z[zl]='\0';
   for(int i=0;i<k;i++)
      printf("%s",z);
   puts("");
   return 1;
}

int main(void)
{
   scanf("%d %s",&k,s);
   l=strlen(s);
   if(!solve()) puts("-1");
   return 0;
}