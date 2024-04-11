#include<iostream>
using namespace std;
int dp0[100009],dp1[100009],dp2[100009],mx;
int main(){
	string s1,s2,s;cin>>s1>>s2;
	s=s1[0];s+=s2[0];
	for(int i=1;i<s1.size();i++){
		dp0[i]=max(max(dp0[i-1],dp1[i-1]),dp2[i-1]);
		if(s1[i]=='0' && s2[i]=='0'){
			if(s[0]=='0' || s[1]=='0'){
				dp2[i]=max(max(dp0[i-2],dp1[i-2]),dp2[i-2])+1;
			}
			if(s[0]=='0' && s[1]=='0'){
				dp2[i]=max(dp2[i],dp1[i-1]+1);
			}
		}
		if(s1[i]=='0' || s2[i]=='0'){
			if(s[0]=='0' && s[1]=='0')
				dp1[i]=max(max(dp1[i-2],dp2[i-2]),dp0[i-2])+1;
		}
		//cout<<dp0[i]<<" "<<dp1[i]<<" "<<dp2[i]<<endl;
		mx=max(max(max(mx,dp1[i]),dp2[i]),dp0[i]);
		s=s1[i];s+=s2[i];
	}
	cout<<mx;
}