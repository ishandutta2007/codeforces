#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define LL long long
#define N 5050
using namespace std;
int n;
int a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
    	if(a[a[a[i]]]==i){
    		printf("YES\n");return 0;
		}
	}
	printf("NO\n");
	return 0;
}