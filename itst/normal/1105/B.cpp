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

const int MAXN = 2e5 + 5;
int len[MAXN] , K , L , cnt;
char s[MAXN];

int main(){
	scanf("%d %d %s" , &L , &K , s + 1);
	for(int i = 0 ; i < 26 ; ++i){
		memset(len , 0 , sizeof(len));
		int ans = 0;
		for(int j = 1 ; j <= L ; ++j)
			if(s[j] - 'a' == i)
				if((len[j] = len[j - 1] + 1) % K == 0)
					++ans;
		cnt = max(cnt , ans);
	}
	cout << cnt;
	return 0;
}