#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int dp[101];
int main(){
	int x;dp[1]=1;dp[2]=0;cin>>x;
	f(i,1,50){dp[i*2+1]=dp[i*2-1]+((i*2))*2;}
	f(i,1,101){
		if(dp[i]>=x){
			if(i%2==1){
				if(i>3){cout<<i;break;}
				if(i==1){cout<<i;break;}
				if(i==3 && x!=3){cout<<i;break;}
			}
		}
	}
}