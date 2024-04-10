//Time Complexity : O(N*log(N)*L)
//Space Complexity : O(N*log(N)*L)
#include<bits/stdc++.h>
using namespace std;
const int N=100000,L=32;
int main(){
	int n;
	map<string,int>cnt;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		string s;
		cin>>s;
		if(cnt.count(s)){
			cout<<s;
			printf("%d\n",cnt[s]++);
		}else{
			puts("OK");
			cnt[s]=1;
		}
	}
	return 0;
}