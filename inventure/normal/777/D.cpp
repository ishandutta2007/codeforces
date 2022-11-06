#include <bits/stdc++.h>

inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
#define input_fast std::ios::sync_with_stdio(false);std::cin.tie(0)

using namespace std;

const int maxn = 1e6 + 50;
const int inf = 1 << 30;

vector < string > str , Answer;
vector < vector < int > > dp , pre;
int n ;

inline void upd( int & x , int v ){
	x = min( x , v );
}

int main(int argc,char *argv[]){
	input_fast;
	string tmp;
	cin >> n >> tmp;
	str.emplace_back( tmp );
	int len = tmp.size();
	vector < int > os , os2;
	os.resize( str.back().size() , 0 );
	os2.resize( str.back().size() , 0 );
	for(int i = 0 ; i < len ; ++ i)
		os[i] = len - i - 1;
	dp.emplace_back( os );
	pre.emplace_back( os2 );
	for(int i = 1 ; i < n ; ++ i){
		cin >> tmp;
		int prelen = str.back().size();
		str.emplace_back( tmp );
		int curlen = tmp.size();
		vector < int > os , os2 ;
		os.resize( str.back().size() , 0 );
		os2.resize( str.back().size() , 0 );
		int find = 1 , as;
		for(int j = 0 ; j < min( curlen , prelen ) ; ++ j){
			if( str[i][j] > str[i - 1][j] ){
				int mindp = inf , best = -1;
				for(int z = 0 ; z < prelen ; ++ z){
					if( dp[i - 1][z] < mindp )
						best = z;
					mindp = min( mindp , dp[i - 1][z] );
				}
				for(int v = j ; v < curlen ; ++ v){
					os[v] = mindp + curlen - v - 1;
					os2[v] = best;
				}
				mindp = inf , best = -1;
				for(int v = 0 ; v < j ; ++ v){
					if( dp[i - 1][v] < mindp )
						best = v;
					mindp = min( mindp , dp[i - 1][v] );
					os[v] = mindp + curlen - v - 1;
					os2[v] = best;
				}
				find = 2;
				break;
			}else if( str[i][j] == str[i - 1][j] )
				continue;
			else{
				find = -1;
				as = j;
				break;
			}
		}
		if( find == 1 ){
			int mindp = inf , best;
			for(int z = 0 ; z < curlen ; ++ z){
				if( z < prelen ){
					if( dp[i - 1][z] < mindp )
						best = z;
					mindp = min( mindp , dp[i - 1][z] );
				}
				os[z] = mindp + curlen - z - 1;
				os2[z] = best;
			}
		}else if( find == -1 ){
			int mindp = inf , best;
			for(int z = 0 ; z < curlen ; ++ z){
				if( z < as ){
					if( dp[i - 1][z] < mindp )
						best = z;
					mindp = min( mindp , dp[i - 1][z] );
				}
				os[z] = mindp + curlen - z - 1;
				os2[z] = best;
			}
		}
		dp.emplace_back( os );
		pre.emplace_back( os2 );
	}
	int ans = inf , best;
	len = str.back().size();
	for(int i = 0 ; i < len ; ++ i){
		if( dp[n - 1][i] < ans )
			best = i;
		ans = min( ans , dp[n - 1][i] );
	}
	for(int i = n - 1 ; i >= 0 ; -- i){
		len = str[i].size();
		string oq;
		for(int j = 0 ; j <= best ; ++ j)
			oq.push_back( str[i][j] );
		Answer.emplace_back( oq );
		best = pre[i][best];
	}
	for(int i = Answer.size() - 1 ; i >= 0 ; -- i)
		cout << Answer[i] << endl;
	return 0;
}