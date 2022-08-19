#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;

char str[MAXN];

int main(){
	int tc; scanf("%d",&tc);
	while(tc--){
		scanf("%s", str);
		int n = strlen(str);
		sort(str, str + n);
		if(str[0] == str[n-1]) puts("-1");
		else puts(str);
	}
}