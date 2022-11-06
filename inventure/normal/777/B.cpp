#include <bits/stdc++.h>

inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

using namespace std;

string a , b;
int n , cnt[88];
multiset < int > f;

int main(int argc,char *argv[]){
	cin >> n >> a >> b;
	for(auto it : b){
		++ cnt[it - '0'];
		f.insert( it - '0' );
	}
	int ans1 = 0 , ans2 = 0;
	for(int i = 0 ; i < n ; ++ i){
		int find = 0;
		for(int j = a[i] - '0' ; j <= 9 ; ++ j)
			if( cnt[j] ){
				find = 1;
				-- cnt[j];
				break;
			}
		if( find )
			continue;
		++ ans1;
		for(int j = 0 ; j < a[i] - '0' ; ++ j)
			if( cnt[j] ){
				-- cnt[j];
				break;
			}
	}
	memset( cnt , 0 , sizeof( cnt ) );
	sort( a.begin() , a.end() );
	for(auto it : a){
		auto c = f.upper_bound( it - '0' );
		if( c != f.end() ){
			f.erase( c );
			++ ans2;
		}else{
			-- c;
			f.erase( c );
		}
	}
	cout << ans1 << endl << ans2 << endl;
	return 0;
}