#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int pd1[1100000],pd2[1100000],n,A[1100000],B[1100000];
unsigned long long x[1100000],y[1100000],key=10007,Key[1100000];
char ch[1100000];
int solve(){
	memset(pd1,0x00,sizeof pd1);
	memset(pd2,0x00,sizeof pd2);
	int k1=1,k2=1;// cout<<"begin"<<endl;
	for (int now=1;;now++){
		for (int i=k1;i<n;i++)
			if (B[k2]==A[i]) k2++; else if (B[k2-1]==(A[i]^1)) k2--;
		k1=n;
	//	cout<<"fa "<<k1<<" "<<k2<<endl;
		if (pd1[k2]) return 0; if (k2==n) return 1; pd1[k2]=1;
		for (int i=k2;i<n;i++)
			if (B[i]==A[k1]) k1++; else if (A[k1-1]==(B[i]^1)) k1--;
		if (pd2[k1]) return 0; if (k1==n) return 1; k2=n; pd2[k1]=1;
	//	cout<<"fa "<<k1<<" "<<k2<<endl;
	}
}
int main(){
//	 srand(time(0));
//	for (int tt=1;tt<=10000;tt++){
	scanf("%d",&n); 
//	n=5;
	scanf("%s",ch+1); 
	A[0]=100; B[0]=100; A[n]=200; B[n]=200; A[n-1]=1; B[n-1]=0;
	for (int i=1;i<n;i++) if (ch[i]=='E') A[i]=0; else if (ch[i]=='W') A[i]=1; else if (ch[i]=='N') A[i]=2; else A[i]=3; 
	scanf("%s",ch+1);
	for (int i=1;i<n;i++) if (ch[i]=='E') B[i]=0; else if (ch[i]=='W') B[i]=1; else if (ch[i]=='N') B[i]=2; else B[i]=3;
	/*while ((A[n-1]^B[n-1])==1){
		for (int i=1;i<n;i++){
			A[i]=rand()%4,B[i]=rand()%4;
			while ((A[i]^A[i-1])==1) A[i]=rand()%4;
			while ((B[i]^B[i-1])==1) B[i]=rand()%4;
		}
	}
	if (solve()) printf("YES\n");
	else{
		memcpy(pd1,A,sizeof A);
		memcpy(A,B,sizeof B);
		memcpy(B,pd1,sizeof pd1);
		if (solve()) printf("YES\n"); else{
			printf("NO\n");
			for (int i=1;i<n;i++) cout<<A[i]<<" "; cout<<endl;
			for (int i=1;i<n;i++) cout<<B[i]<<" "; cout<<endl;
			while (1);
		}
	}
	}*/
	int k1=1,k2=1;
	for (int i=k1;i<n;i++)
		if (B[k2]==A[i]) k2++; else if (B[k2-1]==(A[i]^1)) k2--;
	for (int i=1;i<n;i++) A[i]^=1;
	Key[0]=1; for (int i=1;i<=n;i++) Key[i]=Key[i-1]*key;
	n--;
//	for (int i=1;i<=n;i++) cout<<A[i]<<" "<<B[i]<<endl;
	unsigned long long a=0,b=0;
	for (int i=1;i<=n-k2+1;i++){
		a=a*key+A[n-i+1]; b=b+Key[i-1]*B[n-i+1];
		if (a==b){
			printf("NO\n"); return 0;
		}
	}
	printf("YES\n");
	return 0;
}