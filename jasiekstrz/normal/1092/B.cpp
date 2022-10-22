#include<bits/stdc++.h>
using namespace std;
int tab[110];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,w,i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>tab[i];
	sort(tab+1,tab+n+1);
	w=0;
	for(i=1;i<=n;i+=2)
	{
		w+=tab[i+1]-tab[i];
	}
	cout<<w;
	return 0;
}