#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct tree{
	int go[26];
	int where;
}t[1100000];
string x[110000];
char ch[20000],ch2[2000];
int n,m,len,pre[20000];
vector<int>ans;
void insert(int where){
	int now=0,l=strlen(ch2+1);
	for (int i=1;i<=l;i++){
		if (ch2[i]>='A'&&ch2[i]<='Z') ch2[i]=ch2[i]-'A'+'a';
		int k1=ch2[i]-'a';
		if (t[now].go[k1]==0) t[now].go[k1]=++len;
		now=t[now].go[k1];
	}
	t[now].where=where;
}
int main(){
	scanf("%d",&n);
	scanf("%s",ch+1);
	scanf("%d",&m); len=0;
	for (int i=1;i<=m;i++){
		scanf("%s",ch2+1); x[i]=""; int len=strlen(ch2+1);
		int k1=0; unsigned long long k2=0;
		for (int j=1;j<=len;j++) x[i]=x[i]+ch2[j];
		insert(i);
	}
	memset(pre,0xff,sizeof pre);
	pre[0]=0;
	for (int now=1;now<=n;now++){
		int k1=0;
		for (int i=now;i;i--){
			int ne=ch[i]-'a';
			if (t[k1].go[ne]==0) break;
			k1=t[k1].go[ne];
			if (t[k1].where&&pre[i-1]!=-1){
				pre[now]=t[k1].where; break;
			}
		}
	}
	for (int now=n;now;){
		int k1=pre[now]; ans.push_back(k1);// cout<<k1<<endl;
		now-=x[k1].length(); 
	}
	for (int i=ans.size()-1;i>=0;i--){
		int k1=ans[i]; //cout<<x[k1];
		for (int j=0;j<x[k1].length();j++) putchar(x[k1][j]);
		putchar(' ');
	}
	putchar('\n');
	return 0;
}