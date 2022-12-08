#include<bits/stdc++.h>
using namespace std;
const int N = 2010;
typedef pair<int,int> pii;
int n,m,q;
bitset<2010> p[N],bs[N];
set<pii> table;

queue<pii> psbans;

inline bool check(int a,int b,int chk){
	int p1,p2;
	static bitset<2010> q1,q2;
	q1=(p[a]^bs[m])&p[b];
	q2=(p[b]^bs[m])&p[a];
	bool ans = q1.count()&&q2.count();
	if(chk&&ans){
		p1=q1._Find_first(),p2=q2._Find_first();
		printf("%d %d %d %d\n",min(a,b),min(p1,p2),max(a,b),max(p1,p2));
	}
	return ans;
}
int main()
{
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++)table.insert(pii(0,i));
	for(int i=1;i<=m;i++)bs[i]=bs[i-1],bs[i].set(i);
	while(q--){
		int a,l,r;scanf("%d%d%d",&a,&l,&r);		
		pii pst = pii(p[a].count(),a);
		set<pii>::iterator it = table.find(pst),lst=it,nxt=it;
		lst--,nxt++;
		if(it!=table.begin()&&nxt!=table.end()){
			if(check((*lst).second,(*nxt).second,0)){
				psbans.push(pii((*lst).second,(*nxt).second));
			}
		}
		table.erase(pst);
		p[a]=p[a]^bs[r]^bs[l-1];
		pii nw = pii(p[a].count(),a);
		table.insert(nw);
		it = table.find(nw),lst=it,nxt=it;
		lst--,nxt++;
		if(it!=table.begin()){
			if(check((*lst).second,a,0)){
				psbans.push(pii((*lst).second,a));
			}
		}
		if(nxt!=table.end()){
			if(check((*nxt).second,a,0)){
				psbans.push(pii((*nxt).second,a));
			}
		}
		while(psbans.size()){
			pii cur=psbans.front();
			if(check(cur.first,cur.second,1)){
				break;
			}else psbans.pop();
		}
		if(!psbans.size()){
			puts("-1");
		}
	}
}