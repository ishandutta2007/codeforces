#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

char s[MAXN];
int cnt[1000];

void read(){
	scanf("%d", &m);
	scanf("%s", s + 1);
}

int count(char ch){
	int tot = 0;
	for(int i = 1; i <= n; i++)
		tot += s[i] == ch;
	return tot;
}

int check(char ch){
	int lst = 0;
	for(int i = 1; i <= n; i++){
		if (s[i] <= ch){
			if (i - lst <= m)
				lst = i;
			else
				return 0;
		}
	}
	if (n + 1 - lst <= m)
		return 1;
	return 0;
}

vector<int> U;

PII b[MAXN];

int work(char ch){
	U.clear();
	int lst = 0;
	int p = 0;
	int pre = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if (i - lst > m){
	//		cout<<i<<endl;
			ans++;
			lst = pre;
		}
			if (s[i] < ch){
				lst = i;
			}
			else if (s[i] == ch){
				pre = i;
			}
	}
	if (ans == 0) ans = 1;
	return ans;
	/*
	if (n + 1 - lst <= m)
		b[++p] = PII(lst, n+1);
	U.push_back(n+m+233333);
	int now = 1;
	int ans = 0;
	for(int i = 0; i < U.size() - 1; i++){
		if (U[i+1] - b[p].first <= m){
			;
		}
		else{
			ans++;
			while(now <= p && b[now].second - U[i] <= m)
				now++;
			if (now > p) break;
			if (U[i] > b[now].first)
				b[now].first = U[i];
		}
	}
	if (now <= p) ans++;
	return ans;*/
	/*

	now = 1;
	int ans = 0;
	for(int i = 0; i < U.size() - 1; i++){
		if (U[i+1] - m + 1 <= b[now].first){
			;
		}
		else{
			ans++;
			while(now <= p && b[now].second <= U[i] + m - 1)
				now++;
			if (now > p) break;
			b[now].first = U[i] + m;
		}
	}
	if (now <= p) ans++;
	return ans;*/
}

void solve(){
	n = strlen(s + 1);
	for(char i = 'a'; i <= 'z'; i++)
		cnt[i] = 0;
	for(char i = 'a'; i <= 'z'; i++){
		if (check(i)){
	//		puts("= -");
			cnt[i] = work(i);
			break;
		}
		else{
			cnt[i] = count(i);
		}
	}
	for(char i = 'a'; i <= 'z'; i++)
		for(int j = 1; j <= cnt[i]; j++)
			putchar(i);
	puts("");
}

void printans(){

}
	

int main(){
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}