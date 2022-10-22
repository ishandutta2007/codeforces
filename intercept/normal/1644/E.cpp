#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=2e5+9;
char s[M];
void work(){
	int n;
	cin>>n>>(s+1);
	int m=strlen(s+1);
	int x=1,y=1,p=0;
	for(int i=1;i<=m;++i){
		if(s[i]=='D')x++;
		else y++;
	}
	int lx=1,ly=1;
	for(int i=1;i<=m;++i){
		if(i>1&&s[i]!=s[i-1]){
			p=i;
			break;
		}
		if(s[i]=='D')lx++;
		else ly++;
	}
	if(s[1]=='R')swap(x,y),swap(lx,ly);
	if(p==0)cout<<n<<endl;
	else {
		cout<<1ll*(x-lx+1)*(n-y)+1ll*n*(n-x)+m+1<<endl;
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3 5
-2 -7 -1
*/