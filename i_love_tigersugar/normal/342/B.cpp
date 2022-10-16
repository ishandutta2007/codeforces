#include<bits/stdc++.h>
#define l   first
#define r   second
using namespace std;
typedef pair<int,int> ii;
int n,m,s,f;
map<int,ii> mp;
bool watch(const int &i,const int &t) {
	map<int,ii>::iterator it=mp.find(t);
	if (it==mp.end()) return (false);
	if ((*it).r.l>i) return (false);
	if ((*it).r.r<i) return (false);
	return (true);
}
void process(void) {
	mp.clear();
	int cur,mod,i,t,l,r;
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&s);
	scanf("%d",&f);
	for (i=1;i<=m;i=i+1) {
		scanf("%d",&t);
		scanf("%d",&l);
		scanf("%d",&r);
		mp[t]=ii(l,r);		
	}
	cur=s;
	t=0;
	if (s>f) mod=-1; else mod=1;
	while (cur!=f) {
		t++;
		if (watch(cur,t) || watch(cur+mod,t)) printf("X");
		else {
			cur=cur+mod;
			if (mod<0) printf("L");
			else printf("R");
		}
	}
}
int main(void) {
	process();
	return 0;
}