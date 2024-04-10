#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int n;

bool f[17][17][17][17][17][17];

void solve()
{
	int r1,c1,r2,c2,r3,c3,tr,tc;
	scanf("%d",&n);
	scanf("%d%d",&r1,&c1);
	scanf("%d%d",&r2,&c2);
	scanf("%d%d",&r3,&c3);
	scanf("%d%d",&tr,&tc);

	bool flg=0;
	if(r1%2==tr%2&&c1%2==tc%2) flg=1;
	if(r2%2==tr%2&&c2%2==tc%2) flg=1;
	if(r3%2==tr%2&&c3%2==tc%2) flg=1;
	if(!flg)
	{
		puts("NO");
		return;
	}

	vector<int> ax,ay;
	rep(i,6)
	{
		ax.push_back(r1/2*2-3+i);
		ax.push_back(r2/2*2-3+i);
		ax.push_back(r3/2*2-3+i);
		ax.push_back(tr/2*2-3+i);
		ay.push_back(c1/2*2-3+i);
		ay.push_back(c2/2*2-3+i);
		ay.push_back(c3/2*2-3+i);
		ay.push_back(tc/2*2-3+i);
	}

	sort(ax.begin(),ax.end());ax.resize(unique(ax.begin(),ax.end())-ax.begin());
	sort(ay.begin(),ay.end());ay.resize(unique(ay.begin(),ay.end())-ay.begin());
	r1=lower_bound(ax.begin(),ax.end(),r1)-ax.begin();
	r2=lower_bound(ax.begin(),ax.end(),r2)-ax.begin();
	r3=lower_bound(ax.begin(),ax.end(),r3)-ax.begin();
	tr=lower_bound(ax.begin(),ax.end(),tr)-ax.begin();
	c1=lower_bound(ay.begin(),ay.end(),c1)-ay.begin();
	c2=lower_bound(ay.begin(),ay.end(),c2)-ay.begin();
	c3=lower_bound(ay.begin(),ay.end(),c3)-ay.begin();
	tc=lower_bound(ay.begin(),ay.end(),tc)-ay.begin();

	bool ans=0;
	vector<int> qr1,qr2,qr3,qc1,qc2,qc3;int hd=0;
	qr1.push_back(r1);qr2.push_back(r2);qr3.push_back(r3);
	qc1.push_back(c1);qc2.push_back(c2);qc3.push_back(c3);
	while(hd<qr1.size())
	{
		int r1=qr1[hd],r2=qr2[hd],r3=qr3[hd];
		int c1=qc1[hd],c2=qc2[hd],c3=qc3[hd];
		hd++;
		
		if(abs(r1-r2)<=1&&abs(c1-c2)<=1)
		{
			int nr1=r1,nr2=r2,nr3=r3;
			int nc1=c1,nc2=c2,nc3=c3;
			nr1=r2*2-r1;nc1=c2*2-c1;
			if(nr1==tr&&nc1==tc){ans=1;break;}
			if(0<=nr1&&nr1<ax.size()&&1<=ax[nr1]&&ax[nr1]<=n&&0<=nc1&&nc1<ay.size()&&1<=ay[nc1]&&ay[nc1]<=n&&!f[nr1][nc1][nr2][nc2][nr3][nc3])
			{
				f[nr1][nc1][nr2][nc2][nr3][nc3]=1;
				qr1.push_back(nr1);qr2.push_back(nr2);qr3.push_back(nr3);
				qc1.push_back(nc1);qc2.push_back(nc2);qc3.push_back(nc3);
			}
			nr1=r1,nr2=r2,nr3=r3;
			nc1=c1,nc2=c2,nc3=c3;
			nr2=r1*2-r2;nc2=c1*2-c2;
			if(nr2==tr&&nc2==tc){ans=1;break;}
			if(0<=nr2&&nr2<ax.size()&&1<=ax[nr2]&&ax[nr2]<=n&&0<=nc2&&nc2<ay.size()&&1<=ay[nc2]&&ay[nc2]<=n&&!f[nr1][nc1][nr2][nc2][nr3][nc3])
			{
				f[nr1][nc1][nr2][nc2][nr3][nc3]=1;
				qr1.push_back(nr1);qr2.push_back(nr2);qr3.push_back(nr3);
				qc1.push_back(nc1);qc2.push_back(nc2);qc3.push_back(nc3);
			}
		}
		if(abs(r1-r3)<=1&&abs(c1-c3)<=1)
		{
			int nr1=r1,nr2=r2,nr3=r3;
			int nc1=c1,nc2=c2,nc3=c3;
			nr1=r3*2-r1;nc1=c3*2-c1;
			if(nr1==tr&&nc1==tc){ans=1;break;}
			if(0<=nr1&&nr1<ax.size()&&1<=ax[nr1]&&ax[nr1]<=n&&0<=nc1&&nc1<ay.size()&&1<=ay[nc1]&&ay[nc1]<=n&&!f[nr1][nc1][nr2][nc2][nr3][nc3])
			{
				f[nr1][nc1][nr2][nc2][nr3][nc3]=1;
				qr1.push_back(nr1);qr2.push_back(nr2);qr3.push_back(nr3);
				qc1.push_back(nc1);qc2.push_back(nc2);qc3.push_back(nc3);
			}
			nr1=r1,nr2=r2,nr3=r3;
			nc1=c1,nc2=c2,nc3=c3;
			nr3=r1*2-r3;nc3=c1*2-c3;
			if(nr3==tr&&nc3==tc){ans=1;break;}
			if(0<=nr3&&nr3<ax.size()&&1<=ax[nr3]&&ax[nr3]<=n&&0<=nc3&&nc3<ay.size()&&1<=ay[nc3]&&ay[nc3]<=n&&!f[nr1][nc1][nr2][nc2][nr3][nc3])
			{
				f[nr1][nc1][nr2][nc2][nr3][nc3]=1;
				qr1.push_back(nr1);qr2.push_back(nr2);qr3.push_back(nr3);
				qc1.push_back(nc1);qc2.push_back(nc2);qc3.push_back(nc3);
			}
		}
		if(abs(r2-r3)<=1&&abs(c2-c3)<=1)
		{
			int nr1=r1,nr2=r2,nr3=r3;
			int nc1=c1,nc2=c2,nc3=c3;
			nr2=r3*2-r2;nc2=c3*2-c2;
			if(nr2==tr&&nc2==tc){ans=1;break;}
			if(0<=nr2&&nr2<ax.size()&&1<=ax[nr2]&&ax[nr2]<=n&&0<=nc2&&nc2<ay.size()&&1<=ay[nc2]&&ay[nc2]<=n&&!f[nr1][nc1][nr2][nc2][nr3][nc3])
			{
				f[nr1][nc1][nr2][nc2][nr3][nc3]=1;
				qr1.push_back(nr1);qr2.push_back(nr2);qr3.push_back(nr3);
				qc1.push_back(nc1);qc2.push_back(nc2);qc3.push_back(nc3);
			}
			nr1=r1,nr2=r2,nr3=r3;
			nc1=c1,nc2=c2,nc3=c3;
			nr3=r2*2-r3;nc3=c2*2-c3;
			if(nr3==tr&&nc3==tc){ans=1;break;}
			if(0<=nr3&&nr3<ax.size()&&1<=ax[nr3]&&ax[nr3]<=n&&0<=nc3&&nc3<ay.size()&&1<=ay[nc3]&&ay[nc3]<=n&&!f[nr1][nc1][nr2][nc2][nr3][nc3])
			{
				f[nr1][nc1][nr2][nc2][nr3][nc3]=1;
				qr1.push_back(nr1);qr2.push_back(nr2);qr3.push_back(nr3);
				qc1.push_back(nc1);qc2.push_back(nc2);qc3.push_back(nc3);
			}
		}

	}

	if(ans) puts("YES"); else puts("NO");
	for(int i=0;i<qr1.size();i++) f[qr1[i]][qc1[i]][qr2[i]][qc2[i]][qr3[i]][qc3[i]]=0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}