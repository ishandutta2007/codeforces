#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int dp[5100][510],d,s;
pii pre[5100][510];
queue<pii>Q;
vector<int> v;
int main(){
	scanf("%d%d",&d,&s);
	if(s==0){
		puts("0");
		return 0;
	}
	for(int i=1;i<=9;++i)dp[i][i%d]=1,Q.push(pii(i,i%d));
	while(Q.size()){
		pii p=Q.front();
		Q.pop();
		int S=p.first,D=p.second;
		for(int i=0;i<=9;++i){
			int nS=S+i,nD=(D*10+i)%d;
			if(nS<=s&&!dp[nS][nD]){
				dp[nS][nD]=dp[S][D]+1;
				Q.push(pii(nS,nD));
				pre[nS][nD]=pii(S,D);
			}
		}
	}
	if(!dp[s][0]){
		puts("-1");
	} else {
		int ns=s,nd=0;
		while(1){
			if(dp[ns][nd]==1){
				v.push_back(ns);
				break;
			} else {
				pii x=pre[ns][nd];
				v.push_back(ns-x.first);
				ns=x.first,nd=x.second;
			}
		}
		for(int i=v.size()-1;i>=0;--i)printf("%d",v[i]);
	}
	
}