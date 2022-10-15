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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string S,T;
		cin>>S>>T;
		srt(S);
		if(T=="abc")
		{
			int A=0,B=0,C=0;
			string SS;
			for(auto c:S)
				if(c=='a')
					A++;
				else if(c=='b')
					B++;
				else if(c=='c')
					C++;
				else	SS+=c;
			if(!A)
				cout<<S<<endl;
			else cout<<string(A,'a')<<string(C,'c')<<string(B,'b')<<SS<<endl;
		}
		else	cout<<S<<endl;
	}
	return 0;
}