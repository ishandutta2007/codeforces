#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,cnt[27];
ll t;
string s;

int main(){
	cin>>n>>t>>s;
	t-=1<<s[n-1]-'a';
	t+=1<<s[n-2]-'a';
	n-=2;
	t=-t;
	f(i,0,n){
		cnt[s[i]-'a']++;
		t+=1<<s[i]-'a';
	}
	if(t&1) return cout<<"NO",0;
	t/=2;
	f_(i,26,0)
		while(cnt[i] && (1<<i)<=t)
			cnt[i]--,t-=(1<<i);
	cout<<(t? "NO":"YES");
}