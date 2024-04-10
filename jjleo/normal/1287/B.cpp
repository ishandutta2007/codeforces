#include <bits/stdc++.h>
#define maxn 1586

using namespace std;

int n, k;
unordered_map<string, bool> mp;
char s[35];
string S[maxn];
string ss;
bool tag[3];
long long ans;

int main(){
	scanf("%d%d", &n, &k);
	for(register int i = 1;i <= n;i++){
		scanf("%s", s);
		S[i] = s;
		mp[S[i]] = true;
	}
	for(register int i = 1;i <= n;i++){
		for(register int j = i + 1;j <= n;j++){
			if(i == j) continue; 
			mp[S[i]] = false, mp[S[j]] = false;
			for(register int a = 0;a < k;a++){
				if(S[i][a] == S[j][a]) s[a] = S[i][a];
				else{
					s[a] = 'S' + 'E' + 'T' - S[i][a] - S[j][a];
					/*memset(tag, 0, sizeof(tag));
					switch(S[i][a]){
						case 'S':
							tag[0] = true;
							break;
						case 'E':
							tag[1] = true;
							break;
						case 'T':
							tag[2] = true;
							break;
					}
					switch(S[j][a]){
						case 'S':
							tag[0] = true;
							break;
						case 'E':
							tag[1] = true;
							break;
						case 'T':
							tag[2] = true;
							break;
					}
					if(!tag[0]) s[a] = 'S';
					else if(!tag[1]) s[a] = 'E';
					else s[a] = 'T';*/
				}
			}
			ss = s;
			ans += mp[ss];
			mp[S[i]] = true, mp[S[j]] = true;
		}
	}
	printf("%lld", ans / 3);
}