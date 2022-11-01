#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, k;
char s[maxn];
string mn, S;

int main(){
	scanf("%d%d%s", &n, &k, s);
	for(int i = 1;i <= n;i++){
		S = "";
		for(int j = 0;j < k;j++) S += s[j % i];
		if(i == 1 || S < mn) mn = S;
	}
	printf("%s\n", mn.c_str());
}