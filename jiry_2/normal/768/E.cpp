#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[61]={0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,
8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};
int n;
int main(){
	scanf("%d",&n); int ans=0;
	for (;n;n--){
		int k1; scanf("%d",&k1); ans^=A[k1];
	}
	if (ans) printf("NO\n"); else printf("YES\n");
	return 0;
}