#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define INF 314159
#define mod 1000000007

int main(){
	int n;
	scanf("%d",&n);
	int *a,*l,*r,*m;
	int prev2=-1,prev=-1,cur=-1;
	int cursum=0;
	a = new int[n];
	l = new int[n];
	m = new int[n];
	r = new int[n];
	for(int i=0;i<n;i++){
		prev2 = prev;
		prev = cur;
		scanf("%d",&cur);
		cur--;
		cursum+=cur;
		cursum%=mod;
		if(i>=1){
			l[i-1]=min(prev,cur);
		}
		if(i>=2){
			m[i-1] = min(l[i-1],prev2);
		}
		if(i>=1){
			r[i] = min(prev,cur);
		}
	}
	m[0]=r[0]=l[n-1]=m[n-1]=0;
	long long right=0;
	int index=n-2;
	long long res=0;
	while(index>=0){
		right=right*1LL*m[index+1];
		right%=mod;
		right+=r[index+1];
		right%=mod;
		res+=l[index]*1LL*right;
		res%=mod;
		index--;
	}
	res+=cursum;
	res%=mod;
	printf("%d",(int)res);
	return 0;
}