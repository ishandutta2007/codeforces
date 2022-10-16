#include<bits/stdc++.h>
#define MAX   1010
using namespace std;
vector<int> v;
struct state {
	int s,d,l;
	state(){}
	state(const int &_s,const int &_d,const int &_l) {
		s=_s;d=_d;l=_l;
	}
	bool operator != (const state &x) const {
		return (s!=x.s || d!=x.d || l!=x.l);
	}
};
typedef pair<state,int> si;
int m;
bool vst[MAX][13][13];
si t[MAX][13][13];
queue<state> q;
vector<int> res;
state f;
void init(void) {
	char s[13];
	scanf("%s",s);
	int i;
	v.clear();
	for (i=0;i<10;i=i+1)
		if (s[i]=='1') v.push_back(i+1);		
	scanf("%d",&m);
	f=state(0,0,0);
}
state BFS(void) {
	while (!q.empty()) q.pop();
	int i,ps,pd,pl;
	state p;	
	q.push(f);
	vst[0][0][0]=true;
	while (!q.empty()) {
		p=q.front();q.pop();
		ps=p.s;pd=p.d;pl=p.l;
		if (ps==m) return (p);
		for (i=0;i<v.size();i=i+1) {
			if (v[i]!=pl && v[i]>pd && !vst[ps+1][v[i]-pd][v[i]]) {				
				vst[ps+1][v[i]-pd][v[i]]=true;
				q.push(state(ps+1,v[i]-pd,v[i]));
				t[ps+1][v[i]-pd][v[i]]=si(p,v[i]);
			}
		}				
	}
	printf("NO");
	exit(0);
	return (f);
}
void trace(void) {	
	state x=BFS();
	res.clear();
	printf("YES\n");
	while (x!=f) {
		res.push_back(t[x.s][x.d][x.l].second);
		x=t[x.s][x.d][x.l].first;
	}
	printf("%d",res[res.size()-1]);
	int i;
	for (i=(int)res.size()-2;i>=0;i=i-1) printf(" %d",res[i]);
}
int main(void) {
	init();
	trace();
	return 0;
}