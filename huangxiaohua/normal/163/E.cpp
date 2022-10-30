#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,id[100500],it1,it,t,l[1005000],r[1005000],it2=-1,x,y,b[100500];
ll a[1005000],res;
struct sb{
	int fail,mp[27];
}s[1005000];
string st;
queue<int> q;
vector<int> v[1005000];
void dfs0(int x){
	l[x]=++it2;
	for(auto i:v[x]){dfs0(i);}
	r[x]=it2;
}
void add(int x,int y){
	if(!x){return;}
	for(;x<=it2;x+=(-x&x)){a[x]+=y;}
}
ll get(int x,ll res=0){
	for(;x;x-=(-x&x)){res+=a[x];}return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t>>n;
	for(i=1;i<=n;i++){
		cin>>st;it=0;
		for(auto j:st){
			j-='a'-1;
			if(!s[it].mp[j]){s[it].mp[j]=++it1;}
			it=s[it].mp[j];
		}
		id[i]=it;
	}
	for(i=1;i<=26;i++){
		if(s[0].mp[i]){q.push(s[0].mp[i]);}
	}
	while(!q.empty()){
		x=q.front();q.pop();
		v[s[x].fail].push_back(x);
		for(i=1;i<=26;i++){
			if(s[x].mp[i]){
				q.push(s[x].mp[i]);
				s[s[x].mp[i]].fail=s[s[x].fail].mp[i];
			}
			else{
				s[x].mp[i]=s[s[x].fail].mp[i];
			}
		}
	}
	dfs0(0);
	for(i=1;i<=n;i++){
		add(l[id[i]],1);add(r[id[i]]+1,-1);b[i]++;
	}
	while(t--){
		cin>>st;
		if(st[0]!='?'){
			int nmsl=stoi(st.substr(1));
			it=id[nmsl];
			if(st[0]=='+'){
				if(b[nmsl]){continue;}b[nmsl]++;
				add(l[it],1);add(r[it]+1,-1);
			}
			else{
				if(!b[nmsl]){continue;}b[nmsl]--;
				add(l[it],-1);add(r[it]+1,1);
			}
		}
		else{
			it=0;res=0;
			for(auto i:st){
				if(i=='?'){continue;}
				i-='a'-1;
				it=s[it].mp[i];
				res+=get(l[it]);
			}
			cout<<res<<endl;
		}
	}
}