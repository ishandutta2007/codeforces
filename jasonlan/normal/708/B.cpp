#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll a[20];
int cnt1,cnt2;
bool process(){
	cnt1=(sqrt(a[0]*8+1)+1)/2;
	cnt2=(sqrt(a[3]*8+1)+1)/2;
	if(1ll*cnt1*(cnt1-1)!=2*a[0]||1ll*cnt2*(cnt2-1)!=2*a[3])return false;
	if(!(a[0]+a[1]+a[2]+a[3]))puts("0");
	else if(!(a[0]+a[1]+a[2])){
		while(cnt2--)printf("1");
	}
	else if(!(a[1]+a[2]+a[3])){
		while(cnt1--)printf("0");
	}
	else{
		if(cnt1*cnt2!=a[1]+a[2])return false;
		while(a[1]){
			if(a[1]>=cnt2){
				a[1]-=cnt2;
				--cnt1;
				printf("0");
			}
			else{
				--cnt2;
				printf("1");
			}
		}
		while(cnt2)printf("1"),--cnt2;
		while(cnt1)printf("0"),--cnt1;
	}
	return true;
}
int main(){
	for(register int i=0;i<4;++i)
		scanf("%lld",&a[i]);
	if(!process())puts("Impossible");
	return 0;
}