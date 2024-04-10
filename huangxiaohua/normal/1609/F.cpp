#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
vector<tuple<int,int,int,int> > mx[66],mn[66];
ll a[1005000],res;
int s1[1005000],s2[1005000],it1,it2;
#define cnt(x) __builtin_popcountll(x)

struct _BIT{
	int N;
	int C[1005000],C2[1005000];
	void init(int n){
		N=n;
		memset(C,0,sizeof(C));
		memset(C2,0,sizeof(C2));
	}
	void add(int pos,int val){
		for(int i=pos;i<=N;i+=(-i&i)) C[i]+=val,C2[i]+=val*pos;
	}
	void add(int l,int r,int x){
		add(l,x);add(r+1,-x);
    }
    int ask(int pos){
		int ret=0;
		for(int i=pos;i>0;i-=(-i&i)) ret+=(pos+1)*C[i]-C2[i];
		return ret;
	}
    int ask(int l,int r){
        return ask(r)-ask(l-1);
    }
}f1,f2;

void chk(int t){
	int i,j,k,i1=0,i2=0,n1=mx[t].size(),n2=mn[t].size(),cur=0;
	if(!n1||!n2)return;
	f1.init(n);f2.init(n);
	sort(mx[t].begin(),mx[t].end());
	sort(mn[t].begin(),mn[t].end());
	for(i=1;i<=n;i++){
		while(i1<n1){
			if(get<0>(mx[t][i1])==i){
				auto [x,l,r,ty]=mx[t][i1];i1++;
				cur+=f2.ask(l,r)*ty;
				f1.add(l,r,ty);
			}
			else break;
		}
		while(i2<n2){
			if(get<0>(mn[t][i2])==i){
				auto [x,l,r,ty]=mn[t][i2];i2++;
				cur+=f1.ask(l,r)*ty;
				f2.add(l,r,ty);
			}
			else break;
		}
		res+=cur;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n+1;i++){
		if(i<=n)cin>>a[i];
		while(it1&&(a[i]<=a[s1[it1]]||i>n)){
			t=s1[it1];
			mn[cnt(a[t])].push_back({s1[it1-1]+1,t,i-1,1});
			mn[cnt(a[t])].push_back({t+1,t,i-1,-1});
			it1--;
		}
		while(it2&&(a[i]>=a[s2[it2]]||i>n)){
			t=s2[it2];
			mx[cnt(a[t])].push_back({s2[it2-1]+1,t,i-1,1});
			mx[cnt(a[t])].push_back({t+1,t,i-1,-1});
			it2--;
		}
		s1[++it1]=i;s2[++it2]=i;
	}
	for(t=0;t<=60;t++)chk(t);
	cout<<res;
}