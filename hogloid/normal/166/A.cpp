#include<iostream>
#include<algorithm>
#include<cstdio>
#include<deque>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,a) for(int i=a;i<(int)m;++i)
using namespace std;
int n,k;
typedef pair<int,int> pi;
#define fr first
#define sc second
pi score[105];
int main(){
	scanf("%d%d",&n,&k);
	REP(i,n){
		scanf("%d%d",&score[i].fr,&score[i].sc);
		score[i].fr=-score[i].fr;
	}
	--k;
	sort(score,score+n);
	REP(i,n){
		int j=i;
		while(j<n && score[j]==score[i]) ++j;
		if(i<=k && k<j){
			printf("%d\n",j-i);
			return 0;
		}
		i=j-1;
	}
	return 0;
}