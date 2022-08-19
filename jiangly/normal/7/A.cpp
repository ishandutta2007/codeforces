//Time Complexity : O(N^2)
//Space Complexity : O(N)
#include<bits/stdc++.h>
using namespace std;
const int N=8;
int main(){
	int R=0,C=0;
	for(int i=1;i<=N;++i){
		string S;
		cin>>S;
		int Cnt=0;
		for(int j=0;j<=N-1;++j){
			Cnt=Cnt+(S[j]=='B');
		}
		if(Cnt==N){
			++R;
		}else{
			C=Cnt;
		}
	}
	if(R==N){
		printf("%d\n",N);
	}else{
		printf("%d\n",R+C);
	}
	return 0;
}