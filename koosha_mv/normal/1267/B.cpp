#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
string s;
int sa,a[300009][2];
int main(){
	cin>>s;
	a[0][0]=1;a[0][1]=s[0];
	f(i,1,s.size()){
		if(s[i]==s[i-1]){
			a[sa][0]++;
		}
		else{
			sa++;
			a[sa][0]=1;
			a[sa][1]=s[i];
		}
	}
	sa++;
	if(sa%2==0){cout<<0;return 0;}
	f(i,0,sa){
		if(i!=(sa/2)){
			if(a[i][1]!=a[sa-i-1][1] || a[i][0]+a[sa-i-1][0]<3){cout<<0;return 0;}
		}
	}
	if(a[sa/2][0]<2){cout<<0;return 0;}
	cout<<a[sa/2][0]+1;
}