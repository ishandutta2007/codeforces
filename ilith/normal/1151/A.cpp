#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a;i<=b;++i)
#define log(a) cerr<<#a<<'='<<(a)<<" @ line "<<__LINE__<<endl
typedef long long ll;
using namespace std;
const int N=400010;
int n,ans=N;
char a[N];
int dis(char x,char y){
	if(x>y)swap(x,y);
	return min(abs(x-y),abs(x+26-y));
}
signed main(){
	scanf("%d%s",&n,a+1);
	FOR(i,1,n-3){
		ans=min(ans,dis(a[i],'A')+dis(a[i+1],'C')+dis(a[i+2],'T')+dis(a[i+3],'G'));
	}
	printf("%d",ans);
	return 0;
}