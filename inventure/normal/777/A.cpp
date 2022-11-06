#include <bits/stdc++.h>

inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

using namespace std;

int main(int argc,char *argv[]){
//	freopen( "in.txt" , "r" , stdin );
	int n ;
	cin >> n;
	n %= 6;
	int a[3] = {0,1,2};
	for(int i = 1 ; i <= n ; ++ i){
		if( i & 1 )
			swap( a[0] , a[1] );
		else
			swap( a[1] , a[2] );
	}
	int x;
	cin >> x;
	cout << a[x] << endl;
	return 0;
}