#include <bits/stdc++.h>
using namespace std; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s1,s2;
	int k=0;
	cin>>k>>s1>>s2;
	char arr[k+5];
	int sum[k+5];
	char ans[k+5];
	for(int i=0;i<k;i++)sum[i]=s2[i]+s1[i]-'a'-'a'+2;
	for(int i=0;i<k;i++){
		if(sum[i]%2==1)sum[i+1]+=26;
		sum[i]/=2;
	}
	for(int i=k-1;i>=0;i--){
		while(sum[i]>26){
			sum[i]-=26;
			sum[i-1]++;
		}
	}
	for(int i=k-1;i>=0;i--){
		ans[i]=sum[i]+'a'-1;
	}
	for(int i=0;i<k;i++)cout<<ans[i];
	cout<<endl;
}