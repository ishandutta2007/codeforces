#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxm 4020005
#define maxn 1000005
#define PII pair<int, int>
#define fi first
#define mkp make_pair
#define se second
#define ls (tot << 1)
#define rs (tot << 1 | 1)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 998244353;
const double eps = 1e-6;
inline ll read(){
    ll x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

char s[maxn];
int nxt[maxn];
vector<int> black, white;
bool check(int x){
	if(x < 0) return 0;
	for(int i = 1; i + 1 < black.size(); i++){
		if(((black[i] - x) & 1) && !x && (black[i] - x) > 1) return 0;
		if(!((black[i] - x) & 1) && ((black[i] - x > 2 && x <= 1) || black[i] - x == 2)) return 0; 
	}
	if(!((black[0] - x) & 1) && !x && (black[0] - x) > 2) return 0;
	if(black[0] - x == 1) return 0;
	if(((black[0] - x) & 1) && x <= 1) return 0;
	if(!((black.back() - x) & 1) && !x && (black.back() - x) > 2) return 0;
	if(black.back() - x == 1) return 0;
	if(((black.back() - x) & 1) && x <= 1) return 0;
	if(!x){
		for(int i = 1; i + 1 < black.size(); i++) if(black[i] > 1) return 0;
		if(black[0]) return 0;
		if(black.back()) return 0;
	}
	return 1;
}

vector<int> ans;
void print(){
	printf("%d\n", ans.size());
	for(auto i: ans) printf("%d ", i); 
}

void solve(int x){
	black[0] -= x;
	if(!(black[0] & 1)){
		for(int i = 1; i <= black[0] / 2; i++) ans.push_back(1);
	}
	else{
		ans.push_back(2);
		for(int i = 1; i <= (black[0] - 3) / 2; i++) ans.push_back(1);
	}
	for(int i = 0; i < white.size(); i++){
		black[i + 1] -= x;
		ans.push_back(white[i] + x);
		if(i != white.size() - 1){
			if(black[i + 1] & 1){
				for(int j = 1; j <= black[i + 1] / 2; j++) ans.push_back(1);
			}
			else {
				ans.push_back(2);
				for(int j = 1; j <= (black[i + 1] - 3) / 2; j++) ans.push_back(1);
			}
		}else{
			if(!(black[i + 1] & 1)){
				for(int j = 1; j <= black[i + 1] / 2; j++) ans.push_back(1);
			}
			else {
				ans.push_back(2);
				for(int j = 1; j <= (black[i + 1] - 3) / 2; j++) ans.push_back(1);
			}
		}
	}
	print();
}

int main(){
	scanf("%s", s);
	int n = strlen(s);
	bool t = 0;
	for(int i = 0; i < n; i++) if(s[i] == '_') t = 1;
	if(!t){
		printf("1\n%d", n);
		return 0;
	}
	int x = inf;
	int cnt = 0;
	for(int i = 0; i < n; i ++){
		if(s[i] == '#') {cnt++;continue;}
		if(cnt) white.push_back(cnt);
		cnt = 0;
	}
	if(cnt) white.push_back(cnt);
	
	
	if(s[0] == '#') black.push_back(0);
	cnt = 0;
	for(int i = 0; i < n; i ++){
		if(s[i] == '_') {cnt++;continue;}
		if(cnt) black.push_back(cnt);
		cnt = 0;
	}
	if(cnt) black.push_back(cnt);
	if(s[n - 1] == '#') black.push_back(0);
	
	
	for(int i = 1; i + 1 < black.size(); i++) x = min(x, black[i] - 1);
	x = min(x, black[0]), x = min(x, black.back());
	if(check(x)) {
		solve(x);return 0;}
	if(check(x - 3)) {solve(x - 3);return 0;}
	if(check(x - 2)) {solve(x - 2);return 0;}
	puts("-1");
	return 0;
}
/*
1
1 8 10 5 10 10
0 1 3 6
*/