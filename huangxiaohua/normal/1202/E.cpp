#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,i,j,k,it,it1,t;
string st[200500],sb;
ll a[200050],b[200500],res;
queue<int> q;
vector<int> v[200500];
struct sb{
	int mp[30],fail,len,num;
}s[200050];
void dfs(int x){
	for(auto i:v[x]){
		s[i].num+=s[x].num;dfs(i);
	}
}

void work(){
	for(int T=1;T<=t;T++){
		it=0;
		for(auto i:st[T]){
			i-='a'-1;
			if(!s[it].mp[i]){s[it].mp[i]=++it1;s[it1].len=s[it].len+1;}
			it=s[it].mp[i];
		}
		s[it].num++;
	}
	for(i=1;i<=26;i++){
		if(s[0].mp[i]){q.push(s[0].mp[i]);}
	}
	while(!q.empty()){
		k=q.front();q.pop();
		v[s[k].fail].push_back(k);
		for(i=1;i<=26;i++){
			if(s[k].mp[i]){
				s[s[k].mp[i]].fail=s[s[k].fail].mp[i];
				q.push(s[k].mp[i]);
			}
			else{
				s[k].mp[i]=s[s[k].fail].mp[i];
			}
		}
	}
	dfs(0);
}

int main(){
	ios::sync_with_stdio(0);
	cin>>sb>>t;
	for(int T=1;T<=t;T++){
		cin>>st[T];
	}
	work();
	it=j=0;
	for(auto i:sb){
		i-='a'-1;j++;
		it=s[it].mp[i];
		a[j]=s[it].num;
	}
	memset(s,0,sizeof(s));
	for(i=0;i<=it1;i++){v[i].clear();}it=it1=0;
	for(i=1;i<=t;i++){reverse(st[i].begin(),st[i].end());}
	reverse(sb.begin(),sb.end());
	work();
	it=j=0;n=sb.size();
	for(auto i:sb){
		i-='a'-1;j++;
		it=s[it].mp[i];
		b[n+1-j]=s[it].num;
	}
	for(i=1;i<=n;i++){
		res+=a[i]*b[i+1];
	}
	cout<<res;
}