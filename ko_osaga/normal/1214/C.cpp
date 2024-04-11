#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 1000005;

int n;
char str[MAXN];

int main(){
	scanf("%d %s",&n,str);
	int cnt = 0, minv = 1e9;
	for(int i=0; str[i]; i++){
		if(str[i] == '(') cnt++;
		else cnt--;
		minv = min(minv, cnt);
	}
	if(minv >= -1 && cnt == 0) puts("Yes");
	else puts("No");
}