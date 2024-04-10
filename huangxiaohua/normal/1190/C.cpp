#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,p[1005000];
string a;
set<int> s1;

bool chk(int l,int r){
	int t1,t2,t3;
	
	t1=*s1.upper_bound(0);
	if(t1<l){

	}
	else{
		t1=*s1.upper_bound(r);
	}
	
	t2=*--s1.upper_bound(n);
	if(t2>r){

	}
	else{
		t2=*--s1.lower_bound(l);
	}
	
	//printf("NMSL%d %d %d %d\n",l,r,t1,t2);
	return (t2-t1+1)>m;
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m>>a;
	a="X"+a;
	for(auto &i:a)i-='0';
	for(i=1;i<=n;i++){
		p[i]=p[i-1]+a[i];
	}
	for(i=m;i<=n;i++){
		k=p[n]+p[i-m]-p[i];
		if(!k||k==(n-m)){
			cout<<"tokitsukaze";
			return 0;
		}
	}
	
	s1.clear();
	s1.insert(-100);
	s1.insert(n+100);
	for(i=1;i<=n;i++){
		if(a[i]==0){
			s1.insert(i);
		}
	}
	for(i=m;i<=n;i++){
		if(chk(i-m+1,i))goto aaa;
	}
	
	s1.clear();
	s1.insert(-100);
	s1.insert(n+100);
	for(i=1;i<=n;i++){
		if(a[i]==1){
			s1.insert(i);
		}
	}
	for(i=m;i<=n;i++){
		if(chk(i-m+1,i))goto aaa;
	}
	
	cout<<"quailty";return 0;
	aaa:;
	cout<<"once again";
}