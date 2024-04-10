#include<bits/stdc++.h>
using namespace std;

char s[100010];

int main(){
	int N , K;
	cin >> N >> K;
	scanf("%s" , s + 1);
	for(int i = 1 ; K && i < N ; i++)
		if(s[i] == '4' && s[i + 1] == '7')
			if(i & 1)
				if(s[i + 2] == '7'){
					if(K & 1)
						s[i + 1] = '4';
					K = 0;
				}
				else{
					K--;
					s[i + 1] = '4';
				}
			else
				if(s[i - 1] == '4'){
					if(K & 1)
						s[i] = '7';
					K = 0;
				}
				else{
					K--;
					s[i] = '7';
				}
	puts(s + 1);
	return 0;
}