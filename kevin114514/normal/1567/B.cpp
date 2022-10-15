#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
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
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
int Xor[300303];
int main()
{
	for(int i=1;i<=300000;i++)
		Xor[i]=Xor[i-1]^i;
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int c=Xor[a-1];
		if(c==b)
			cout<<a<<endl;
		else if(Xor[a]==b)
			cout<<a+2<<endl;
		else	cout<<a+1<<endl;
	}
	return 0;
}