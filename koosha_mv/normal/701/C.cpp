#include<iostream>
using namespace std;
int poke[128]={0};
int lol[140]={0};
int main(){
	int n,tma=0,tm=0,p1=0,p2=0,mn;
	string s;
	cin>>n>>s;mn=n;
	for(int i=0;i<n;i++){
		if(lol[int(s[i])]==0){tma++;lol[int(s[i])]=1;}
	}
	while(p2<=n && p1<n){
		if(tm<tma){
			if(poke[int(s[p2])]==0)
				tm++;
			poke[int(s[p2])]++;
			p2++;
		}
		else{
			mn=min(mn,p2-p1);
			if(poke[int(s[p1])]==1)
				tm--;
			poke[int(s[p1])]--;	
			p1++;
		}
	}
	cout<<mn;
}