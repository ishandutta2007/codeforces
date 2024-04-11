#include<bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
const int MAXN = 200005;
const int mod = 1e9 + 7;
using lint = long long;
using pi = pair<lint, lint>;

char str[MAXN];
char ret[MAXN];

bool Do(int x){
	int n = strlen(str);
	for(int i=0; i<n+2; i++) ret[i] = 0;
	int minst = n-1, maxst = 0;
	for(int i=0; i<n; i++){
		if(str[i] - '0' > x){
			ret[i] = '1';
			minst = min(minst, i);
		}
		if(str[i] - '0' < x){
			ret[i] = '0';
			maxst = max(maxst, i);
		}
	}
	for(int i=maxst; i<n; i++) if(str[i] == x + '0') ret[i] = '0';
	for(int i=0; i<=minst; i++) if(str[i] == x + '0') ret[i] = '1';
	string stk[2];
	for(int i=0; i<n; i++) {
		if(!ret[i]) return 0;
		stk[ret[i] - '0'].push_back(str[i]);
	}
	for(int i=0; i<2; i++){
		if(!is_sorted(stk[i].begin(), stk[i].end())) return 0;
	}
	return 1;
}

int main(){
	int tc; scanf("%d",&tc);
	while(tc--){
		scanf("%s", str);
		scanf("%s", str);
		bool good = 0;
		for(int i=0; i<10; i++){
			if(Do(i)){
				good = 1;
				for(int i=0; ret[i]; i++) ret[i]++;
				puts(ret);
				break;
			}
		}
		if(!good) puts("-");
	}
}