#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)){c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define int long long
const int _ = 300003; int N;
#define lowbit(x) ((x) & -(x))
struct BIT{
	int sum[_];
	void add(int x , int v){
		while(x <= 3e5){
			sum[x] += v;
			x += lowbit(x);
		}
	}
	int qry(int x){
		int A = 0;
		while(x){A += sum[x]; x -= lowbit(x);}
		return A;
	}
	int qry(int l , int r){return qry(r) - qry(l - 1);}
}sum1 , sumn;

signed main(){
	int all = 0 , ans = 0; N = read();
	for(int i = 1 ; i <= N ; ++i){
		int cnt = 0 , A = read(); ans += all + (i - 1) * A - sumn.qry(A); all += A;
		for(int p = 1 ; p * A <= 3e5 ; ++p){cnt += sum1.qry(p * A , 3e5); sumn.add(p * A , A);}
		ans -= cnt * A; printf("%lld " , ans); sum1.add(A , 1); 
	}
	return 0;
}