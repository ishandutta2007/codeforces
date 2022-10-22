#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;
int n,a[310000],tot[310000];
set<pii> s; set<int> t[310000]; set<pii>::iterator it;
int calc(pii tmp){ return tmp.first-tmp.second+1;}
void myerase(pii tmp){
	if (calc(tmp)>0) t[calc(tmp)].erase(tmp.first);
	s.erase(tmp);
}
void myinsert(pii tmp){
	if (calc(tmp)>0) t[calc(tmp)].insert(tmp.first);
	s.insert(tmp);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int j=n,ans=0;
	for (int i=n;i>=1;i--){
		tot[a[i]]++;
		while (tot[a[i]]>1){
			tot[a[j]]--;
			
			if (!s.empty()){
				pii tmp=*s.rbegin(); myerase(tmp); tmp.first--;
				if (!s.empty()&&s.rbegin()->first!=tmp.first||(s.empty()&&i!=tmp.first)) myinsert(tmp);
			}
			
			j--;
		}
		int pos=i;
		while (!s.empty()&&s.begin()->second<=a[i]){
			pos=s.begin()->first;
			myerase(*s.begin());
		}
		pii tmp=pii(pos,a[i]);
		myinsert(tmp);
		if (!t[i].empty()) ans+=t[i].size();
	}
	printf("%d\n",ans);
	return 0;
}