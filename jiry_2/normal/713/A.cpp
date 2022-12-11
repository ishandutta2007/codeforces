#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int num[1<<19],n;
const int N=18;
char ch[30];
int getw(long long k1){
	int ans=0;
	for (int i=1;i<=19;i++){
		int k2=k1%10; k1/=10;
		if (k2&1) ans+=(1<<i-1);
	}
	return ans;
}
int getw2(){
	int ans=0; int len=strlen(ch+1);
	for (int i=len;i;i--){
		int now=len-i+1;
		if (ch[i]=='1') ans+=(1<<now-1);
	}
	return num[ans];
}
int main(){
	scanf("%d",&n);
	for (;n;n--){
		scanf("%s",ch+1);
		if (ch[1]=='+'){
			long long k2; scanf("%I64d",&k2);
			num[getw(k2)]++;
		} else if (ch[1]=='-'){
			long long k2; scanf("%I64d",&k2);
			num[getw(k2)]--;
		} else {
			scanf("%s",ch+1);
			printf("%d\n",getw2());
		}
	}
	return 0;
}