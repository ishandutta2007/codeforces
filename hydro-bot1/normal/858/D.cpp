// Hydro submission #62f0ce82403a5e414e08a3d0@1659948674599
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n, tot, d, cnt[N], trie[N][15];
char a[N][15], ans[15], t[15];
int read() {
	int a=0, f=1; char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) a=a*10+c-'0', c=getchar();
	return a*f;
}
void insert(char* s) {
	int x=0, len=strlen(s);
	for(int i=0;i<len;++i) {
		int a=s[i]-'0';
		if(!trie[x][a]) trie[x][a]=++tot;
		x=trie[x][a], ++cnt[x];
	}
}
void del(char* s) {
	int x=0, len=strlen(s);
	for(int i=0;i<len;++i) {
		int a=s[i]-'0';
		x=trie[x][a], --cnt[x];
	}
}
void find(char* s) {
	int x=0, len=strlen(s);
	for(int i=0;i<len;++i) {
		t[i]=s[i];
		int a=s[i]-'0';
		x=trie[x][a];
		if(cnt[x]==0) {
			if(i+1<d) {
				d=i+1;
				t[i+1]='\0';
				strcpy(ans,t);
				break;
			}
		}
	}
}
int main() {
	n=read();
	for(int i=1;i<=n;++i) {
		scanf("%s",a[i]);
		for(int j=0;j<9;++j) insert(a[i]+j);
	}
	for(int i=1;i<=n;++i) {
		d=10;
		for(int j=0;j<9;++j) del(a[i]+j);
		for(int j=0;j<9;++j) find(a[i]+j);
		for(int j=0;j<9;++j) insert(a[i]+j);
		puts(ans);
	}
}