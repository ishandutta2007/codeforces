#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,int> pli;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=500010;
int i,j,k,n,m,T;
int fa[maxn][2],size[maxn][2],con[maxn][2];
int cl[maxn];
vector<pli>V[maxn];
int find(int x,int id){
	//cout<<"FIND "<<x<<' '<<id<<' '<<(fa[x][id]==x?x:find(fa[x][id],id))<<endl;
	return fa[x][id]==x?x:find(fa[x][id],id);
}
int main(){
	cin>>n>>m;
	for(i=1;i<maxn;i++)fa[i][0]=fa[i][1]=i,size[i][0]=size[i][1]=1,con[i][0]=con[i][1]=0;
	for(i=1;i<=m;i++){
		//cout<<"i="<<i<<endl;
		string S;
		cin>>S;
		if(S=="U"){
			int x=read(),y=read();
			int X=find(x,0),Y=find(y,0);
			if(size[X][0]>size[Y][0])swap(X,Y);
			fa[X][0]=Y;size[Y][0]+=size[X][0];
			con[X][0]=i;
		}
		if(S=="M"){
			int x=read(),y=read();
			int X=find(x,1),Y=find(y,1);
			if(size[X][1]>size[Y][1])swap(X,Y);
			fa[X][1]=Y;size[Y][1]+=size[X][1];
			con[X][1]=i;
		}
		if(S=="A"){
			int x=read(),X=find(x,0);
			ll w=0;
			if(V[X].size())w=V[X][V[X].size()-1].first;
			V[X].push_back(make_pair((long long)(w+size[X][0]),i));
		}
		if(S=="Z"){
			int x=read(),X=find(x,1);
			//cout<<"X="<<X<<endl;
			cl[X]=i;
		}
		if(S=="Q"){
			int x=read(),now=x,X0=find(x,0),X1=find(x,1),timecl=-1,Maxt=-1;
			int last=-1e9;
			ll ans=0;
			while(1){
	//			cout<<"now="<<now<<" cl="<<cl[now]<<" MAXT="<<Maxt<<endl;
				if(cl[now]>Maxt)timecl=max(timecl,cl[now]);
				Maxt=max(Maxt,con[now][1]);
				if(now==fa[now][1])break;
				now=fa[now][1];
			}
	//		cout<<"timecl="<<timecl<<endl;
			now=x;
			while(1){
				int L=0,R=V[now].size()-1;
	//			cout<<"TIME:"<<timecl<<' '<<last<<endl;
				while(L<=R){
					int Mid=(L+R)>>1;
					int x=V[now][Mid].second;
	//				cout<<Mid<<' '<<x<<endl;
					if(x<=max(timecl,last))L=Mid+1;
					else R=Mid-1;
				}
				last=con[now][0];
	//			cout<<"L-1="<<L-1<<endl;
	//			for(int j=0;j<V[now].size();j++)cout<<' '<<V[now][j].first<<' '<<V[now][j].second<<endl;
				if(V[now].size())ans+=V[now][V[now].size()-1].first;
				if(L>0)ans-=V[now][L-1].first;
				if(now==fa[now][0])break;
				now=fa[now][0];
			}
			printf("%lld\n",ans);
		}
	}
}