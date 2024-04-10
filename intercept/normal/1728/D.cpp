#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=2e3+9;
int n;
char s[M];
void work(){
	cin>>(s+1);
	n=strlen(s+1);
	int l=1,r=n;
	while(s[l]==s[r])l++,r--;
	for(int i=l;i<=r;i+=2){
		if(s[i]!=s[i+1]){
			puts("Alice");
			return;
		}
	}
	puts("Draw");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
5
ab
dd
aabbdffd
abccba
aafddfaa
*/