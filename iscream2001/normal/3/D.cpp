#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+10;
int n,m;
char s[N];
LL a[N],b[N];
priority_queue< pair<LL,LL> ,vector< pair<LL,LL> >,greater< pair<LL,LL> > > Q;
void MAIN(){
	while(!Q.empty()) Q.pop();
	LL ans=0;
	scanf("%s",s+1);
	n=strlen(s+1);m=0;
	
	int L=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='?'){
			s[i]=')';
			++m;
			scanf("%lld%lld",&a[m],&b[m]);
			ans+=b[m];
			Q.push(make_pair(a[m]-b[m],i));
			--L;
		}
		else if(s[i]=='('){
			++L;
		}
		else if(s[i]==')'){
			--L;
		}
		if(L<0){
			if(Q.empty()){
				puts("-1");
				return;
			}
			ans+=Q.top().first;
			s[Q.top().second]='(';
			Q.pop();
			++L;++L;
		}
	} 
	if(L==0){
		printf("%lld\n",ans);
		printf("%s\n",s+1);
	}
	else {
		puts("-1");
	}
	return;
}
int main(){
	int ttt=1;
	while(ttt--) MAIN();
    return 0;
}