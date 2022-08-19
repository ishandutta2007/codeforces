#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n;
char str[1000005];
int fail[1000005];
int occd[1000005];

int main(){
	scanf("%s",str);
	n = strlen(str);
	int p = 0;
	for(int i=1; i<n; i++){
		while(p && str[p] != str[i]) p = fail[p];
		if(str[p] == str[i]) p++;
		fail[i+1] = p;
		if(i < n-1) occd[p] = 1;
	}
	for(int i=n; fail[i]; i=fail[i]){
		if(occd[fail[i]]){
			str[fail[i]] = 0;
			puts(str);
			return 0;
		}
	}
	puts("Just a legend");
}