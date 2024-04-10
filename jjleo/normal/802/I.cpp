#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

struct Node{//State 
	int len, link;//maxlen 
	int edge[26];
	int siz;//endpos 
}t[maxn];

int cnt, last;

void init(){
	t[1].len = 0;
	t[1].link = 0;
	last = 1;
	cnt = 1;// 
}

void insert(char c){
	int x = c - 'a';
	int cur = ++cnt;
	t[cur].len = t[last].len + 1;//1i-1 1i len+1 
	t[cur].siz = 1;//endpos   endposendpos+1 
	int p = last;
	for(;p && !t[p].edge[x];p = t[p].link) t[p].edge[x] = cur;//1-i-1 
	if(!p){
		t[cur].link = 1;
	}else{
		int q = t[p].edge[x];
		if(t[q].len == t[p].len + 1){// S[1-j]  ji 
			t[cur].link = q;
		}else{// S[1-j]  S[1-j] edge link 
			int clone = ++cnt;
			t[clone].len = t[p].len + 1;
			memcpy(t[clone].edge, t[q].edge, sizeof(t[q].edge));
			for(;p && t[p].edge[x] == q;p = t[p].link) t[p].edge[x] = clone;//q pqpq
			t[clone].link = t[q].link;
			t[q].link = t[cur].link = clone;
		}
	}
	last = cur;
}

int T; 

char s[maxn];
ll ans;
int bk[maxn];// 
int sa[maxn];//i debug: 

int main(){
	scanf("%d", &T);
	while(T--){
		init();
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		for(int i = 1;i <= len;i++) insert(s[i]);
		
		for(int i = 2;i <= cnt;i++) bk[i] = 0;
		for(int i = 2;i <= cnt;i++) bk[t[i].len]++;
		for(int i = 2;i <= len;i++) bk[i] += bk[i - 1];
		for(int i = 2;i <= cnt;i++) sa[bk[t[i].len]--] = i;
		
		ans = 0;
		for(int i = cnt - 1;i;i--){
			int j = sa[i];
			ans += 1ll * t[j].siz * t[j].siz * (t[j].len - t[t[j].link].len);
			t[t[j].link].siz += t[j].siz;
		}
		printf("%lld\n", ans);
		for(int i = 1;i <= cnt;i++) t[i].len = t[i].link = t[i].siz = 0, memset(t[i].edge, 0, sizeof(t[i].edge));
	}
}