#include <stdio.h>
#include <string.h>
#define MAXL 305

int len;
char s[MAXL],z[MAXL];

inline bool isupper(char ch) {
   return ch>='A'&&ch<='Z';
}

inline bool isvowel(char ch) {
   if(ch=='a') return 1;
   if(ch=='e') return 1;
   if(ch=='i') return 1;
   if(ch=='o') return 1;
   if(ch=='u') return 1;
   if(ch=='y') return 1;
   return 0;
}

int main(void)
{
   scanf("%s",s);
   len=strlen(s);
   for(int i=0;i<len;i++)
      if(isupper(s[i])) s[i]=s[i]-'A'+'a';
   int zl=0;
   for(int i=0;i<len;i++) {
      if(isvowel(s[i])) continue;
      z[zl++]='.';
      z[zl++]=s[i];
   }
   z[zl]=0;
   puts(z);
   return 0;
}