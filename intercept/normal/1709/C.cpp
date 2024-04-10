#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=2e5+9;
int n,m;
char s[M];
void work(){
	cin>>(s+1);
	n=strlen(s+1);
	int l=0,r=0,o=0;
	for(int i=1;i<=n;++i){
		if(s[i]==')'){
			r--;
			l--;
			if(l<0){
				l=1;
				if(r>l)o=1;
			}
			if(l==r)o=0;
			else if(r<0){
				puts("NO");
				return;
			}
		}
		if(s[i]=='(')r++,l++;
		if(s[i]=='?'){
			r++;
			l--;
			if(l<0){
				l=1;
				if(r>l)o=1;
			}
		}
	}
	if((!l&&o)||l){
		puts("NO");
	}
	else puts("YES");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
??????
*/