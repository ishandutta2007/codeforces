#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
int mx,a1[200009],a2[200009],p1,p2;
int main(){
	string t,s;
	cin>>t>>s;p2=s.size()-1;
	f(i,0,t.size()){
		if(p1<s.size() && t[i]==s[p1]) p1++;
		a1[i+1]=p1;}
	f_(i,t.size()-1,0){
		if(p2>=0 && s[p2]==t[i]) p2--;
		a2[i+1]=p2+1;}
	a2[t.size()+1]=s.size();
	p1=0,p2=0;
	while(p2<=t.size()){
		if(a1[p1]>=a2[p2+1]){
			p2++;
			mx=max(mx,p2-p1-1);}
		else p1++;
			
	}
	cout<<mx;
}