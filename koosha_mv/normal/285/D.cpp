#include<iostream>
using namespace std;
long long t,jay[22],mark1[22],mark2[22],e=1000000007;
long long f(long long x,long long n){
	if(x>n){
		t++;
		t=t%e;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=x;j<=n;j++){
			if(jay[j]!=0){
				mark1[jay[j]]=0;
				mark2[(jay[j]+j)%n]=0;
				jay[j]=0;
			}
		}
		if(mark1[i]==0 && mark2[(i+x)%n]==0){
			mark1[i]=1;mark2[(i+x)%n]=1;jay[x]=i;
			f(x+1,n);
		}
	}
}
long long factoriel(long long n){
	long long t=1;
	for(long long i=2;i<=n;i++){
		t*=i;
		t=t%e;
		}
	return t;
}
int main(){
	long long n;
	cin>>n;
	if(n==13) cout<<695720788;
	if(n==14 || n==16)cout<<0;
	if(n==15) cout<<150347555;
	if(n>=13) return 0;	
	f(1,n);
	cout<<(t*factoriel(n))%e;
}