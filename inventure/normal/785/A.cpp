#include <bits/stdc++.h>

inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;


int main( int argc , char * argv[] ){
	int n , ans = 0;
	cin >> n ;
	while( n -- ){
		string str;
		cin >> str;
		if( str == "Tetrahedron")
			ans += 4;
		else if( str == "Cube")
			ans += 6;
		else if( str == "Octahedron")
			ans += 8;
		else if( str == "Dodecahedron")
			ans += 12;
		else
			ans += 20;
	}
	cout << ans << endl;
	return 0;
}