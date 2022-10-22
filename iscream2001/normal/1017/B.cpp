#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<set>
#define LL long long
using namespace std;
const int N=1e5+10;
struct P{
	int sum,id;
}a[N];
bool cmp(P A,P B){
	if(A.sum!=B.sum) return A.sum>B.sum;
	return A.id<B.id;
}
int n;
char s[N],t[N];
LL A=0,B=0,C=0,D=0;
int main(){
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='0'&&t[i]=='0') ++A;
		if(s[i]=='1'&&t[i]=='0') ++B;
		if(s[i]=='0'&&t[i]=='1') ++C;
		if(s[i]=='1'&&t[i]=='1') ++D;
	}
	LL ans=A*B+A*D+B*C;
	printf("%I64d\n",ans);
	return 0;
}