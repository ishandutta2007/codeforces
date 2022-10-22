#include<bits/stdc++.h>
using namespace std;
const int M=2e5+9;
int n;
int b[M],a[M];
void work(){
	set<int>s;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&b[i]);
	}
	s.insert(b[1]);
	s.insert(1e9+1);
	s.insert(-1e9-1);
	for(int i=2;i<=n;++i){
		if(b[i]>b[i-1]){
			if(*s.upper_bound(b[i-1])<b[i]){
				printf("NO\n");
				return;
			}
		}
		if(b[i]<b[i-1]){
			if(*s.upper_bound(b[i])<b[i-1]){
				printf("NO\n");
				return;
			}
		}
		s.insert(b[i]);
	}
	printf("YES\n");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}