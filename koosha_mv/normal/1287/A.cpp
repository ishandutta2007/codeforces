#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,t,k,mx,o;
string s;
int main(){
	cin>>t;
	f(q,0,t){
		k=0;mx=0;
		cin>>o>>s;
		f(i,0,s.size()){
			if(s[i]=='P'){
				k++;
				if(k!=i+1)
					mx=max(mx,k);
			}
			else
				k=0;
		}
		cout<<mx<<endl;
	}
}