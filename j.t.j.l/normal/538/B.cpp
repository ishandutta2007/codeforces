#include<bits/stdc++.h>

using namespace std;

int main(){
	char s[10];
	scanf("%s", s);
	int l = strlen(s);
	int m = 0;
	for(int i = 0; i < l; i++)
		m = max(m, s[i] - '0');
	cout<<m<<endl;
	for(int i = 1; i <= m; i++){
		int k = 0;
		for(int j = 0; j < l; j++)
			if (s[j] > '0'){
				k = k * 10 + 1;
				s[j]--;
			}
			else
				k *= 10;
		printf("%d%c", k, " \n"[i == m]);
	}
	return 0;
}