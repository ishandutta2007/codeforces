#include <bits/stdc++.h>

using namespace std;
#define DIM 107
#define INF 10000000000007
typedef pair<long,long> pairll;
long long n,F[DIM],s,sum,res;
int main() {
    //freopen("b.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	cin>>n;
	s=sqrt(n);
	sum = n/s;
	if (n%sum!=0)res=1;
	res+=n/sum+sum;
	cout<<res;
}