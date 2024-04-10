//Time Complexity : O(N)
//Space Complexity : O(N)
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int main(){
	int n;
	scanf("%d",&n);
	vector<int>t(n);
	for(int i=0;i<n;++i){
		scanf("%d",&t[i]);
	}
	int a=0,b=0;
	for(int l=0,r=n-1,t1=0,t2=0;l<=r;){
		if(t1+t[l]<=t2+t[r]){
			++a;
			t1=t1+t[l];
			++l;
		}else{
			++b;
			t2=t2+t[r];
			--r;
		}
	}
	printf("%d %d\n",a,b);
	return 0;
}