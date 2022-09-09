#pragma GCC optimize("O2")
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const double PI=acos(-1.0),RANG=PI/10,EPS=1e-5;

struct pnt
{
	double x,y;pnt(double _x=0,double _y=0):x(_x),y(_y){}
}P[4000];
pnt rotate(pnt P,double RANG)
{
	return pnt(P.x*cos(RANG)-P.y*sin(RANG),P.x*sin(RANG)+P.y*cos(RANG));
}
pnt read_pnt()
{
	pnt P;scanf("%lf%lf",&P.x,&P.y);return rotate(P,RANG);
}
pnt operator-(pnt A,pnt B){return pnt(A.x-B.x,A.y-B.y);}
bool operator<(pnt A,pnt B){return A.x<B.x;}
double dis(pnt A,pnt B)
{
	A=A-B;return sqrt(A.x*A.x+A.y*A.y);
}
struct line
{
	double k,b;line(pnt A,pnt B){k=(B.y-A.y)/(B.x-A.x);b=A.y-k*A.x;}
};
double dis(pnt P,line L)
{
	return abs(L.k*P.x-P.y+L.b)/sqrt(1+L.k*L.k);
}


int rk[4000],pos[4000]; 
struct query
{
	double k;int i,j;query(int _i,int _j):i(_i),j(_j){k=(P[i].y-P[j].y)/(P[i].x-P[j].x);}
	query():i(0),j(0),k(0){}
};
query Q[3100*3100/2];
bool operator<(query A,query B){return A.k<B.k;}

/*
struct Heap
{
	priority_queue <double> A,B;
	void clear(){while(!A.empty())A.pop();while(!B.empty())B.pop();}
	void ins(double x){A.push(x);}
	void del(double x){B.push(x);}
	double query(){while(!B.empty()&&abs(A.top()-B.top())<EPS)A.pop(),B.pop();return A.top();}
	bool empty(){while(!B.empty()&&abs(A.top()-B.top())<EPS)A.pop(),B.pop();return A.empty();}
}H;
*/
deque<int> H;

double maxn[3100][3100],d[3100][3100];

pair<double,int> X[10000];

int main()
{
//freopen("CF1588E.in","r",stdin);
//printf("%.10lf\n",PI);
	int n=0;double R=0;scanf("%d%lf",&n,&R);if(n==1){puts("0");return 0;}
	for(int i=1;i<=n;i++)P[i]=read_pnt();
	sort(P+1,P+n+1);for(int i=1;i<=n;i++)rk[i]=i,pos[i]=i;
	int c=0;for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)Q[++c]=query(i,j);
	sort(Q,Q+c);
	for(int i=0;i<c;i++)
	{
		int u=Q[i].i,v=Q[i].j;
		swap(rk[pos[u]],rk[pos[v]]);swap(pos[u],pos[v]);
		line L=line(P[u],P[v]);
		maxn[u][v]=maxn[v][u]=max(dis(P[rk[1]],L),dis(P[rk[n]],L));
	}
	//printf("%.5lf\n",maxn[100][1000]);
	for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)d[i][j]=d[j][i]=dis(P[i],P[j]);
	for(int i=1;i<=n;i++)
	{
		//if(i%10==0)printf("%d\n",i);
		for(int j=1,c=0;j<=n;j++)if(j!=i)X[c++]=(make_pair(atan2(P[j].y-P[i].y,P[j].x-P[i].x),j));
		sort(X,X+n-1);
		for(int j=0;j<n-1;j++){X[j+n-1]=(make_pair(X[j].first+2*PI,X[j].second));}
		//printf("%d\n",X.size());
		int l=lower_bound(X,X+2*(n-1),make_pair(X[0].first+0.5*PI,0))-X,r=l;
		H.clear();
		//puts("??");
		for(int j=0;j<n-1;j++)
		{
			//printf("%d\n",j);
			while(X[r].first<=X[j].first+1.5*PI)
			{
				//printf("%d\n",r);
				while(!H.empty()&&d[i][X[H.back()].second]<d[i][X[r].second])H.pop_back();
				H.push_back(r);r++;
			}
			while(X[l].first<=X[j].first+0.5*PI)
			{
				//printf("%d\n",l);
				while(!H.empty()&&H[0]<=l)H.pop_front();
				l++;
			}
			if(!H.empty())maxn[i][X[j].second]=maxn[X[j].second][i]=max(maxn[i][X[j].second],d[i][X[H[0]].second]);
		}
	}

	//printf("%.5lf\n",maxn[100][1000]);
	int ans=0;
	for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)if(maxn[i][j]<R)ans++;printf("%d\n",ans);
}