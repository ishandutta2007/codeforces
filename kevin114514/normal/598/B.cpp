#include<bits/stdc++.h>
using namespace std;
string S;
void _rotate(int l,int r,int k)
{
	k%=(r-l+1);
	k=r-l+1-k;
	rotate(S.begin()+l,S.begin()+l+k,S.begin()+r+1);
}
int main()
{
	int N;
	cin>>S>>N;
	while(N--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		_rotate(a,b,c);
	}
	puts(S.c_str());
	return 0;
}