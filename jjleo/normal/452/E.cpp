#include <bits/stdc++.h>
#define maxn 300086
using namespace std;

const int p = 1e9 + 7;

struct Node{
	int len, link;
	int edge[26];
	int siz[3];
}t[maxn << 1];

int cnt;

void init(){
	t[1].len = 0;
	t[1].link = 0;
	cnt = 1;
}

inline int insert(char c, int last){
	int x = c - 'a';
	if(t[last].edge[x] && t[t[last].edge[x]].len == t[last].len + 1) return t[last].edge[x];//  
	int cur = ++cnt;
	t[cur].len = t[last].len + 1;
	int p = last;
	for(;p && !t[p].edge[x];p = t[p].link) t[p].edge[x] = cur;
	if(!p){
		t[cur].link = 1;
	}else{
		int q = t[p].edge[x];
		if(t[q].len == t[p].len + 1){
			t[cur].link = q;
		}else{
			int clone = (p == last) ? cur : (++cnt);//!edge[x] cur clone 
			t[clone].len = t[p].len + 1;
			memcpy(t[clone].edge, t[q].edge, sizeof(t[q].edge));
			if(p != last) t[cur].link = clone;//plastcur=clone debug: p 
			for(;p && t[p].edge[x] == q;p = t[p].link) t[p].edge[x] = clone;
			t[clone].link = t[q].link;
			t[q].link = clone;
		}
	}
	return cur;
}

int last, len, maxl, minl = maxn;
char s[maxn];

int bk[maxn];
int sa[maxn << 1];
int ans[maxn], sum;

int main(){
	init();
	last = 1, scanf("%s", s + 1), len = strlen(s + 1), maxl = max(maxl, len), minl = min(minl, len);
	for(int i = 1;i <= len;i++) last = insert(s[i], last), t[last].siz[0]++;
	last = 1, scanf("%s", s + 1), len = strlen(s + 1), maxl = max(maxl, len), minl = min(minl, len);
	for(int i = 1;i <= len;i++) last = insert(s[i], last), t[last].siz[1]++;
	last = 1, scanf("%s", s + 1), len = strlen(s + 1), maxl = max(maxl, len), minl = min(minl, len);
	for(int i = 1;i <= len;i++) last = insert(s[i], last), t[last].siz[2]++;
	
	//debug: 1gg 
	for(int i = 2;i <= cnt;i++) bk[t[i].len]++;
	for(int i = 2;i <= maxl;i++) bk[i] += bk[i - 1];
	for(int i = 2;i <= cnt;i++) sa[bk[t[i].len]--] = i;
	
	for(int i = cnt - 1;i;i--){
		sum = 1ll * t[sa[i]].siz[0] * t[sa[i]].siz[1] % p * t[sa[i]].siz[2] % p;//debug:1ll 
		ans[t[t[sa[i]].link].len + 1] += sum;//debug:linklen+1 
		if(ans[t[t[sa[i]].link].len + 1] >= p) ans[t[t[sa[i]].link].len + 1] -= p;
		ans[t[sa[i]].len + 1] += p - sum;
		if(ans[t[sa[i]].len + 1] >= p) ans[t[sa[i]].len + 1] -= p;
		
		t[t[sa[i]].link].siz[0] += t[sa[i]].siz[0];
		if(t[t[sa[i]].link].siz[0] >= p) t[t[sa[i]].link].siz[0] -= p;
		t[t[sa[i]].link].siz[1] += t[sa[i]].siz[1];
		if(t[t[sa[i]].link].siz[1] >= p) t[t[sa[i]].link].siz[1] -= p;
		t[t[sa[i]].link].siz[2] += t[sa[i]].siz[2];
		if(t[t[sa[i]].link].siz[2] >= p) t[t[sa[i]].link].siz[2] -= p;
	}
	for(int i = 1;i <= minl;i++){
		ans[i] += ans[i - 1];
		if(ans[i] >= p) ans[i] -= p;
		printf("%d ", ans[i]);
	}
}