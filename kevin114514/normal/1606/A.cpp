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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string S;
		cin>>S;
		int AB=0,BA=0;
		for(int i=1;i<sz(S);i++)
			if(S[i-1]=='a'&&S[i]=='b')
				AB++;
			else if(S[i-1]=='b'&&S[i]=='a')
				BA++;
		bool fl=0;
		if(AB<BA)
		{
			swap(AB,BA);
			fl=1;
			for(int i=0;i<sz(S);i++)
				S[i]='a'+'b'-S[i];
		}
		if((AB-BA)%2)
		{
			if(S[0]=='a'&&S[1]=='b')
			{
				S[0]='b';
				AB--;
			}
			else if(S[sz(S)-2]=='a'&&S[sz(S)-1]=='b')
			{
				S[sz(S)-1]='a';
				AB--;
			}
			else
			{
				if(S[0]=='b'&&S[1]=='a')
					BA--;
				S[0]='a'+'b'-S[0];
				if(S[0]=='b'&&S[1]=='a')
					BA++;
				if(S[0]=='a'&&S[1]=='b')
					AB++;
			}
		}
		for(int i=1;i<sz(S)-1;i++) if(AB>BA)
			if(S[i]=='a'&&S[i-1]=='a'&&S[i+1]=='b')
			{
				AB--;
				BA--;
				S[i]='a'+'b'-S[i];
			}
		if(fl)
			for(int i=0;i<sz(S);i++)
				S[i]='a'+'b'-S[i];
		cout<<S<<endl;
	}
	return 0;
}