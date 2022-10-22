#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
int dp1[1002],dp2[1002],tyal,ejtema2[1001][1001],ejtemakol2[2001],markk2[2002],barg2[1002],ejtema1[1002][1002],ejtemakol1[2002],markk1[2002],barg1[1002],x,p,n1,n2,deg1[2002],mark1[2002],edge1[2002][2002],deg2[2002],mark2[2009],edge2[2002][2002];
vector <int> g1[2002],masir1[2002],g2[2002],masir2[2002];
vector <int> l;
int dfs1(int x,vector <int> v1){
	vector <int> u;mark1[x]=1;
	f(i,0,g1[x].size()){
		if(mark1[g1[x][i]]==0){
			u=v1;
			u.push_back(edge1[g1[x][i]][x]);
			dfs1(g1[x][i],u);}
	}
	if(deg1[x]==1) masir1[x]=v1;
}
int dfs2(int x,vector <int> v1){
	vector <int> u;mark2[x]=1;
	f(i,0,g2[x].size()){
		if(mark2[g2[x][i]]==0){
			u=v1;
			u.push_back(edge2[g2[x][i]][x]);
			dfs2(g2[x][i],u);
		}
	}
	if(deg2[x]==1) masir2[x]=v1;
}
int main(){
	cin>>p>>n1;
	deg1[0]=1;
	f(i,1,n1){
		cin>>x;
		deg1[i+1]++,deg1[x]++;
		g1[x].push_back(i+1);
		g1[i+1].push_back(x);
		edge1[i+1][x]=i;
		edge1[x][i+1]=i;}
	f(i,1,p+1) cin>>barg1[i];
	cin>>n2;
	f(i,1,n2){
		cin>>x;deg2[i+1]++,deg2[x]++;
		g2[x].push_back(i+1);
		g2[i+1].push_back(x);
		edge2[i+1][x]=i,edge2[x][i+1]=i;}
	f(i,1,p+1) cin>>barg2[i];
	dfs2(1,l);dfs1(1,l);
	f(i,1,n1){
		f(j,0,masir1[barg1[i]].size()){
			ejtemakol1[masir1[barg1[i]][j]]++;
		}
	}
	f(i,1,n2){
		f(j,0,masir2[barg2[i]].size()){
			ejtemakol2[masir2[barg2[i]][j]]++;
		}
	}
	f(i,1,p+1){
		f(j,1,n1) markk1[j]=ejtemakol1[j];
		tyal=0;
		f(j1,i,p+1){
			f(k,0,masir1[barg1[j1]].size()){
				markk1[masir1[barg1[j1]][k]]--;
				if(markk1[masir1[barg1[j1]][k]]==0) tyal++;}
			ejtema1[i][j1]=tyal;
			//cout<<i<<" & "<<j1<<" : "<<ejtema1[i][j1]<<endl;
		}
	}
	f(i,1,p+1){
		f(j,1,n2) markk2[j]=ejtemakol2[j];
		tyal=0;
		f(j1,i,p+1){
			f(k,0,masir2[barg2[j1]].size()){
				markk2[masir2[barg2[j1]][k]]--;
				if(markk2[masir2[barg2[j1]][k]]==0) tyal++;}
			ejtema2[i][j1]=tyal;}
	}
	f(i,1,p+1){
		f(j,1,i+1){
			dp1[i]=max(dp1[i],dp2[j-1]+ejtema1[j][i]);
			dp2[i]=max(dp2[i],dp1[j-1]+ejtema2[j][i]);
		}
	}
	cout<<max(dp1[p],dp2[p]);
}