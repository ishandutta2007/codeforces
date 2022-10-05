#include <bits/stdc++.h>
using namespace std;

char str[100010];

int main(){
	scanf("%s", str);
	int i = 0;
	while(str[i] == 'a') i++;
	if(!str[i]){
		str[i - 1] = 'z';
		puts(str);
		return 0;
	}
	while(str[i] != 'a' && str[i]){
		str[i]--;
		i++;
	}
	puts(str);
	return 0;
}