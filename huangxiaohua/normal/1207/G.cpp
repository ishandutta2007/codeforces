#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,id[400500],it1,it,t,l[405000],r[405000],it2=-1,x,y,pos[400500];
ll a[405000],res[400500],tmp;
struct sb{
	int fail,mp[27],fa;
	vector<int> id;
}s[405000],s2[400500];
string st;
queue<int> q;
vector<int> v[405000],qu[400500];
void add(int x,int y){
	if(!x){return;}
	for(;x<=it2;x+=(-x&x)){a[x]+=y;}
}
ll get(int x,ll res=0){
	for(;x;x-=(-x&x)){res+=a[x];}return res;
}
void dfs0(int x){
	//printf("a%d\n",x);
	l[x]=++it2;
	for(auto i:v[x]){dfs0(i);}
	r[x]=it2;
}
void dfs(int x){
	//printf("a%d %d\n",x,it);
	add(l[it],1);
	for(auto i:s[x].id){
		for(auto j:qu[i]){
			//printf("%d %d %d %d\n",x,i,j,pos[j]);
			res[j]=get(r[pos[j]])-get(l[pos[j]]-1);
		}
	}
	for(int i=1;i<=26;i++){
		if(s[x].mp[i]){
			int tmp=it;
			it=s2[it].mp[i];
			dfs(s[x].mp[i]);
			it=tmp;
		}
	}
	add(l[it],-1);
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;
		if(k==1){it=0;}
		else{cin>>k;it=id[k];}
		cin>>st;
		for(auto j:st){
			j-='a'-1;
			if(!s[it].mp[j]){s[it].mp[j]=++it1;}
			it=s[it].mp[j];
		}
		id[i]=it;
		s[it].id.push_back(i);
	}
	
	cin>>t;it1=0;
	for(i=1;i<=t;i++){
		cin>>x>>st;
		qu[x].push_back(i);it=0;
		for(auto j:st){
			j-='a'-1;
			if(!s2[it].mp[j]){s2[it].mp[j]=++it1;s2[it1].fa=it;}
			it=s2[it].mp[j];
		}
		pos[i]=it;
		//s2[it].id.push_back(i);
	}
	for(i=1;i<=26;i++){
		if(s2[0].mp[i]){q.push(s2[0].mp[i]);}
	}
	while(!q.empty()){
		x=q.front();q.pop();
		v[s2[x].fail].push_back(x);
		for(i=1;i<=26;i++){
			if(s2[x].mp[i]){
				q.push(s2[x].mp[i]);
				s2[s2[x].mp[i]].fail=s2[s2[x].fail].mp[i];
			}
			else{
				s2[x].mp[i]=s2[s2[x].fail].mp[i];
			}
		}
	}
	dfs0(0);
	it=0;
	dfs(0);
	for(i=1;i<=t;i++){
		cout<<res[i]<<endl;
	}
}