#include<bits/stdc++.h>
using namespace std;

const int _ = 5e6 + 7;
char str[_] , tmp[_]; int L , K , pos;
vector < pair < int , int > > now; vector < int > len;

void Lyndon(){
	int k = 1 , i = 1 , j = 1;
	while(k <= L)
		if(++j > L || tmp[k + (j - k) % (i - k + 1)] > tmp[j]){
			int L = i - k + 1; len.push_back(L); int l = k;
			while(i < j){i += L; k += L;}
			now.push_back(make_pair(l , k)); i = j = k;
		}
		else if(tmp[k + (j - k) % (i - k + 1)] < tmp[j]) i = j;
	for(pos = now.size() - 1 ; ~pos && K > 2 ; --K , --pos)
		if(len[pos] == 1) while(pos && len[pos - 1] == 1) --pos;
		else reverse(str + L - now[pos].second + 2 , str + L - now[pos].first + 2);
	memcpy(tmp , str , sizeof(tmp)); reverse(tmp + 1 , tmp + L + 1);
}

char ans[_]; int t;
void solve1(){
	int l = L - t + 2 , r = L; memcpy(ans , str , sizeof(ans));
	while(l <= r)
		if(str[l] == str[r]){++l; --r;}
		else{
			if(str[l] > str[r]) reverse(ans + L - t + 2 , ans + L + 1);
			break;
		}
}

void solve00(){
	int i = 1 , j = 2;
	while(max(i , j) < t){
		int l = -1;
		while(++l < t) if(tmp[(i + l - 1) % (t - 1) + 1] != tmp[(j + l - 1) % (t - 1) + 1]) break;
 		if(l == t) break;
		if(tmp[(i + l - 1) % (t - 1) + 1] < tmp[(j + l - 1) % (t - 1) + 1]) j += l + 1;
		else i += l + 1;
		if(i == j) ++i;
	}
	int l1 = L - t + 2 , l2 = L - min(i , j) + 1;
	reverse(str + l1 , str + l2 + 1); reverse(str + l2 + 1 , str + L + 1);
	if(strcmp(str + 1 , ans + 1) < 0) memcpy(ans , str , sizeof(ans));
	reverse(str + l1 , str + l2 + 1); reverse(str + l2 + 1 , str + L + 1);
}

int z[_] , lcp[_];

void solve01(){
	int mx = 1 , id = 1;
	for(int i = 2 ; i <= L ; ++i){
		z[i] = max(min(mx - i , z[i - id + 1]) , 0);
		while(tmp[z[i] + 1] == tmp[z[i] + i]) ++z[i];
		if(i + z[i] > mx){mx = i + z[i]; id = i;}
	}
	mx = id = 1;
	for(int i = 1 ; i <= L ; ++i){
		lcp[i] = max(min(mx - i , z[i - id + 1]) , 0);
		while(lcp[i] + i <= L && str[lcp[i] + i] == tmp[lcp[i] + 1]) ++lcp[i];
		if(i + lcp[i] > mx){mx = i + lcp[i]; id = i;}
	}
	int pos = L - t + 2;
	for(int i = pos + 1 ; i <= L ; ++i)
		if(lcp[pos] < i - pos) pos = str[pos + lcp[pos]] < tmp[lcp[pos] + 1] ? i : pos;
		else{int t = z[i - pos + 1]; pos = tmp[i - pos + 1 + t] < tmp[1 + t] ? pos : i;}
	reverse(str + pos , str + L + 1);
	if(strcmp(str + 1 , ans + 1) < 0) memcpy(ans , str , sizeof(ans));
	reverse(str + pos , str + L + 1);
}

bool checkprefix(int l1 , int l2){
	if(2 * (t - l2) >= t - l1) return 0;
	for(int i = 0 ; i + l2 < t ; ++i) if(tmp[i + l1] != tmp[i + l2]) return 0;
	return 1;
}

void solve10(){
	int p = pos , l1 , l2;
	while(p && checkprefix(now[p - 1].first , now[p].first)) --p;
	int mn = now[p].first;
	for(int i = p + 1 ; i <= pos ; ++i){
		l1 = now[i - 1].first; l2 = now[i].first;
		int p1 = l1 + (t - l2) , p2 = l2 - 1; bool flg = 0;
		while(p1 < t && !flg)
			if(tmp[p1] == tmp[p2]){++p1; --p2;}
			else if(tmp[p1] > tmp[p2]) flg = 1;
			else break;
		if(flg) mn = now[i].first;
	}
	reverse(str + L - t + 2 , str + L - mn + 2);
	if(strcmp(str + 1 , ans + 1) < 0) memcpy(ans , str , sizeof(ans));
}

int main(){
	scanf("%s %d" , str + 1 , &K); L = strlen(str + 1);
	memcpy(tmp , str , sizeof(tmp)); reverse(tmp + 1 , tmp + L + 1); Lyndon();
	if(pos >= 0){t = now[pos].second; solve1(); if(K != 1 && pos){solve00(); solve01(); solve10();}}
	else memcpy(ans , str , sizeof(ans));
	puts(ans + 1); return 0;
}