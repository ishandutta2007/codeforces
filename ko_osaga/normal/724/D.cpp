#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

vector<int> pos[128];
int chk[100005], tchk[100005];
int n, m;

int ok(int *x){
	int lst = 0;
	for(int i=1; i<=n+1; i++){
		if(i - lst > m) return 0;
		if(x[i]) lst = i;
	}
	return 1;
}
int main(){
	string str;
	cin >> m >> str;
	n = str.size();
	for(int i=0; i<str.size(); i++){
		pos[str[i]].push_back(i+1);
	}
	vector<char> v;
	chk[0] = chk[n+1] = 1;
	for(int i='a'; i<='z'; i++){
		memcpy(tchk, chk, sizeof(tchk));
		for(int j=0; j<pos[i].size(); j++){
			tchk[pos[i][j]] = 1;
		}
		if(!ok(tchk)){
			memcpy(chk, tchk, sizeof(tchk));
			for(int j=0; j<pos[i].size(); j++){
				putchar(i);
			}
			continue;
		}
		else{
			int pnt = 0, cnt = 0, lst = 0;
			for(int j=1; j<=n+1; j++){
				if(j - lst > m){
					while(pnt+1 < pos[i].size() && pos[i][pnt+1] < j) pnt++;
					lst = pos[i][pnt];
					pnt++;
					cnt++;
				}
				if(chk[j]) lst = j;
			}
			for(int j=0; j<cnt; j++) putchar(i);
			return 0;
		}
	}
}