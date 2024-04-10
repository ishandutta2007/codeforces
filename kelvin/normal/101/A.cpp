#include <stdio.h>
#include <string.h>
#include <utility>
#include <algorithm>
#define MAXL 100050

using namespace std;

int l,k;
char s[MAXL];
int cnt[300]={0};

int nn;
pair<int,char> arr[26];
bool no[300]={0};

int main(void)
{
   int i,st,rem;
   scanf("%s",s);
   scanf("%d",&k);
   l=strlen(s);
   for(i=0;i<l;i++)
      cnt[s[i]]++;
   nn=0;
   for(i=0;i<26;i++)
      if(cnt['a'+i]) arr[nn++]=make_pair(cnt['a'+i],'a'+i);
   std::sort(arr,arr+nn);
   for(st=0;st<nn;st++) {
      if(k<arr[st].first) break;
      k-=arr[st].first;
      no[arr[st].second]=1;
   }
   rem=nn-st;
   printf("%d\n",rem);
   for(i=0;i<l;i++)
      if(!no[s[i]]) printf("%c",s[i]);
   puts("");
   return 0;
}