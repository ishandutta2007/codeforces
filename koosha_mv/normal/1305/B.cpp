#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=5e5+9;
ll n,t,t2,t1,g,ans,p;
string s;
int main(){
	cin>>s;
	f(i,0,s.size()){
		if(s[i]=='(')
			t++;
	}
	t2=s.size()-t;
	f(i,0,s.size()){
		if(s[i]=='('){
			t1++;
		}
		else{
			t2--;
		}
		if(t2==t1){
			ans=i;
		}
	}
	f(i,0,s.size()-1){
		if(s[i]=='(' && s[i+1]==')'){p=1;}
	}
	if(p==0){cout<<0;return 0;}
	f(i,0,ans+1){
		if(s[i]=='(') g++;
	}
	cout<<1<<endl;
	cout<<g*2<<endl;
	f(i,0,ans+1){
		if(s[i]=='(') cout<<i+1<<" ";
	}
	f(i,ans+1,s.size()){
		if(s[i]==')')
			cout<<i+1<<" ";
	}
}