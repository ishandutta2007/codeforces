#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,ty;

struct sb{
	int l1,r1,l2,r2;
	bool operator<(const sb x)const{
		if(ty==1){
			return l1<x.l1;
		}
		else{
			return l2<x.l2;
		}
	}
}s;

vector<sb> v;

void chk(vector<sb> v){
	if(v.size()==1){return;}
	vector<sb> v1,v2;
	
	int i,j,k,r,n=v.size();
	ty=1;r=0;
	sort(v.begin(),v.end());
	
	/*for(i=0;i<n;i++){
		printf("a%d %d %d %d\n",v[i].l1,v[i].r1,v[i].l2,v[i].r2);
	}cout<<endl;*/
	
	for(i=0;i<n;i++){
		if(i&&v[i].l1>=r){
			for(j=0;j<i;j++){
				v1.push_back(v[j]);
			}
			for(j=i;j<n;j++){
				v2.push_back(v[j]);
			}
			chk(v1);chk(v2);
			return;
		}
		r=max(r,v[i].r1);
	}
	
	ty=2;r=0;
	sort(v.begin(),v.end());
	for(i=0;i<n;i++){
		if(i&&v[i].l2>=r){
			for(j=0;j<i;j++){
				v1.push_back(v[j]);
			}
			for(j=i;j<n;j++){
				v2.push_back(v[j]);
			}
			chk(v1);chk(v2);
			return;
		}
		r=max(r,v[i].r2);
	}
	puts("NO");exit(0);
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d",&s.l1,&s.l2,&s.r1,&s.r2);
		v.push_back(s);
	}
	chk(v);
	puts("YES");
}