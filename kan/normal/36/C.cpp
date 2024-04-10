#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

const int maxn=3005;

struct tar
{
	double h,r,R;
};

tar t[maxn];
double h[maxn];

inline double geth(tar t,double r)
{
	if (r>t.R) return -1;
	if (r<t.r) return 0;
	return (r-t.r)/(t.R-t.r)*t.h;
}

inline double check(tar u,tar d,double r)
{
	double hd=geth(d,r);
	double hu=geth(u,r);
	if (hu<0 || hd<0) return 0.0;
	return hd-hu;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> t[i].h >> t[i].r >> t[i].R;
		h[i]=0.0;
		for (int j=0;j<i;j++)
		{
			h[i]=max(h[i],h[j]+check(t[i],t[j],t[i].r));
// 			cout << h[i] << endl;
			h[i]=max(h[i],h[j]+check(t[i],t[j],t[i].R));
// 			cout << h[i] << endl;
			h[i]=max(h[i],h[j]+check(t[i],t[j],t[j].r));
// 			cout << h[i] << endl;
			h[i]=max(h[i],h[j]+check(t[i],t[j],t[j].R));
// 			cout << h[i] << endl;
		}
	}
	double maxh=0;
	for (int i=0;i<n;i++) if (h[i]+t[i].h>maxh) maxh=h[i]+t[i].h;
	cout.precision(20);
	cout << maxh << endl;
	return 0;
}