#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,t,a[N],mark[N];
string s;

void Main(){
	int ans=N;
	cin>>n>>s;	
	f(i,0,n){
		f(j,i,min(i+20,n)){
			mark[s[j]-'a']++;
			if(mark[0]>mark[1] && mark[0]>mark[2] && i<j){
				minm(ans,j-i+1);
			}
		}
		mark[0]=mark[1]=mark[2]=0;
	}
	if(ans==N) cout<<-1<<endl;
	else cout<<ans<<endl;
}

int main(){
	cin>>t;
	while(t--){
		Main();
	}
}