#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))

int i,j,k,n,m,t;
tuple<int,int,int> res;

struct sb{
	int id,w,t;
	bool operator<(const sb x)const{return w>x.w;}
}s;

set<struct sb> st;

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;
		s={i,k,0};
		auto it=st.find(s);
		if(it!=st.end()){res={0,i,(*it).id};}
		st.insert(s);
	}
	
	while(1){
		s=*st.begin();st.erase(st.begin());
		if(!s.w)break;
		for(i=1;i<s.w;i<<=1);
		s.w=i-s.w;s.t++;
		auto it=st.find(s);
		if(it!=st.end()){
			res=max(res,{s.t+(*it).t,s.id,(*it).id});
			if(s.t<(*it).t){s=(*it);}
			st.erase(it);
		}
		st.insert(s);
	}
	auto [x,y,z]=res;
	cout<<y<<' '<<z<<' '<<x;
}