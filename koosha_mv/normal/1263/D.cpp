#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
string s;
int n;
int ans,mn,mark2[28],mark[28],mark3[27],mark4[29],s1=0,ko=0;
int main(){
	f(i,0,28) mark[i]=28;
	cin>>n;
	f(l,0,n){
		cin>>s;
		mn=28;
		f(j,0,28) {mark2[j]=0;mark3[min(j,26)]=0;}
		f(i,0,s.size()){
			mn=min(mn,mark[s[i]-'a']);
			mark2[s[i]-'a']=1;
			if(mark[s[i]-'a']!=28){mark3[mark[s[i]-'a']]=1;}
		}
	//	f(i,0,28)
	//		cout<<mark2[i]<<" ";
		if(mn==28){
		mn=ko;
		ko++;
		}
		f(i,0,28){
			if((mark2[i]==1) || (mark[i]!=28 && mark3[mark[i]]==1 && 0==2)){
				mark[i]=mn;	
			}
		}
	}
	//f(i,0,28)
	//	cout<<mark[i]<<" ";
	//cout<<endl;
	f(i,0,28){
		if(mark[i]!=28){mark4[mark[i]]=1;}
	}
	cout<<endl;
	f(i,0,27){
		if(mark4[i]==1){ans++;}
	}
	cout<<ans;
}