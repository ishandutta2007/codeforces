#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

int num[52] , rev[52];
string s;
char ans[52];

int main(){
	cin >> s;
	num[1] = 1;
	for(int i = 2 ; i <= s.size() ; ++i)
		if(i & 1){
			for(int j = 1 ; j < i ; ++j)
				++num[j];
			num[i] = 1;
		}
		else
			num[i] = i;
	for(int i = 1 ; i <= s.size() ; ++i)
		rev[num[i]] = i;
	for(int i = 0 ; i < s.size() ; ++i)
		ans[rev[i + 1] - 1] = s[i];
	printf("%s" , ans);
	return 0;
}