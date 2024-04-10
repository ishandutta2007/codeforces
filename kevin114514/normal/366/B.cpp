#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
void die(string S){puts(S.c_str());exit(0);}
int tot[100100];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		tot[i%k]+=x;
	}
	int mn=1e9,ind=0;
	for(int i=0;i<k;i++)
		if(tot[i]<mn)
		{
			mn=tot[i];
			ind=i;
		}
	cout<<ind+1<<endl;
	return 0;
}