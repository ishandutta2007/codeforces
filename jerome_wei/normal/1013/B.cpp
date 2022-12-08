#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
int n,k;
int sum[100010];
int a[200010];
int sub[200010];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
	scanf("%d",&sum[i]);
	a[sum[i]]++;
	if(a[sum[i]]<=1)sub[sum[i]]=i;
	else {
	    printf("0\n");
	    return 0;
	}
    }
    for(int i=1;i<=n;i++){
	sum[i]&=k;
	if(a[sum[i]]&&sub[sum[i]]!=i){
	    printf("1\n");
	    return 0;
	}
    }
    memset(a,0,sizeof(a));
    memset(sub,0,sizeof(sub));
    for(int i=1;i<=n;i++){
	a[sum[i]]++;
	if(a[sum[i]]<=1)sub[sum[i]]=i;
	else {
	    printf("2\n");
	    return 0;
	}
    }
    printf("-1\n");
    return 0;
}