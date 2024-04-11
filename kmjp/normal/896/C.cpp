#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
ll V;
ll seed;
ll A[101010];
int T[101010],L[101010],R[101010],X[101010],Y[101010];
ll mo;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll rnd() {
	ll ret=seed;
	seed=(seed*7+13)%1000000007;
	return ret;
}
set<pair<int,ll>> S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>seed>>V;
	S.insert({0,0});
	S.insert({N+1,0});
	FOR(i,N) {
		x=rnd()%V+1;
		S.insert({i+1,x});
	}
	FOR(i,M) {
		T[i]=rnd()%4;
		L[i]=rnd()%N+1;
		R[i]=rnd()%N+1;
		if(L[i]>R[i]) swap(L[i],R[i]);
		
		if(T[i]==2) X[i]=rnd()%(R[i]-L[i]+1)+1;
		else X[i]=rnd()%V+1;
		
		if(T[i]==3) mo=rnd()%V+1;
		//cout<<"!"<<T[i]<<" "<<L[i]<<" "<<R[i]<<" "<<X[i]<<" "<<mo<<endl;
		if(T[i]==0 || T[i]==1) {
			while(L[i]<=R[i]) {
				auto it=S.lower_bound({L[i],0});
				auto cur=*it;
				auto pre=*--it;
				
				if(pre.first!=L[i]-1) {
					S.insert({L[i]-1,cur.second});
				}
				if(R[i]<cur.first) {
					if(T[i]==0) {
						S.insert({R[i],cur.second+X[i]});
					}
					else {
						S.insert({R[i],X[i]});
					}
				}
				else {
					S.erase(cur);
					if(T[i]==0) {
						S.insert({cur.first,cur.second+X[i]});
					}
					else {
						S.insert({cur.first,X[i]});
					}
				}
				L[i]=cur.first+1;
			}
			while(1) {
				auto it=S.lower_bound({R[i],0});
				ll cur=it->second;
				it--;
				if(it->first==0 || it->second != cur) break;
				S.erase(it);
			}
			while(1) {
				auto it=S.lower_bound({R[i],0});
				ll cur=it->second;
				it++;
				if(it->first==N+1 || it->second != cur) break;
				S.erase(--it);
			}
			
		}
		else if(T[i]==2 || T[i]==3) {
			vector<pair<ll,int>> V;
			auto it=S.lower_bound({L[i],0});
			while(L[i]<=R[i]) {
				V.push_back({it->second,min(R[i],it->first)-L[i]+1});
				L[i]=it->first+1;
				it++;
			}
			sort(ALL(V));
			ll ret=0;
			FORR(v,V) {
				if(T[i]==2) {
					if(X[i]>0 && X[i]<=v.second) ret=v.first;
					X[i]-=v.second;
				}
				else {
					//cout<<"add"<<v.second<<"*"<<v.first<<"^"<<X[i]<<endl;
					(ret+=v.second*modpow(v.first%mo,X[i]))%=mo;
				}
			}
			cout<<ret<<endl;
			
		}
		//FORR(r,S) cout<<r.first<<":"<<r.second<<"      ";
		//cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}