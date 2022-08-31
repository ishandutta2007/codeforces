//Time Complexity : O(1)
//Space Complexity : O(1)
#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>a(4);
	for(int i=0;i<=3;++i){
		scanf("%d",&a[i]);
	}
	sort(a.begin(),a.end());
	if(a[0]+a[1]>a[2]||a[1]+a[2]>a[3]){
		printf("TRIANGLE\n");
	}else if(a[0]+a[1]==a[2]||a[1]+a[2]==a[3]){
		printf("SEGMENT\n");
	}else{
		printf("IMPOSSIBLE\n");
	}
	return 0;
}