#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
struct seg
{
	long double l;
	int pi;
	long double a;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int a[n];
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		seg arr[n];
		FOR(i,0,n)
		{
			arr[i].l=1;
			arr[i].pi=i-1;
			arr[i].a=a[i];
		}
		int in,v;
		FOR(i,1,n)
		{
			in=i;
			while(arr[in].pi!=-1 && arr[arr[in].pi].a>=arr[in].a)
			{
				if((in+arr[in].l)<n)
				{
					v=arr[in].l;
					arr[in+v].pi=arr[in].pi;
				}
				arr[arr[in].pi].a=((arr[arr[in].pi].a*arr[arr[in].pi].l)+(arr[in].a*arr[in].l))/(arr[arr[in].pi].l+arr[in].l);
				arr[arr[in].pi].l=arr[arr[in].pi].l+arr[in].l;
				in=arr[in].pi;
			}
		}
		in=0;
//		FOR(i,0,n)
//		cout<<arr[i].<<' ';
		cout<<fixed<<setprecision(10);
		while((in)<n)
		{
			FOR(i,0,arr[in].l)
			{
				cout<<arr[in].a<<'\n';
			}
			in+=arr[in].l;
//			cout<<in<<' ';
		}
	}
	return 0;
}