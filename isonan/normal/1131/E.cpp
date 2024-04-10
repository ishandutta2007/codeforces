#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define int long long

string s[100001];
bool allsame[100001];
int exi[100001][26],ans[100001][26],n;
int pre[100001],suf[100001],len[100001];
int query(int x,int ch){
//	printf("%d %d\n",x,ch);
	if(!x)return 0ll;
	if(x==1)return ans[x][ch];
	if(allsame[x]){
		if(s[x][0]-'a'==ch)return (query(x-1,ch)+1)*(len[x]+1)-1;
		return exi[x-1][ch]?1ll:0ll;
	}
	else{
//		printf("%d %d %d %d %d %d\n",x,ch,s[x][0]-'a',s[x][len[x]-1]-'a',exi[x-1][ch],pre[x]+suf[x]);
		if(s[x][0]-'a'==ch&&s[x][len[x]-1]-'a'==ch)return max(ans[x][ch],exi[x-1][ch]?(pre[x]+suf[x]+1ll):0ll);
		if(s[x][0]-'a'==ch)return max(ans[x][ch],exi[x-1][ch]?(pre[x]+1ll):0ll);
		if(s[x][len[x]-1]-'a'==ch)return max(ans[x][ch],exi[x-1][ch]?(suf[x]+1ll):0ll);
		return max(ans[x][ch],exi[x-1][ch]?1ll:0ll);
	}
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		len[i]=s[i].length();
		for(int j=0;j<26;++j)exi[i][j]=exi[i-1][j];
		for(int j=0;j<len[i];++j)exi[i][s[i][j]-'a']++;
		for(int j=0,ch,length=0;j<len[i];++j){
			if(!length)length=1,ch=s[i][j]-'a';
			else if(ch==s[i][j]-'a')++length;
			else length=1,ch=s[i][j]-'a';
			ans[i][ch]=max(ans[i][ch],length);
		}
		if(exi[i][s[i][0]-'a']-exi[i-1][s[i][0]-'a']==len[i]){
			allsame[i]=1;
			continue;
		}
		for(pre[i]=1;s[i][pre[i]]==s[i][0];++pre[i]);
		for(suf[i]=1;s[i][len[i]-suf[i]-1]==s[i][len[i]-1];++suf[i]);
//		printf("%d %d %d\n",i,pre[i],suf[i]);
	}
//	for(int i=1;i<=n;i++){
//		printf("%d %d %d\n",allsame[i],pre[i],suf[i]);
//		for(int j=0;j<26;j++)printf("(%d %d)",ans[i][j],exi[i][j]);
//		putchar('\n');
//	}
	int _ans=0;
	for(int i=0;i<26;i++)_ans=max(_ans,query(n,i));
	cout<<_ans;
}