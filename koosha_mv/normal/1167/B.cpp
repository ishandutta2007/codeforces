#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int a[6]={4 , 8, 15, 16, 23, 42 };

int n,t,p,j[6],ans[6],mark[6];

void ask(int x,int y){
	cout<<"? "<<x<<" "<<y<<endl;
	cin>>p;
}
int main(){
	f(i,0,6) j[i]=5;
	f(i,1,5){
		ask(i,i+1);
		f(j1,0,6){
			f(j2,0,j1)
				if(a[j1]*a[j2]==p){
				//	cout<<a[j1]<<" "<<a[j2]<<endl;
					mark[j1]++,mark[j2]++;
					j[j1]=i-1,j[j2]=i-1;
					if(i==4){
						if(mark[j1]==2) j[j2]=i;
						else j[j1]=i;
					}
				}
		}
	}
	f(i,0,6){
		ans[j[i]]=a[i];
	}
	cout<<"! ";
	print(ans,6);
}