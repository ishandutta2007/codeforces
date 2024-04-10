//Time Complexity : O(N*L)
//Space Complexity : O(L)
#include<bits/stdc++.h>
using namespace std;
const int N=100,L=100;
int main(){
	int m=0,ans=0;
	string s;
	while(getline(cin,s)){
		if(s[0]=='+'){
			++m;
		}else if(s[0]=='-'){
			--m;
		}else{
			ans=ans+m*(s.length()-s.find(":")-1);
		}
	}
	printf("%d\n",ans);
	return 0;
}