//Time Complexity : O(N^2)
//Space Complexity : O(N^2)
#include<bits/stdc++.h>
using namespace std;
map<string,int>Type;
int Check(string S){
	int n=S.length();
	int Pos=-1,Cnt=0;
	for(int i=n-1;i>=0;--i){
		switch(S[i]){
			case '(':
				++Cnt;
				break;
			case ')':
				--Cnt;
				break;
			case '*':
			case '/':
				if(!Cnt&&Pos==-1){
					Pos=i;
				}
				break;
			case '+':
			case '-':
				if(!Cnt){
					int Ans1=Check(S.substr(0,i)),Ans2=Check(S.substr(i+1,n-i-1));
					if(Ans1==1||Ans2==1||S[i]=='-'&&Ans2==2){
						return 1;
					}else{
						return 2;
					}
				}
				break;
		}
	}
	if(~Pos){
		int Ans1=Check(S.substr(0,Pos)),Ans2=Check(S.substr(Pos+1,n-Pos-1));
		if(Ans1==1||Ans2==1||Ans1==2||Ans2==2||S[Pos]=='/'&&Ans2==3){
			return 1;
		}else{
			return 3;
		}
	}else if(S[0]=='('){
		int Ans=Check(S.substr(1,n-2));
		if(Ans==1){
			return 1;
		}else{
			return 0;
		}
	}else{
		return Type[S];
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n-1;++i){
		string D,S0,S;
		int Rest=7;
		while(Rest){
			cin>>D;
			Rest=Rest-D.length();
		}
		cin>>D;
		getline(cin,S0);
		int l=S0.length();
		for(int j=0;j<=l-1;++j){
			if(!isspace(S0[j])){
				S+=S0[j];
			}
		}
		Type[D]=Check(S);
	}
	string S0,S;
	getline(cin,S0);
	int l=S0.length();
	for(int i=0;i<=l-1;++i){
		if(!isspace(S0[i])){
			S+=S0[i];
		}
	}
	int Ans=Check(S);
	if(Ans==1){
		puts("Suspicious");
	}else{
		puts("OK");
	}
	return 0;
}