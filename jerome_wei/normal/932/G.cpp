#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
const int mod = 1e9+7;
char s[N], ss[N];
int n;
int anc[N],diff[N],f[N],g[N];

struct Palindromic_Tree{
	struct Node{
		int ch[26],fa,len;
	}t[N<<1];
	int last, tot;
	inline void init(){
		t[tot=1].len=-1;
		t[0].fa=1,t[1].fa=1;
		anc[0]=1;
	}
	void extend(int c,int n,char *s){
		int p=last;
		while(s[n-t[p].len-1]!=s[n])p=t[p].fa;
		if(!t[p].ch[c]){
			int v=++tot,k=t[p].fa;
			t[v].len=t[p].len+2;
			while(s[n-t[k].len-1]!=s[n])k=t[k].fa;
			t[v].fa=t[k].ch[c];
			t[p].ch[c]=v;
			diff[v]=t[v].len-t[t[v].fa].len;
			anc[v]=(diff[v]==diff[t[v].fa])?anc[t[v].fa]:t[v].fa;
		}
		last = t[p].ch[c];
	}
}PAM;

int main()
{
	scanf("%s",ss+1);n=strlen(ss+1);
	if(n%2){
		puts("0");
		return 0;
	}
	PAM.init();
	for(int i=1;i<=n;i+=2)s[i]=ss[(i+1)>>1];
	reverse(ss+1,ss+n+1);
	for(int i=2;i<=n;i+=2)s[i]=ss[(i+1)>>1];
	f[0]=1;
	for(int i=1;i<=n;i++){
		PAM.extend(s[i]-'a',i,s);
		// cout << i << ":::" << endl;
		for(int k=PAM.last;k;k=anc[k]){
			g[k]=f[i-PAM.t[anc[k]].len-diff[k]];
			// cout << k << "::" << i-PAM.t[anc[k]].len-diff[k] << endl;
			if(anc[k]!=PAM.t[k].fa){
				g[k]=(g[k]+g[PAM.t[k].fa])%mod;
			}
			if(!(i&1))f[i]=(f[i]+g[k])%mod;
		}
	}
	cout << f[n] << endl;
}