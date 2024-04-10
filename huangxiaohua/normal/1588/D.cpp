#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))

int i,j,k,l,n,m,t,pos[11][66][2],rnk[11][666],nxt[11][666][66],len[11],cur[66],sb,tmp,fa[100500],dep[100500],in[100500];
string s[11];
char mp[66];

vector<int> v[100500];

void get(int id,int ch){
	int i,j;
	sb=0;
	for(i=1;i<=n;i++){
		tmp=rnk[i][ nxt[i][cur[i]][ch] ];
		
		//printf("NMSL %d %d %d\n",id,ch,tmp);
		
		if(!tmp){
			return;
		}
		if(tmp==2){
			sb|=b(i);
		}
	}
	v[id].push_back(ch*1024+sb);
	in[ch*1024+sb]++;
}

int main() {
	for(i=1;i<=26;i++)mp[i]=('a'+i-1);
	for(i=27;i<=52;i++)mp[i]=('A'+i-27);
	cin.tie(0);
	cin>>t;
	while(t--){
		for(i=0;i<=100000;i++){
			v[i].clear();
			fa[i]=dep[i]=0;
		}
		
		memset(pos,0,sizeof(pos));
		memset(rnk,0,sizeof(rnk));
		memset(nxt,0,sizeof(nxt));
		memset(dep,0,sizeof(dep));
		memset(fa,0,sizeof(fa));
		memset(in,0,sizeof(in));
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>s[i];
			j=0;
			len[i]=s[i].size();
			for(auto &k:s[i]){
				if(k>='a'&&k<='z')k-='a'-1;
				if(k>='A'&&k<='Z')k-='A'-1-26;
				
				//cout<<(int)k<<endl;
				
				j++;
				if(!pos[i][k][0]){
					pos[i][k][0]=j;
					rnk[i][j]=1;
				}
				else{
					//puts("caonima");
					pos[i][k][1]=j;
					rnk[i][j]=2;
				}
			}
			s[i]="0"+s[i];
			
			for(j=0;j<=len[i];j++){
				for(k=1;k<=52;k++){
					for(l=j+1;l<=len[i]+1;l++){
						nxt[i][j][k]=l;
						if(l>len[i]||s[i][l]==k)break;
					}
					/*if(nxt[i][j][k]<=len[i]){
						printf("NMSL%d %d %d %d\n",i,j,k,nxt[i][j][k]);
					}*/
				}
			}
		}
		
		for(i=1;i<=52;i++){
			memset(cur,0,sizeof(cur));
			for(j=0;j<b(n+1);j++){
				for(k=1;k<=n;k++){
					if(j&b(k)){
						if(!pos[k][i][1])goto aaa;
						cur[k]=pos[k][i][1];
					}
					else{
						if(!pos[k][i][0])goto aaa;
						cur[k]=pos[k][i][0];
					}
				}
				//printf("NMSL%d %d %d %d\n",i,j,cur[1],cur[2]);
				
				v[0].push_back(1024*i+j);
				in[1024*i+j]++;
				
				for(k=1;k<=52;k++){
					get(i*1024+j,k);
				}
				aaa:;
			}
		}
		
		queue<int> q;
		q.push(0);
		
		int res=0,mx=0;
		
		while(!q.empty()){
			k=q.front();q.pop();
			//printf("nmsl%d\n",k);
			dep[k]++;
			if(mx<dep[k]){
				mx=dep[k];res=k;
			}
			for(auto i:v[k]){
				in[i]--;
				if(!in[i])q.push(i);
				if(dep[i]<dep[k]){
					dep[i]=dep[k];
					fa[i]=k;
				}
			}
		}
		
		string ans;
		while(res){
			ans=mp[res/1024]+ans;
			res=fa[res];
		}
		
		cout<<ans.size()<<'\n'<<ans<<'\n';
	}
}