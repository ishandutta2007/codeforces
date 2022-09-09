#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <stack>
#include <memory.h>
#include <queue>
#include <time.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef vector <int> vi;

void solve();
//#define FILE "fibseq"
//bool flag=true;
int main ()
{
#ifdef DEBUG
	freopen ("in.txt", "r", stdin);
	//freopen ("out.txt", "w", stdout);
	//cout<<FILE<<endl;
#else
	//freopen (FILE ".in", "r", stdin);
	//freopen (FILE ".out", "w", stdout);
#endif

	int t=1;
	while (t--)
		solve();
	return 0;
}

//#define int li

ld eps=1e-10;

ld vp, vd, t, f, c;

void solve()
{
	cin>>vp>>vd>>t>>f>>c;
	int ans=0;

	if (vd<vp+eps)
	{
		cout<<"0";
		return;
	}

	ld cur=t*vp;
	if (cur>c-eps)
	{
		cout<<"0";
		return;
	}
	ld ras=cur;
	while (true)
	{
		ld v=vd-vp;
		ld dob=ras/v;
		dob*=vp;
		cur+=dob;
		if (cur>c-eps)
		{
			cout<<ans;
			return;
		}
		ans++;

		dob=(f+cur/vd)*vp;
		cur+=dob;
		ras=cur;
		if (cur>c-eps)
		{
			cout<<ans;
			return;
		}
	}

}