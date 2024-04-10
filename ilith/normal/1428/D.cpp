#include<bits/stdc++.h>
#define si set<int>::iterator
using namespace std;
int a[1000010];
pair<int,int> po[4000040];
int cnt;
set<int> b[4],t[4];
signed main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
		b[a[i]].insert(i);
		t[a[i]].insert(i);
	}
	for(si it=b[3].begin();it!=b[3].end();++it) {
		si i3=t[3].upper_bound(*it),i2=t[2].upper_bound(*it),i1=t[1].upper_bound(*it);
		if(i3!=t[3].end()) {++cnt,po[cnt].second=*it,po[cnt].first=*it,++cnt,po[cnt].second=*i3,po[cnt].first=*it,t[3].erase(i3); continue;}
		if(i2!=t[2].end()) {++cnt,po[cnt].second=*it,po[cnt].first=*it,++cnt,po[cnt].second=*i2,po[cnt].first=*it,t[2].erase(i2); continue;}
		if(i1!=t[1].end()) {++cnt,po[cnt].second=*it,po[cnt].first=*it,++cnt,po[cnt].second=*i1,po[cnt].first=*it,t[1].erase(i1); continue;}
		puts("-1");
		return 0;
	}
	for(si it=b[2].begin();it!=b[2].end();++it) {
		si i1=t[1].upper_bound(*it);
		if(i1!=t[1].end()) ++cnt,po[cnt].second=*it,po[cnt].first=*it,++cnt,po[cnt].second=*i1,po[cnt].first=*it,b[1].erase(*i1),t[1].erase(i1);
		else{
			puts("-1");
			return 0;
		}
	}
	for(si it=b[1].begin();it!=b[1].end();++it) {
		++cnt,po[cnt].second=*it,po[cnt].first=*it;
	}
	cout<<cnt<<'\n';
	sort(po+1,po+1+cnt);
	for(int i=1;i<=cnt;++i) cout<<po[i].first<<' '<<po[i].second<<'\n';
	return 0;
}