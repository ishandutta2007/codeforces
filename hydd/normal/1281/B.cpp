#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,ans,len1,len2,loc[5100];
char s[5100],t[5100];
int main(){
	scanf("%d",&T);
	while (T--){
		memset(s,0,sizeof(s)); memset(t,0,sizeof(t));
		scanf("%s%s",s+1,t+1);
		len1=strlen(s+1); len2=strlen(t+1);
		loc[len1]=len1;
		for (int i=len1-1;i>=1;i--)
			if (s[i]<s[loc[i+1]]) loc[i]=i;
			else loc[i]=loc[i+1];
		for (int i=1;i<=len1;i++)
			if (s[i]>s[loc[i]]){
				swap(s[i],s[loc[i]]);
				break;
			}
		ans=0;
		for (int i=1;i<=len1&&i<=len2;i++)
			if (s[i]<t[i]){ ans=1; break;}
			else if (s[i]>t[i]){ ans=-1; break;}
		if (ans==1) printf("%s\n",s+1);
		else if (ans==-1) puts("---");
		else{
			if (len1<len2) printf("%s\n",s+1);
			else puts("---");
		}
	}
	return 0;
}