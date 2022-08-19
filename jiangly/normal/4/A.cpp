//Time Complexity : O(1)
//Space Complexity : O(1)
#include<bits/stdc++.h>
using namespace std;
int main(){
	int w;
	scanf("%d",&w);
	if(w%2==0&&w>=4){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}