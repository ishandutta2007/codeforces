#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=100005;
int n,c[26];
char s[N];
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%s",s);
		n=strlen(s);
		for(int i=0;i<26;i++)c[i]=0;
		for(int i=0;i<n;i++)c[s[i]-97]++;
		std::vector<PI>e;
		for(int i=0;i<26;i++) if(c[i])e.push_back(MP(i,c[i]));
		if(e.size()==1){
			for(int i=0;i<n;i++)putchar(97+e[0].fi);
			puts("");
			continue;
		}
		auto get=[&](int x){
			for(;!e[x].se;x++);
			return x;
		}
		;
		int u=0;
		for(;u<e.size()&&e[u].se!=1;u++);
		if(u<e.size()){
			putchar(97+e[u].fi);
			e[u].se--;
			for(int i=0;i<n-1;i++){
				int t=get(0);
				e[t].se--;
				putchar(97+e[t].fi);
			}
			puts("");
			continue;
		}
		if(e[0].se<=n/2+1){
			for(int i=0;i<2;i++)putchar(97+e[0].fi);
			e[0].se-=2;
			for(int i=0;i<n-2;i++){
				int t=get(~i&1);
				e[t].se--;
				putchar(97+e[t].fi);
			}
			puts("");
			continue;
		}
		if(e.size()==2){
			putchar(97+e[0].fi);
			e[0].se--;
			int t=e[1].se;
			e[1].se=0;
			for(int i=0;i<t;i++)putchar(97+e[1].fi);
			for(int i=0;i<n-1-t;i++){
				int t=get(0);
				e[t].se--;
				putchar(97+e[t].fi);
			}
			puts("");
			continue;
		}
		putchar(97+e[0].fi);
		putchar(97+e[1].fi);
		e[0].se--,e[1].se--;
		int t=e[0].se;
		e[0].se=0;
		for(int i=0;i<t;i++)putchar(97+e[0].fi);
		putchar(97+e[2].fi);
		e[2].se--;
		for(int i=0;i<n-3-t;i++){
			int t=get(0);
			e[t].se--;
			putchar(97+e[t].fi);
		}
		puts("");
		continue;
	}
}