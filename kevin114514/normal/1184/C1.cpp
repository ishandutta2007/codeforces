#include<bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define uniq(x) (x).erase(unique(ALL(x)),(x).end())
#define SORT(x) sort(ALL(x))
#define REV(x) reverse(ALL(x))
#define foreach(it,x) for(__typeof((x).begin()) it=(x).begin();it!=(x).end();it++)
#define debug(x) cerr<<#x<<"="<<(x)<<endl
#define gett() cerr<<"Time:"<<clock()<<"ms."<<endl
#define ri(x) scanf("%d",&x)
#define rl(x) scanf("%lld",&x)
#define rlcfpoj(x) scanf("%I64d",&x)
#define pi(x) printf("%d",x)
#define pl(x) printf("%lld",x)
#define plcfpoj(x) printf("%I64d",x)
#define lfd() printf("\n")
#define sp() printf(" ")
int n;
int x[50],y[50];
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n;
	int m=4*n+1;
	for(int i=1;i<=m;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=m;i++){
		int xmi=1e9,xma=-1e9,ymi=1e9,yma=-1e9;
		for(int j=1;j<=m;j++){
			if(i!=j){
				xmi=min(xmi,x[j]);
				xma=max(xma,x[j]);
				ymi=min(ymi,y[j]);
				yma=max(yma,y[j]);
			}
		}
		bool good=true;
		int cntu=0,cntd=0,cntl=0,cntr=0;
		for(int j=1;j<=m;j++){
			if(i!=j){
				if(x[j]!=xmi&&x[j]!=xma&&y[j]!=ymi&&y[j]!=yma){
					good=false;
					break;
				}
				if(x[j]==xmi)
					cntu++;
				if(x[j]==xma)
					cntd++;
				if(x[j]==ymi)
					cntl++;
				if(x[j]==yma)
					cntr++;
			}
		}
		if((x[i]!=xmi&&x[i]!=xma)||(y[i]!=ymi&&y[i]!=yma)){
			if(xma-xmi==yma-ymi){
				if(good){
					cout<<x[i]<<' '<<y[i]<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}