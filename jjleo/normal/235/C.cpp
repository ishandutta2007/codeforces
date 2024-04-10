#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

struct Node{//State 
	int len, link;//maxlen 
	int edge[26];
	int siz;//endpos 
	int tag;
}t[maxn << 1];

int cnt, last;

void init(){
	t[0].len = 0;
	t[0].link = -1;
	last = 0;
	cnt = 0;// 
}

void insert(char c){
	int x = c - 'a';
	int cur = ++cnt;
	t[cur].len = t[last].len + 1;//1i-1 1i len+1 
	t[cur].siz = 1;//endpos   endposendpos+1 
	int p = last;
	for(;p != -1 && !t[p].edge[x];p = t[p].link) t[p].edge[x] = cur;//1-i-1 
	if(p == -1){
		t[cur].link = 0;
	}else{
		int q = t[p].edge[x];
		if(t[q].len == t[p].len + 1){// S[1-j]  ji 
			t[cur].link = q;
		}else{// S[1-j]  S[1-j] edge link 
			int clone = ++cnt;
			t[clone].len = t[p].len + 1;
			memcpy(t[clone].edge, t[q].edge, sizeof(t[q].edge));
			for(;p != -1 && t[p].edge[x] == q;p = t[p].link) t[p].edge[x] = clone;//q pqpq
			t[clone].link = t[q].link;
			t[q].link = t[cur].link = clone;
		}
	}
	last = cur;
}

int n, len, x, y, ans;
char s[maxn];
int bk[maxn];// 
int sa[maxn << 1];//i debug: 

int main(){
	scanf("%s", s + 1);
	len = strlen(s + 1);
	init();
	for(int i = 1;i <= len;i++) insert(s[i]);
	for(int i = 1;i <= cnt;i++) bk[t[i].len]++;
	for(int i = 2;i <= len;i++) bk[i] += bk[i - 1];
	for(int i = 1;i <= cnt;i++) sa[bk[t[i].len]--] = i;
	for(int i = cnt;i;i--) t[t[sa[i]].link].siz += t[sa[i]].siz;
	t[0].siz = 0;
	scanf("%d", &n);
	for(int k = 1;k <= n;k++){
		ans = 0;
		scanf("%s", s);
		len = strlen(s);
		x = 0, y = 1;
		for(int i = 0;i < len;i++){
			--y;
			if(x && t[t[x].link].len + 1 > y) x = t[x].link;
			while(y < len){
				if(!t[x].edge[s[(i + y) % len] - 'a']) break;
				x = t[x].edge[s[(i + y) % len] - 'a'], y++;
			}
			//debug: 
			if(y == len && t[x].tag < k) ans += t[x].siz, t[x].tag = k;
		}
		printf("%d\n", ans);
	}
}