#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=1e5;
int _t[N+10];
int tab[N+10];
void _init(int n)
{
	for(int i=1;i<=n;i++)
		cin>>_t[i];
	return;
}
int _and(int a,int b)
{
	//return _t[a]&_t[b];
	cout<<"and "<<a<<" "<<b<<endl;
	int x;
	cin>>x;
	return x;
}
int _or(int a,int b)
{
	//return _t[a]|_t[b];
	cout<<"or "<<a<<" "<<b<<endl;
	int x;
	cin>>x;
	return x;
}
void _fin(int a)
{
	cout<<"finish "<<a<<endl;
	return;
}
void solve3()
{
	int a[3]={_and(1,2),_and(1,3),_and(2,3)};
	int o[3]={_or(1,2),_or(1,3),_or(2,3)};
	tab[1]=(a[0]|a[1]);
	tab[2]=(a[0]|a[2]);
	tab[3]=(a[2]|a[1]);
	o[0]^=(tab[1]|tab[2]);
	o[1]^=(tab[1]|tab[3]);
	o[2]^=(tab[2]|tab[3]);
	tab[1]|=(o[0]&o[1]);
	tab[2]|=(o[0]&o[2]);
	tab[3]|=(o[2]&o[1]);
	return;
}
int main()
{
	int n,k;
	cin>>n>>k;
	//_init(n);
	solve3();
	for(int i=4;i<=n;i++)
	{
		int a=_and(1,i);
		int o=_or(1,i);
		tab[i]=tab[1]^a^o;
	}
	//for(int i=1;i<=n;i++)
	//	cerr<<tab[i]<<" ";
	//cerr<<endl;
	sort(tab+1,tab+n+1);
	_fin(tab[k]);
	return 0;
}