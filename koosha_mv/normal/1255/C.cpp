#include<iostream>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
int p[100099],mark[100099],deg[100099],g[100099][6],s[100099];
int main(){
	int n,x,y,z;
	cin>>n;
	f(i,0,n-2){
		cin>>x>>y>>z;
		deg[x]++;deg[y]++;deg[z]++;
		g[x][s[x]]=y;g[x][s[x]+1]=z;s[x]+=2;
		g[y][s[y]]=x;g[y][s[y]+1]=z;s[y]+=2;
		g[z][s[z]]=x;g[z][s[z]+1]=y;s[z]+=2;
	}
	int dg1,dg2;
	f(i,1,n+1){
		if(deg[i]==1){
			dg1=i;
			break;
		}
	}
	mark[dg1]=1;
	if(deg[g[dg1][0]]==2){
		dg2=g[dg1][0];
		mark[g[dg1][0]]=1;
	}
	else{
		dg2=g[dg1][1];
		mark[g[dg1][1]]=1;
	}
	cout<<dg1<<" "<<dg2<<" ";
	p[1]=dg1;p[2]=dg2;
	f(i,3,n+1){
		f(j,0,s[p[i-2]]){
			if(mark[g[p[i-2]][j]]==0){
				mark[g[p[i-2]][j]]=1;
				cout<<g[p[i-2]][j]<<" ";
				p[i]=g[p[i-2]][j];
				break;
			}
		}
	}
}