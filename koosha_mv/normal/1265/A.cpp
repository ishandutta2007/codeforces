#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int t,l=0;
string s;
int main(){
	cin>>t;
	f(i,0,t){
		cin>>s;l=0;
		f(i,0,s.size()-1){
			if(s[i]==s[i+1] && s[i]!='?'){
				l=1;
			}
		}
		f(i,0,s.size()){
			if(s[i]=='?'){
				if(i>=0){
					if((i==0 || s[i-1]!='a' )&& s[i+1]!='a' )
						s[i]='a';
					else{
						if((i==0 || s[i-1]!='b') && s[i+1]!='b' )
							s[i]='b';
						else 
							s[i]='c';
					}
				}
			}
		}
		if(l==0)cout<<s<<endl;
		else cout<<-1<<endl;
	}
}