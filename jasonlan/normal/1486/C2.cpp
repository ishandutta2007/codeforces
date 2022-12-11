#include<iostream>
#include<cstdio>
using namespace std;
int n,secp;
int Ques(int l,int r){
	printf("? %d %d\n",l,r);
	cout.flush();
	int res;
	scanf("%d",&res);
	return res;
}
int main(){
	scanf("%d",&n);
	secp=Ques(1,n);
	if(secp==1||(secp!=n&&Ques(secp,n)==secp)){
		int l=secp+1,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(Ques(secp,mid)!=secp)l=mid+1;
			else r=mid;
		}
		printf("! %d\n",l);
	}
	else{
		int l=1,r=secp-1;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(Ques(mid,secp)!=secp)r=mid-1;
			else l=mid;
		}
		printf("! %d\n",l);
	}
	return 0;
}