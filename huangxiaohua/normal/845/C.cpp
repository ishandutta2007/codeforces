#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l=-1,r=-1;

vector<pair<int,int> > v;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&i,&j);v.push_back({i,j});
	}
	sort(v.begin(),v.end());
	for(auto [x,y]:v){
		if(l<x){
			l=y;continue;
		}
		if(r<x){
			r=y;continue;
		}
		puts("NO");return 0;
	}
	puts("YES");
}