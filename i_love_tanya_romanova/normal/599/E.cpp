/*
Riders of the Nile race towards the light
Swiftly moves the golden lion

South's an eon watching, waiting to be whole
Never will the roacher tire
Winds of poisonous whispers brought to break them all
Racing riders of the Nile

Sapless seasons ending, the end of all grey
Graves and huddled in the fire
No one lingers long as fire comes their way
Racing riders of the Nile

Down the Nile, like them down the Nile

North a storm has wakened. Angry as it breathes
Molten lines are to expire
Cosmos holds the reason, cosmos holds the key
Racing riders of the Nile

Down the Nile, like them down the Nile

Riders of the Nile race towards the light
Swiftly moves the golden lion

Down the Nile, like them down the Nile
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>  
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 200000;

using namespace std;

int n,m,q,a,b;
int L[100][100];
vector<int> known[100];
long long dp[1<<14][14];
int at[100];
int have_edge[50][50];

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
//	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>m>>q;
	
	int H=0;
	
	for (int i=1;i<=m;i++)
	{
		cin>>a>>b;
		--a;
		--b;
		known[a].push_back(b);
		known[b].push_back(a);
		have_edge[a][b]=have_edge[b][a]=1;
		if (a==b)
			H=1;
	}
	
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			L[i][j]=-1;
	
	for (int i=1;i<=q;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		--a;
		--b;
		--c;
		if (a==b&&c!=a)
			H=1;
		
		if (L[a][b]!=-1&&L[a][b]!=c)
			H=1;
			
		L[a][b]=L[b][a]=c;
	}
	
	for (int mask=1;mask<(1<<n);mask++)
		for (int root=0;root<n;root++)
		{
			if (!(mask&(1<<root)))
				continue;
			if (mask==(1<<root))
			{
				dp[mask][root]=1;
				continue;
			}
			
			int Q=0;
			while (Q==root||(!(mask&(1<<Q))))
				++Q;
			
			int s=mask;
			s=(s-1);
			s&=mask;
			
			while (s>0)
			{
				int Q2=0;
				while (!(s&(1<<Q2)))
					++Q2;
				
				if (Q2!=Q)
				{
					s=((s-1)&mask);
					continue;
				}
				
			//	cout<<"#"<<mask<<" "<<root<<" "<<s<<" "<<Q<<" "<<Q2<<endl;
				for (int i=0;i<n;i++)
				{
					if (!(mask&(1<<i)))
						at[i]=0;
					else if(s&(1<<i))
						at[i]=1;
					else
						at[i]=2;
				}
				bool bad=0;
				
				
				for (int i=0;i<n;i++)// bad LCA, mEdge
					for (int j=i+1;j<n;j++)
					{
						if (at[i]>0&&at[j]>0&&at[i]!=at[j]&&L[i][j]!=-1&&L[i][j]!=root)
						{
							bad=1;
							break;
						}
						if (at[i]>0&&at[j]>0&&(i!=root&&j!=root)&&have_edge[i][j]&&at[i]!=at[j])
						{
							bad=1;
							break;
						}
					}
				
				if ((1<<root)&s)
					bad=1;
				
				int S=-1;
				for (int i=0;i<known[root].size();i++)
				{
					int to=known[root][i];
					if (at[to]==1)
					{
						if (S>=0)
							bad=1;
						else
							S=to;
					}
				}
				
				for (int root2=0;root2<n;root2++)
				{
					if (Q!=Q2)
						break;
					if (S!=-1&&S!=root2)
						continue;
					if (bad)
						continue;
					if (at[root2]!=1)
						continue;
					int C=0;
					for (int i=0;i<known[root2].size();i++)// bad edge
					{
						int to=known[root2][i];
						if (at[to]==2&&to!=root)
							C=1;
					}
					if (C)
						continue;
			//		cout<<mask<<" "<<root<<" "<<s<<" "<<root2<<" "<<dp[s][root2]<<" "<<dp[mask^s][root]<<endl;
					dp[mask][root]+=1ll*dp[s][root2]*dp[mask^s][root];
				}
				s=((s-1)&mask);
			}
//			cout<<mask<<"%"<<root<<" "<<dp[mask][root]<<endl;
		}
	
	if (H)
		dp[(1<<n)-1][0]=0;
	
	cout<<dp[(1<<n)-1][0]<<endl;
		
	return 0;
}