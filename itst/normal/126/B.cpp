#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

const int _ = 1e6 + 7;
char s[_];
int z[_] , L;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	scanf("%s" , s + 1); L = strlen(s + 1);
	int l = 1 , r = 1 , Mx = 0;
	for(int i = 2 ; i <= L ; ++i){
		if(r < i){
			l = i; r = i;
			while(r <= L && s[r - l + 1] == s[r]) ++r;
			z[i] = r - l; --r;
		}
		else{
			int len = z[i - l + 1];
			if(len < r - i + 1)
				z[i] = len;
			else{
				l = i;
				while(r <= L && s[r - l + 1] == s[r]) ++r;
				z[i] = r - l; --r;
			}
		}
		Mx = max(Mx , z[i] + i == L + 1 ? z[i] - 1 : z[i]);
	}
	for(int i = Mx ; i ; --i)
		if(z[L - i + 1] == i){
			for(int j = 1 ; j <= i ; ++j)
				putchar(s[j]);
			return 0;
		}
	puts("Just a legend");
	return 0;
}