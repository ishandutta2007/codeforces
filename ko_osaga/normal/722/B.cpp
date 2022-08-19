#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef long long lint;

int n, a[105];
char str[10005];

bool solve(int v){
	string t = "aeiouy";
	int ret = 0;
	for(int i=0; str[i]; i++){
		int ok = 0;
		for(auto &j : t){
			if(j == str[i]) ok = 1;
		}
		ret += ok;
	}
	return ret == a[v];

}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d ",&a[i]);
	}
	for(int i=0; i<n; i++){
		fgets(str, 1000, stdin);
		if(!solve(i)){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}