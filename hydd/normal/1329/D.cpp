#include<bits/stdc++.h>
using namespace std;
int T,n,cnt[26]; int top,st[210000];
int now,a[210000];
char s[210000];
int getmx(){
	int res=0;
	for (int j=0;j<26;j++)
		if (cnt[j]>cnt[res]) res=j;
	return res;
}
void work(){
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=0;i<26;i++) cnt[i]=0;
	int tot=0;
	for (int i=2;i<=n;i++)
		if (s[i]==s[i-1]) tot++,cnt[s[i]-'a']++;
	printf("%d\n",max((tot+1)>>1,cnt[getmx()])+1);
	now=0; top=0;
	for (int i=1;i<=n;i++){
		a[++now]=s[i]-'a';
		if (now<=1||a[now]!=a[now-1]) continue;
		if (!top||a[now]==a[st[top]]){
			st[++top]=now;
			continue;
		}
		int mx=getmx();
		if (cnt[mx]<tot-cnt[mx]||a[st[top]]==mx||a[now]==mx){
			cnt[a[st[top]]]--; cnt[a[now]]--; tot-=2;
			printf("%d %d\n",st[top],now-1);
			a[st[top]]=a[now]; now=st[top--];
		} else st[++top]=now;
	}
	st[++top]=now+1; st[0]=1;
	for (int i=top;i>=1;i--) printf("%d %d\n",st[i-1],st[i]-1);
}
int main(){
	scanf("%d",&T);
	while (T--) work();
	return 0;
}