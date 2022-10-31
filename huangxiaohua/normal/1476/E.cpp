#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<string,int> mp;

int i,j,k,n,t,id[100500],m,yes,son[100500];

vector<int> ve[100500],v,ans;
string sb[100500],s[100500];

void ad(string b,int x){
	if(mp[b]){mp[b]=-1;}
	else{mp[b]=id[x];}
}

void chk(int x){
	int i,ii,iii,iiii,q=1145141919;
	string tmp;
	v.clear();
	tmp=s[x];
	if(mp[tmp]){v.push_back(mp[tmp]);}
	
	if(k>=1){
		for(i=1;i<=k;i++){
			tmp=s[x];
			tmp[i-1]='_';
			if(mp[tmp]){v.push_back(mp[tmp]);}
		}
	}
	
	if(k>=2){
		for(i=1;i<=k;i++){
			for(ii=i+1;ii<=k;ii++){
				tmp=s[x];
				tmp[i-1]=tmp[ii-1]='_';
				if(mp[tmp]){v.push_back(mp[tmp]);}
			}
		}
	}
	
	if(k>=3){
		for(i=1;i<=k;i++){
			for(ii=i+1;ii<=k;ii++){
				for(iii=ii+1;iii<=k;iii++){
					tmp=s[x];
					tmp[i-1]=tmp[ii-1]=tmp[iii-1]='_';
					if(mp[tmp]){v.push_back(mp[tmp]);}
				}
			}
		}
	}
	
	if(k==4){
		if(mp["____"]){v.push_back(mp["____"]);}
	}
	
	//cout<<s[x]<<endl;
	
	yes=0;
	for(auto i:v){
		//printf("%d ",i);puts("");
		if(i==id[x]){yes=1;continue;}
		ve[id[x]].push_back(i);son[i]++;
	}
}

queue<int> q;
bool used[105000];

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++){
		cin>>sb[i];
		mp[sb[i]]=i;
	}
	for(i=1;i<=m;i++){
		cin>>s[i]>>id[i];
	}
	for(i=1;i<=m;i++){
		chk(i);
		if(!yes){cout<<"NO"<<endl;return 0;}
	}
	
	for(i=1;i<=n;i++){
		if(!son[i]){q.push(i);used[i]=1;}
	}
	while(!q.empty()){
		k=q.front();q.pop();
		ans.push_back(k);
		for(auto i:ve[k]){
			if(used[i]){continue;}
			son[i]--;
			if(!son[i]){q.push(i);used[i]=1;}
		}
	}
	if(ans.size()!=n){cout<<"NO"<<endl;return 0;}
	cout<<"YES"<<endl;
	for(auto i:ans){
		cout<<i<<" ";
	}
}