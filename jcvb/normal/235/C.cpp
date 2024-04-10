#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
char s[1000005];int n=0,m;
char s1[2000005];int nex[1000005];

struct node{int ch[26],pre,l;}t[2000005];int ndtot=1;
int num[2000005]={0};
int cnt[1000005]={0},seq[2000005];
int rt=1,las=1;
void add(int c){
	int p=las,np=++ndtot;
	las=np;
	num[np]=1;cnt[t[np].l=t[p].l+1]++;
	for (;p && !t[p].ch[c];p=t[p].pre)t[p].ch[c]=np;
	if(!p)t[np].pre=rt;
	else{
		int q=t[p].ch[c];
		if(t[q].l==t[p].l+1)t[np].pre=q;
		else{
			int nq=++ndtot;t[nq]=t[q];
			cnt[t[nq].l=t[p].l+1]++;
			t[q].pre=t[np].pre=nq;
			for (;p && t[p].ch[c]==q;p=t[p].pre)t[p].ch[c]=nq;
		}
	}
}		
int main()
{
	scanf("%s",s+1);
	for (int i=1;s[i];i++){
		n++;
		add(s[i]-'a');
	}
	cnt[0]=1;for (int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
	for (int i=1;i<=ndtot;i++)seq[cnt[t[i].l]--]=i;
	for (int i=ndtot;i>=2;i--)num[t[seq[i]].pre]+=num[seq[i]];
	int que;scanf("%d",&que);
	while(que--){
		scanf("%s",s1+1);m=strlen(s1+1);
		nex[1]=0;
		for (int i=2,j=0;i<=m;i++){
			while(j && s1[j+1]!=s1[i])j=nex[j];
			if(s1[j+1]==s1[i])j++;
			nex[i]=j;
		}
		int r;
		int cy=m-nex[m];if(m%cy==0)r=cy;else r=m;
		for (int i=m+1;i<=m+r;i++)s1[i]=s1[i-m];
		int p=rt;
		int ans=0;
		for (int i=0,j=1;i<r;j++){
			while(p && !t[p].ch[s1[j]-'a']){
				p=t[p].pre;
				i=j-1-t[p].l;
			}
			if(t[p].ch[s1[j]-'a'])p=t[p].ch[s1[j]-'a'];
			else p=rt,i=j;
			if(j==i+m){
				ans+=num[p];
				if(t[t[p].pre].l==m-1)p=t[p].pre;
				i++;
			}
		}
		printf("%d\n",ans);		
	}
	return 0;
}