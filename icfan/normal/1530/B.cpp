#include <cstdio>
const int Maxn=20;
int n,m;
char s[Maxn+5][Maxn+5];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s[i][j]='0';
		}
	}
	s[1][1]='1';
	s[1][m]='1';
	s[n][1]='1';
	s[n][m]='1';
	for(int j=2;j<m;j++){
		if(s[1][j-1]!='1'&&s[1][j+1]!='1'){
			s[1][j]='1';
		}
		if(s[n][j-1]!='1'&&s[n][j+1]!='1'){
			s[n][j]='1';
		}
	}
	for(int i=2;i<n;i++){
		if(s[i-1][1]!='1'&&s[i+1][1]!='1'){
			s[i][1]='1';
		}
		if(s[i-1][m]!='1'&&s[i+1][m]!='1'){
			s[i][m]='1';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			putchar(s[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}