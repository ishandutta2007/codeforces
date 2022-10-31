#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,x=2e9+50;
multiset<int> s;
priority_queue<int,vector<int>,greater<int>> q;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		s.insert(k);q.push(k);
	}
	for(i=1;i<=n/2;i++){q.pop();}
	s.insert(x);
	while(*s.begin()!=x){
		j=*s.begin();
		k=*s.lower_bound(j+m);
		if(k!=x){s.erase(s.find(max(k,q.top())));s.erase(s.find(j));res++;q.pop();}
		else{break;}
	}
	printf("%d",res);
}