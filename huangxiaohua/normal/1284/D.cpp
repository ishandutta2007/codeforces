#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,m,t,n;
multiset<int> sl,sr;
priority_queue<pair<int,int> >ql,qr;

struct sb{
	int ax,ay,bx,by;
	bool operator<(const sb x)const{return ax<x.ax;}
}a[100500];

void chk(){
	int i,j,k,l,r;
	for(i=1;i<=n;i++){
		while(!ql.empty()){
			auto [x,y]=ql.top();x=-x;
			if(x<a[i].ax){sl.erase(sl.find(y));ql.pop();}
			else{break;}
		}
		while(!qr.empty()){
			auto [x,y]=qr.top();x=-x;
			if(x<a[i].ax){sr.erase(sr.find(y));qr.pop();}
			else{break;}
		}
		
		l=a[i].bx;r=a[i].by;
		auto it=sl.upper_bound(r);
		auto it2=sr.lower_bound(l);it2--;
		//printf("a%d %d %d %d\n",l,r,*it,*it2);
		if(*it!=1145141919){puts("NO");exit(0);}
		if(*it2!=0){puts("NO");exit(0);}
		
		
		aaa:;
		sl.insert(l);sr.insert(r);
		ql.push({-a[i].ay,l});
		qr.push({-a[i].ay,r});
	}
}

int main() {
	sl.insert(1145141919);sr.insert(0);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d",&a[i].ax,&a[i].ay,&a[i].bx,&a[i].by);
	}
	sort(a+1,a+n+1);
	chk();
	sr.clear();sl.clear();
	sl.insert(1145141919);sr.insert(0);
	while(!ql.empty()){ql.pop();}
	while(!qr.empty()){qr.pop();}
	for(i=1;i<=n;i++){
		swap(a[i].ax,a[i].bx);
		swap(a[i].ay,a[i].by);
	}
	sort(a+1,a+n+1);
	chk();
	puts("YES");
}