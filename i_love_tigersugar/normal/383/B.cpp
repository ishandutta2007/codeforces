#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
map<int,vector<int> > blk;
map<int,vector<ii> > all;
int n,m;
void exitno(void) {
	printf("-1");
	exit(0);
}
bool cmpy(const ii &a,const ii &b) {
	return (a.se<b.se);
}
void process(void) {
	scanf("%d",&n);
	scanf("%d",&m);	
	REP(i,m) {
		int x,y;
		scanf("%d",&x);
		scanf("%d",&y);
		blk[x].push_back(y);
	}
	FORE(it,blk) {
		vector<int> &cv=it->se;
		vector<ii> &ins=all[it->fi];
		cv.push_back(n+1);
		sort(cv.begin(),cv.end());
		cv.resize(unique(cv.begin(),cv.end())-cv.begin());
		if (cv[0]>1) ins.push_back(ii(1,cv[0]-1));
		REP(i,cv.size()-1) if (cv[i]+1<cv[i+1]) ins.push_back(ii(cv[i]+1,cv[i+1]-1));
	}
	int prev=0;
	FORE(it,all) {		
		int cur=it->fi;		
		vector<ii> &cv=it->se;
		if (cv.empty()) exitno();
		if (cur==1) {
			if (cv[0].fi>1) exitno();
			cv.resize(1);
		}
		else {
			vector<ii> &pv=all[prev];
			if (prev<cur-1) {
				if (prev==0) pv=vector<ii>(1,ii(1,n));
				else {
					int t=pv[0].fi;
					pv=vector<ii>(1,ii(t,n));
				}				
			}
			vector<ii> aft;
			FORE(jt,cv) {
				int u=jt->fi;
				int v=jt->se;
				int p=lower_bound(pv.begin(),pv.end(),ii(u,u),cmpy)-pv.begin();
				if (p<pv.size() && pv[p].fi<=v) aft.push_back(ii(max(u,pv[p].fi),v));
			}
			cv=aft;
			if (cv.empty()) exitno();
			if (cur==n && cv[cv.size()-1].se<n) exitno();
		}
		prev=cur;
	}
	printf("%d",2*n-2);
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	process();
	return 0;
}