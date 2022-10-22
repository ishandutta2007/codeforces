#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,T,x;
string s;

void check(string m){
	string res="";
	f(i,0,n){
	    if((0<=i-x && m[i-x]=='1') || (i+x<n && m[i+x]=='1')) res+='1';
	    else res+='0';
	}
	if(res==s) cout<<m<<endl;
	else cout<<-1<<endl;
}

int main(){
	cin>>T;
	while(T--){
	    string ans="";
		cin>>s>>x;
		n=s.size();
		f(i,0,n) ans+='1';
		f(i,0,n)
		    if(s[i]=='0'){
		        if(i+x<n) ans[i+x]='0';
		        if(0<=i-x) ans[i-x]='0';
		    }
		check(ans);
	}
}