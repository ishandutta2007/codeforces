#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,mark1[162],mark2[162],k=0,k2=0;string s1,s2;
int main(){
	cin>>n;
	f(sal,0,n){
		f(i,0,160) mark1[i]=0,mark2[i]=0;
		cin>>s1>>s2;
		if(s1.size()>s2.size()){
			cout<<"NO"<<endl;
		}
		else{
		f(i,0,s1.size()){
			mark1[s1[i]]++;
		}
		f(i,0,s1.size()){
			mark2[s2[i]]++;
		}
		k=0;k2=0;
		f(i,s1.size(),s2.size()+1){
			k=0;
			f(j,0,159){
				if(mark1[j]!=mark2[j])
					k=1;
			}
			if(k==0) k2=1;
			if(i==s2.size()) break;
			mark2[s2[i-s1.size()]]--;
			mark2[s2[i]]++;
		}
		if(k2==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		}
	}
}