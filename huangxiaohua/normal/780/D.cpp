#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it,sb[5050],match[5050],vis[5050];

unordered_map<string,int >mp,mp2;

vector<int> v[5050];
string s1[5050],s2[5050],id[5050],x,y,res[5050];

bool dfs(int u){
	if(sb[u])return 0;
    for(auto i:v[u]){
        if(!vis[i]){
            vis[i]=1;
            if(!match[i]||dfs(match[i])){
                match[i]=u;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>x>>y;
		s1[i]=x.substr(0,3);
		s2[i]=x.substr(0,2)+y[0];
		if(!mp[s1[i]]){
			mp[s1[i]]=++it;id[it]=s1[i];
		}
		if(!mp[s2[i]]){
			mp[s2[i]]=++it;id[it]=s2[i];
		}
		mp2[s1[i]]++;
		
		v[i].push_back(mp[s1[i]]);
		v[i].push_back(mp[s2[i]]);
	}
	
	for(i=1;i<=t;i++){
		if(mp2[s1[i]]>1){
			sb[i]=1;
			if(match[mp[s2[i]]]){
				cout<<"NO";return 0;
			}
			match[mp[s2[i]]]=i;
		}
	}
	
	for(i=1;i<=t;i++){
		memset(vis,0,sizeof(vis));
		if(!sb[i]&&!dfs(i)){
			cout<<"NO";return 0;
		}
	}
	for(i=1;i<=it;i++){
		res[match[i]]=id[i];
	}
	cout<<"YES\n";
	for(i=1;i<=t;i++){
		cout<<res[i]<<endl;
	}
}