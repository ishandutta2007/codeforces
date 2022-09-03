#include<cstdio>
#include<set>
#include<algorithm>

int a[100001];
int b[100001];

struct work
{
	int x;
	int y;

	int a;
	int b;
} w[1000000];
int wn;

bool operator <(const work &a,const work &b)
{
	if(a.x!=b.x)return a.x<b.x;
	return a.y>b.y;
}

std::multiset<int> U,D;

int r[100001];

int main()
{
	U.insert(987654321);
	D.insert(987654321);
	int i,j,n,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		a[t-1]=i;
	}
    for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		b[t-1]=i;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]<b[i])
		{
            w[wn].x=0;
            w[wn].y=1;
            w[wn].a=-1;
            w[wn].b=b[i]-a[i];
			wn++;

			w[wn].x=b[i]-a[i];
			w[wn].y=-1;
			w[wn].a=-1;
			w[wn].b=b[i]-a[i];
			wn++;

            w[wn].x=b[i]-a[i];
            w[wn].y=1;
            w[wn].a=1;
            w[wn].b=a[i]-b[i];
			wn++;

			w[wn].x=b[i]+1;
			w[wn].y=-1;
			w[wn].a=1;
			w[wn].b=a[i]-b[i];
			wn++;

            w[wn].x=b[i]+1;
            w[wn].y=1;
            w[wn].a=-1;
            w[wn].b=n+b[i]-a[i];
			wn++;

			w[wn].x=n;
			w[wn].y=-1;
			w[wn].a=-1;
			w[wn].b=n+b[i]-a[i];
			wn++;
		}
		else
		{
            w[wn].x=0;
            w[wn].y=1;
            w[wn].a=1;
            w[wn].b=a[i]-b[i];
			wn++;

			w[wn].x=b[i]+1;
			w[wn].y=-1;
			w[wn].a=1;
			w[wn].b=a[i]-b[i];
			wn++;

            w[wn].x=b[i]+1;
            w[wn].y=1;
            w[wn].a=-1;
            w[wn].b=n+b[i]-a[i];
			wn++;

			w[wn].x=n+b[i]-a[i];
			w[wn].y=-1;
			w[wn].a=-1;
			w[wn].b=n+b[i]-a[i];
			wn++;

            w[wn].x=n+b[i]-a[i];
            w[wn].y=1;
            w[wn].a=1;
            w[wn].b=a[i]-b[i]-n;
			wn++;

			w[wn].x=n;
			w[wn].y=-1;
			w[wn].a=1;
			w[wn].b=a[i]-b[i]-n;
			wn++;
		}
	}
	std::sort(w,w+wn);
	for(i=0;i<n;i++)r[i]=-1;
    for(i=0;i<wn;i++)
	{
		if(i)
		{
			for(j=w[i-1].x;j<w[i].x;j++)
			{
				r[j]=987654321;
				if(!U.empty()&&*U.begin()+j<r[j])r[j]=j+*U.begin();
				if(!D.empty()&&*D.begin()-j<r[j])r[j]=*D.begin()-j;
			}
		}
		if(w[i].y>0)
		{
            if(w[i].a==-1)D.insert(w[i].b);
            else U.insert(w[i].b);
		}
		else
		{
            if(w[i].a==-1)D.erase(D.find(w[i].b));
            else U.erase(U.find(w[i].b));
		}
	}
	for(i=0;i<n;i++)printf("%d\n",r[i]);
}