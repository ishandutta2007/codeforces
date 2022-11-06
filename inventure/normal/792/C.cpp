#include <bits/stdc++.h>
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int maxn = 2e5 + 50;

char s[maxn];
int dp[maxn][3][2],len;
pair < int , int > pre[maxn][3][2];

bool Modify( int & x , int y ){
	bool ret = false;
	if( x < y )
		ret = true , x = y;
	return ret;
}

vector < char > Answer;

int main( int argc , char * argv[] ){
	//freopen( "in.txt" , "r" , stdin );
	scanf( "%s" , s + 1 );
	int havezero = 0;
	len=strlen(s+1);
	for(int i = 1 ; i <= len ; ++ i) if( s[i] == '0' ) havezero=1;
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	for(int i = 0 ; i < len ; ++ i)
		for(int j = 0 ; j < 3 ; ++ j)
			for(int f = 0 ; f < 2 ; ++ f)
				if( ~dp[i][j][f] ){
					bool ret = Modify( dp[i + 1][j][f] , dp[i][j][f] );
					if( ret )
						pre[i + 1][j][f] = make_pair( j , f );
					if( f || s[i + 1] > '0' ){
						bool ret = Modify( dp[i + 1][(j+s[i+1]-'0')%3][1] , dp[i][j][f] + 1 );
						if( ret )
							pre[i + 1][(j+s[i+1]-'0')%3][1] = make_pair( j , f );
					}
				}
	if(dp[len][0][1]==-1){
		if(havezero)
			puts("0");
		else
			puts("-1");
	}else{
		int x = len , j = 0 , f = 1;
		while( x ){
			pair < int , int > pf = pre[x][j][f];
			if(dp[x-1][pf.first][pf.second]!=dp[x][j][f])
				Answer.emplace_back(s[x]);
			--x;
			j=pf.first;
			f=pf.second;
		}
		reverse(Answer.begin(),Answer.end());
		for(auto it : Answer)cout<<it;
		cout<<endl;
	}
	return 0;
}