#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
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
#define int ll

const int N=1e6+99,S=29;

int n,q,m,a[N],cnt[N];
string s,t;

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>q;
	while(q--){
		cin>>s>>t;
		n=s.size(),m=t.size();
		int p=0;
		f(i,0,S) cnt[i]=0;
		f(i,0,n) cnt[s[i]-'a']++;
		string ans;
		if(t=="abc"){
			if(!cnt[0]){
				while(cnt[0]--) cout<<'a';
			while(cnt[1]--){
				cout<<'b';
			}
			while(cnt[2]--){
				cout<<'c';
			}
			f(i,3,S){
				while(cnt[i]--){
					cout<<char('a'+i);
				}
			}
			}
			else{
				while(cnt[0]--) cout<<'a';
				while(cnt[2]--){
					cout<<'c';
				}
				while(cnt[1]--){
					cout<<'b';
				}
				f(i,3,S){
					while(cnt[i]--){
						cout<<char('a'+i);
					}
				}
			}
		}
		else{
			while(cnt[0]--) cout<<'a';
			while(cnt[1]--){
				cout<<'b';
			}
			while(cnt[2]--){
				cout<<'c';
			}
			f(i,3,S){
				while(cnt[i]--){
					cout<<char('a'+i);
				}
			}
		}
		cout<<endl;
	}
}