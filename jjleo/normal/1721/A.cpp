#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		set<int> st;
		scanf("%s", s);
		st.insert(s[0]), st.insert(s[1]);
		scanf("%s", s);
		st.insert(s[0]), st.insert(s[1]);
		if(st.size() == 1) puts("0");
		else if(st.size() == 2) puts("1");
		else if(st.size() == 3) puts("2");
		else puts("3");
	}
}