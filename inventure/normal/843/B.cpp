#include <bits/stdc++.h>

using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int maxn = 1e5 + 50;

int n , start , x , ans = 1 << 30 , stpos , gu , finalquery;

std::default_random_engine generator(time(NULL));  
std::uniform_int_distribution<int> dis(0,2e9);  
auto dice = std::bind(dis,generator);

void Query( int x ){
	finalquery = x;
	cout << "? " << x << endl;
	fflush(stdout);
}

pair < int , int > Read( ){
	pair < int , int > ret;
	cin >> ret.first >> ret.second;
	return ret;
}

inline void UpdateAns( int z ){
	if( z >= x )
		ans = min( ans , z );
}

void Display(){
	if( ans == 1 << 30 ) ans = -1;
	cout << "! " << ans << endl;
	fflush(stdout);
	exit( 0 );
}

int main( int argc , char * argv[] ){
	cin >> n >> start >> x;
	stpos = start;
	int findtail = 0;
	for(int i = 1 , j = start ; i <= 500 ; ++ i){
		Query( j );
		pair < int , int > a = Read();
		UpdateAns( a.first );
		if( a.second == -1 ){
			findtail = 1;
			break;
		}
		j = a.second;
	}
	if( findtail ) Display();
	for(int i = 1 ; i <= 1000 ; ++ i){
		int pos = dice( ) % n + 1;
		Query( pos );
		pair < int , int > a = Read();
		if( a.first >= x ) UpdateAns( a.first );
		else if( a.first > gu ) gu = a.first , stpos = pos;
	}
	for(int i = 1 ; i <= 470 ; ++ i){
		Query( stpos );
		pair < int , int > a = Read();
		UpdateAns( a.first );
		if( a.second == -1 ) break;
		stpos = a.second;
	}
	Display();
	return 0;
}