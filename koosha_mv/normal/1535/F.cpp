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
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99,E=1337,Z=27,base=31,R=2,sq=7000;

int n,m,cnt[Z],nxt[N],mod[R],hash1[R],hash2[R],pr[sq][sq],su[sq][sq];
ll ex,ans;
string s[N],t[N];
map<vector<int>,vector<int> > Map;
map<pair<pair<int,int>,pair<int,int> >,int> mark;

void mxp(vector<int> v,int x,int type){
	vector<vector<int> > S(Z);
	f(i,0,v.size())
		S[t[v[i]][x]-'a'].pb(v[i]);
	f(i,0,Z){
		if(S[i].size()){
			f(j,0,i)
				f(ai,0,S[i].size())
					f(aj,0,S[j].size()){
						if(type==0)
							pr[S[i][ai]][S[j][aj]]=pr[S[j][aj]][S[i][ai]]=x;
						else
							su[S[i][ai]][S[j][aj]]=su[S[j][aj]][S[i][ai]]=x;
					}
		}
	}
	f(i,0,Z)
		if(S[i].size()>1)
			mxp(S[i],x+(type==0 ? +1 : -1),type);
}
int calc1(int x,int y){
   int l=0,r=m;
   while(l<m && t[x][l]==t[y][l]) l++;
   while(r && t[x][r-1]==t[y][r-1]) r--;
   int okx=1,oky=1;
   f(i,l,r-1){
      if(t[x][i]>t[x][i+1])
         okx=0;
      if(t[y][i]>t[y][i+1])
         oky=0;
   }
   if(okx || oky){return 1; }
   return 2;
}
void G1(int x){
   f(i,0,R)
      hash1[i]=0;
   nxt[m-1]=m;
   f_(i,m-2,0){
      nxt[i]=i+1;
      if(t[x][i]<=t[x][i+1])
         nxt[i]=nxt[i+1];
   }
   f(i,0,m-1){
      f(r,0,R)
         hash2[r]=0;
      f_(j,m-1,i+1){
         if(nxt[i]>j){
            mark[mp(mp(hash1[0],hash1[1]),mp(hash2[0],hash2[1]))]++;
         }
         f(r,0,R)
            hash2[r]=(1ll*hash2[r]*base+t[x][j]-'a'+1)%mod[r];
      }
      f(r,0,R)
         hash1[r]=(1ll*hash1[r]*base+t[x][i]-'a'+1)%mod[r];
   }
}
void G2(int x){
   f(i,0,R)
      hash1[i]=0;
   f(i,0,m-1){
      fill(cnt,cnt+Z,0);
      f(r,0,R)
         hash2[r]=0;
      f(j,i,m)
         cnt[t[x][j]-'a']++;
      f_(j,m-1,i+1){
         int mn=Z,mx=0;
         f(k,0,Z)
           	if(cnt[k]){
             	maxm(mx,k);
             	minm(mn,k);
            }
         if(t[x][i]-'a'!=mn && t[x][j]-'a'!=mx){
            ans-=mark[mp(mp(hash1[0],hash1[1]),mp(hash2[0],hash2[1]))];
         }
         cnt[t[x][j]-'a']--;
         f(r,0,R)
            hash2[r]=(1ll*hash2[r]*base+t[x][j]-'a'+1)%mod[r];
      }
      f(r,0,R)
         hash1[r]=(1ll*hash1[r]*base+t[x][i]-'a'+1)%mod[r];
   }
}
void solve(vector<int> v){
   int w=v.size();
   mark.clear();
   ex+=1ll*v.size()*(n-v.size())*E;
   f(i,0,v.size())
      t[i]=s[v[i]];
   if(n<sq){
      vector<vector<int> > nxt(w);
   	vector<int> v;
      f(i,0,w)
      	v.pb(i);
      mxp(v,0,0);
      mxp(v,m-1,1);
   //   f(i,0,w)
    //     f(j,0,i)
  //          cout<<j<<" "<<i<<" : "<<pr[i][j]<<" "<<su[i][j]<<endl;
      f(i,0,w){
         nxt[i].pb(0);
         f(j,1,m){
            if(t[i][j]>=t[i][j-1])
               nxt[i].pb(nxt[i][j-1]);
            else
               nxt[i].pb(j);
         }
      }
      f(i,0,w)
         f(j,0,i){
            ans+=1;
            if(!(nxt[i][su[i][j]]<=pr[i][j] || nxt[j][su[i][j]]<=pr[i][j])){
               ans+=1;
            }
         }
   }
   else{
      ans+=1ll*v.size()*(v.size()-1);
      f(i,0,w)
         G1(i);
      //cout<<endl;
      f(i,0,w)
         G2(i);
   }
}

int main(){
   mod[0]=998244353,mod[1]=1e9+9;
   cin>>n;
   f(i,0,n){
      vector<int> v(Z);
      cin>>s[i];
      m=s[i].size();
      f(j,0,s[i].size())
         v[s[i][j]-'a']++;
      Map[v].pb(i);
   }
   for(auto v : Map)
      solve(v.S);
   cout<<ans+ex/2<<endl;
}