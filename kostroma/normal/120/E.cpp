#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef long long li;
typedef pair <int, int> pi;
#define mp make_pair
#define pb push_back
void solve ();
int main()
{
		freopen("input.txt","r",stdin);
#ifndef _DEBUG
	freopen("output.txt","w",stdout);
#endif
	 solve();
	return 0;
}
//#define int li
int t;
void solve()
{
	cin>>t;
	while (t--)
	{
		int n; cin>>n;
		if (n%2)
			cout<<"0"<<endl;
		else 
			cout<<"1"<<endl;
	}
}