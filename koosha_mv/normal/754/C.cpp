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
#define bit(n,k) (((n)>>(k))&1)
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

const int N=111;

int n,m,t,dp[N][N],par[N][N];
string pert,name[N],a[N];
           
void Main(){
	string s;
	f(i,0,N) f(j,0,N) dp[i][j]=0;
	cin>>n;
	f(i,0,n){
		cin>>name[i];
	}
	cin>>m;
	getline(cin,pert);
	pert.clear();
	f(i,1,m+1){
		string s,t,e;
		getline(cin,e);
		f(j,0,e.size()){
			if(e[j]==':'){
				f(k,j+1,e.size()){
					t+=e[k];
				}
				break;
			}
			s+=e[j];
		}
		a[i]=t;
		f(j,0,n){
			if(s!="?" && s!=name[j]) continue ;
			int len=name[j].size(),b=0;
			f(k,0,sz(t)-len+1){
				int check=1;
				f(p,k,k+len){
					if(t[p]!=name[j][p-k]){
						check=0;
					}
				}
				if(check==1 && (k==0 || t[k-1]=='.' || t[k-1]==',' || t[k-1]=='!' || t[k-1]=='?' || t[k-1]==' ') && (k+len==t.size() || t[k+len]=='.' || t[k+len]==',' || t[k+len]=='!' || t[k+len]=='?' || t[k+len]==' ')){
					b=1;
				}
			}
			if(b==1) continue ;
			f(k,0,n){
				if(i==1 || (dp[i-1][k] && k!=j)){
					dp[i][j]=1;
					par[i][j]=k;
				}
			}
		}
	}
	f(i,0,n){
		if(dp[m][i]){
			vector<int> vec;
			int pos=i;
			f_(j,m,1){
				vec.pb(pos);
				pos=par[j][pos];
			}
			f(j,1,m+1){
				cout<<name[vec[vec.size()-j]]<<":"<<a[j]<<endl;
			}
			return ;
		}
	}
	cout<<"Impossible"<<endl;
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}
/*
1
4
netman tigerrrrr banany2001 klinchuh
4
?: tigerrrrr, banany2001, klinchuh, my favourite team ever, are you ready?
klinchuh: yes, coach!
?: yes, netman
banany2001: yes of course.
*/