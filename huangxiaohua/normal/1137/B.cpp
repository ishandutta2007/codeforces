#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
#define N 666623333
#define O 19260817

int n,m,n0,n1,len,i,j;
char a[500500],b[500500];
ll tmp1,tmp2,tmp3=1,tmp11,tmp22,tmp33=1,k1,k2;
int ans[500500],an;

int main(){
	cin>>a+1>>b+1;
	n=strlen(a+1);
	m=strlen(b+1);
	for(i=1;i<=n;i++){
		if(a[i]=='0'){n0++;}
		if(a[i]=='1'){n1++;}
	}
	for(i=1;i<=m-1;i++){
		if(b[i]=='1'){k1=107;}
		else{k1=13;}
		
		if(b[m+1-i]=='1'){k2=107;}
		else{k2=13;}
		
		tmp1=tmp1*O;tmp1+=k1;tmp1%=M;
		tmp2=(tmp2+k2*tmp3%M)%M;
		tmp3=(tmp3*O)%M;
		
		tmp11=tmp11*O;tmp11+=k1;tmp11%=N;
		tmp22=(tmp22+k2*tmp33%N)%N;
		tmp33=(tmp33*O)%N;
		
		if(tmp1==tmp2||tmp11==tmp22){len=i;}
	}
	//printf("%d\n",len);
	for(i=1;i<=len;i++){
		if(b[i]=='0'){
			if(!n0){printf("1");n1--;}
			else{printf("0");n0--;}
		}
		if(b[i]=='1'){
			if(!n1){printf("0");n0--;}
			else{printf("1");n1--;}
		}
	}
	for(i=len+1;i<=m;i++){
		an++;ans[an]=b[i]-'0';
	}

	for(i=1,j=1;i<=n-len;i++,j++){
		if(j==(an+1)){j=1;}
		
		if(ans[j]==0){
			if(!n0){printf("1");n1--;}
			else{printf("0");n0--;}
		}
		if(ans[j]==1){
			if(!n1){printf("0");n0--;}
			else{printf("1");n1--;}
		}
		
	}
}