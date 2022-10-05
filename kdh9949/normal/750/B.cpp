#include <bits/stdc++.h>
using namespace std;

int n, pos;

int main(){
	scanf("%d", &n);
	int t;
	char dir[10];
	for(int i = 0; i < n; i++){
		scanf("%d%s", &t, dir);
		if(dir[0] == 'N'){
			if(pos == 0){ puts("NO"); return 0; }
			pos -= t;
			if(pos < 0){ puts("NO"); return 0; }
		}
		else if(dir[0] == 'E' || dir[0] == 'W'){
			if(pos == 0 || pos == 20000){ puts("NO"); return 0; }
		}
		else{
			if(pos == 20000){ puts("NO"); return 0; }
			pos += t;
			if(pos > 20000){ puts("NO"); return 0; }
		}
	}
	if(pos == 0) puts("YES");
	else puts("NO");
	return 0;
}