#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
#define pb(a) push_back(a);
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		ofstream myfile;
		ifstream ifile;
		myfile.open("output.txt");
		ifile.open("input.txt");
		int n,k;
		ifile>>n>>k;
		int a[n],b[n];
		FOR(i,0,n)
		{
			ifile>>a[i];
			b[i]=a[i];
		}
		sort(b,b+n);
		int m=b[n-k];
		myfile<<m<<"\n";
		FOR(i,0,n)
		{
			if(a[i]>=m)
			{
				myfile<<i+1<<' ';
				k--;
			}
			if(k==0)
			break;
		}
	}
}