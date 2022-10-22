#include<iostream>
using namespace std;
long long  t=1,dp[100009],a[100009],sa=0,mx=0,e=1000000007;
int  main(){
	string s;
	long long  k=0;
	cin>>s;dp[1]=1;dp[2]=2;
	for(long long  i=3;i<100009;i++){
		dp[i]=(dp[i-1]+dp[i-2])%e;
	}
	for(long long  i=0;i<s.size();i++){
		if(s[i]=='w' || s[i]=='m'){
			cout<<0;
			return 0;}
		if(s[i]=='n' || (s[i]=='u')){
			if(i==0)
				k=1;
			else{
			if(s[i]=='n'){
				if(s[i-1]=='n')
					k++;
				else{
					if(s[i-1]=='u'){
						t*=dp[k];
						t=t%e;
					}
					k=1;
					}
			}
			else{
				if(s[i-1]=='u')
					k++;
				else{
					if(s[i-1]=='n')
						t*=dp[k];
					t=t%e;
					k=1;
				}
			}
			}
		}
		else{
			if(k>0){
				//cout<<k<<endl;
				t*=dp[k];
				t=t%e;
				k=0;
			}
		}
	}
	if(k>0)
		t*=dp[k];
	t=t%e;
	cout<<t;
}