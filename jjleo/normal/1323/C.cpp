#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n;
char s[maxn];
char sk[maxn];
int top;
int last;
int num;
int ans;

int main(){
	scanf("%d%s", &n, s + 1);
	for(int i = 1;i <= n;i++){
		if(s[i] == '(') num++;
		else num--;
	}
	if(num) return printf("-1"), 0;
	for(int i = 1;i <= n;i++){
		if(s[i] == ')' && top && sk[top] == '('){
			--top, --num;
		}else{
			if(!top) last = i;
			sk[++top] = s[i];
			if(s[i] == '(') num++;
			else num--;
			if(!num) ans += i - last + 1, top = 0;
		}
	} 
	printf("%d", ans);
	
}