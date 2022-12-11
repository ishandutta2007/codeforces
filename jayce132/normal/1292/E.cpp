#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int x;cin>>x;
	return x;
}

const int maxn=52;

int n;

const char mp[3]={'C','H','O'};

//00,01,02,12,

int a[maxn];
int b[5][2]={{0,0},{0,1},{0,2},{1,2},{2,2}};

inline vector<int> ask(int *a)
{
	printf("? ");
	REP(i,1,n)printf("%c",mp[a[i]]);
	cout<<endl;
	vector<int>x;
	int k=read();
	while(k--)x.push_back(read());
	return x;
}

inline void doing()
{
	cin>>n;
	memset(a,-1,sizeof(a));
	if(n>=5)
	{
		
		REP(i,0,4)
		{
			cout<<"? "; REP(j,0,1)cout<<mp[b[i][j]]; cout<<endl;
			int k=read();
			while(k--)
			{
				int x=read();
				a[x]=b[i][0];
				a[x+1]=b[i][1];
			}
		}
		int flg=0;
		REP(i,1,n)if(a[i]==-1);else flg=1;
		if(flg==0)
		{
			REP(i,2,n-1)a[i]=1;
		}
		int Fi=0;
		REP(i,1,n)if(~a[i]){ Fi=i;break;}
		REP(j,Fi+1,n-1)
		{
			if(~a[j])continue;
			int lst=a[j-1];
			assert(lst!=0);
			if(lst==1)
			{
				a[j]=1;
			}else
			{
				a[j]=1;
			}
		}
		Fi=0;
		DREP(i,n,1)if(~a[i]){ Fi=i;break;}
		//REP(i,1,n)cerr<<a[i]<<endl;
		DREP(j,Fi-1,2)
		{
			if(~a[j])continue;
			int lst=a[j+1];
			assert(lst!=2);
			if(lst==1)
			{
				a[j]=1;
			}
			else
			{
				a[j]=1;
			}
		}
		REP(S,0,2)
		{
			static int b[maxn];
			REP(i,1,n)b[i]=a[i];
			if(a[1]==-1)b[1]=(S&1)+1; else b[1]=a[1];
			if(a[n]==-1)b[n]=(S>>1&1); else b[n]=a[n];
			vector<int>t=ask(b);
			/*cout<<"? ";	REP(i,1,n)cout<<mp[b[i]]; cout<<endl;
			int k=read();
			if(k)read();*/
			if(SZ(t)>=1){ a[1]=b[1]; a[n]=b[n]; break;}
		}
		if(a[1]==-1)a[1]=1+1; if(a[n]==-1)a[n]=1;
	}else
	{
		REP(i,0,3)
		{
			cout<<"? "; REP(j,0,1)cout<<mp[b[i][j]]; cout<<endl;
			int k=read();
			while(k--)
			{
				int x=read();
				a[x]=b[i][0];
				a[x+1]=b[i][1];
			}
		}
		if(~a[2] && ~a[3])
		{
			REP(i,1,2)REP(j,0,2)
			{
				static int b[maxn];
				REP(th,1,n)b[th]=a[th];
				if(b[1]==-1)b[1]=i;
				if(b[n]==-1)b[n]=j;
				vector<int> rlg=ask(b);
				if(SZ(rlg)>=1){ a[1]=b[1]; a[4]=b[4]; }
			}
		}else
		{
			REP(i,4,4)
			{
				cout<<"? "; REP(j,0,1)cout<<mp[b[i][j]]; cout<<endl;
				int k=read();
				while(k--)
				{
					int x=read();
					a[x]=b[i][0];
					a[x+1]=b[i][1];
				}
			}
			REP(i,2,3)if(a[i]==-1)a[i]=1;

			int Fi=0;
			REP(i,1,n)if(~a[i]){ Fi=i;break;}
			REP(j,Fi+1,n-1)
			{
				if(~a[j])continue;
				int lst=a[j-1];
				assert(lst!=0);
				if(lst==1)
				{
					a[j]=1;
				}else
				{
					a[j]=1;
				}
			}
			Fi=0;
			DREP(i,n,1)if(~a[i]){ Fi=i;break;}
			//REP(i,1,n)cerr<<a[i]<<endl;
			DREP(j,Fi-1,2)
			{
				if(~a[j])continue;
				int lst=a[j+1];
				assert(lst!=2);
				if(lst==1)
				{
					a[j]=1;
				}
				else
				{
					a[j]=1;
				}
			}
			
			if(!(a[2]==1 && a[3]==1))
			{
				static int b[maxn];
				REP(i,1,n)b[i]=a[i];
				if(a[n]==-1)
				{
					b[n]=0;
					if(ask(b).size()==1 )a[n]=0; else a[n]=1;
				}
				if(a[1]==-1)
				{
					b[1]=2;
					if(ask(b).size()==1 )a[1]=2; else a[1]=1;
				}
			}else
			{
				printf("? HHH");cout<<endl;
				int k=read();
				int vis[10]={0};
				while(k--)vis[read()]=1;
				a[2]=1;a[3]=1;
				if(a[1]==-1)
				{
					if(vis[1])a[1]=1; else a[1]=2;
				}
				if(a[n]==-1)
				{
					if(vis[2])a[n]=1; else a[n]=0;
				}
			}
		}
	}
	REP(i,1,n)if(a[i]==-1)
	{
		cout<<"! ";REP(i,1,n) cout<<"C"; cout<<endl;
	}
	cout<<"! ";REP(i,1,n) cout<<mp[a[i]]; cout<<endl;
	if(!read())exit(0);
}

int main()
{
	int t=read();
	while(t--)
	{
		doing();
	}
	return 0;
}