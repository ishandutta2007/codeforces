#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
char s[M];
int cnt[209];
void work(){
	cin>>(s+1);
	cnt['r'-'a']=cnt['g'-'a']=cnt['b'-'a']=0;
	for(int i=1;i<=6;++i){
		if(s[i]>='a'&&s[i]<='z'){
			cnt[s[i]-'a']++;
		}
		else {
			cnt[s[i]-'A']--;
			if(cnt[s[i]-'A']<0){
				puts("NO");
				return;
			}
		}
	}
	puts("YES");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3 6 3 19
*/