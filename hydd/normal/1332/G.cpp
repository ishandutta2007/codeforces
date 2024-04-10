#include<bits/stdc++.h>
int n,q,a[210000],l[210000],r[210000],cnt[210000];
std::vector<int> que[210000],s4,Ans[210000];
std::set<int> inc,dec,inc2,dec2,noinc,nodec,del;
std::set<int>::iterator it;
//inc have x: [i..x) <=a[x]
//noinc have x: [i..x) >a[x]
//dec have x: [i..x) >=a[x]
//nodec have x: [i..x) <a[x]

//inc2 have x: [i..x) <a[x]
//dec2 have x: [i..x) >a[x]
//del have x: [i..x) <a[x]>a[x]
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=q;i++){
		scanf("%d%d",&l[i],&r[i]);
		que[l[i]].push_back(i);
	}
	for (int i=n;i>=1;i--){
		cnt[i]=2; int x;
		while (!inc.empty()&&a[x=*inc.begin()]<a[i]){//<=
			noinc.insert(x); cnt[x]--;
			if (!cnt[x]) del.insert(x);
			inc.erase(x);
		}
		while (!dec.empty()&&a[x=*dec.begin()]>a[i]){//>=
			nodec.insert(x); cnt[x]--;
			if (!cnt[x]) del.insert(x);
			dec.erase(x);
		}
		while (!inc2.empty()&&a[x=*inc2.begin()]<=a[i]) inc2.erase(x);//<
		while (!dec2.empty()&&a[x=*dec2.begin()]>=a[i]) dec2.erase(x);//>
		if (!inc2.empty()&&!dec2.empty()){
			int v=std::max(*inc2.begin(),*dec2.begin());//<a[i]>a[i]
			it=del.upper_bound(v);//<>
			if (it!=del.end()&&(s4.empty()||*it<s4.back())){
				int u=*it;
				int s=*--inc2.lower_bound(u),t=*--dec2.lower_bound(u);
				if (s>t) std::swap(s,t);
				s4={i,s,t,u}; //assert(i<s&&s<t&&t<u);
			}
		}
		for (int j:que[i])
			if (!s4.empty()&&s4.back()<=r[j]) Ans[j]=s4;
			else{
				if (!inc2.empty()){
					it=noinc.upper_bound(*inc2.begin());//*inc2.begin() i
					//*it>*inc2.begin()*it-1
					if (it!=noinc.end()&&*it<=r[j]) Ans[j]={i,*it-1,*it};//,assert(i<*it-1);
				}
				if (!dec2.empty()){
					it=nodec.upper_bound(*dec2.begin());//*dec2.begin() i
					//*it>*dec2.begin()*it-1
					if (it!=nodec.end()&&*it<=r[j]) Ans[j]={i,*it-1,*it};//,assert(i<*it-1);
				}
			}
		inc.insert(i); dec.insert(i);
		inc2.insert(i); dec2.insert(i);
	}
	for (int i=1;i<=q;i++){
		printf("%d\n",(int)Ans[i].size());
		for (int v:Ans[i]) printf("%d ",v); putchar('\n');
	}
	return 0;
}