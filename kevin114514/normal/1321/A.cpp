#include<bits/stdc++.h>
using namespace std;
int A1[5000100],B1[5000100];
int main()
{
	int A=0,B=0;
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>A1[i];
	for(int i=0;i<N;i++)
		cin>>B1[i];
	while(N--)
	{
		int a=A1[N],b=B1[N];
		if(a&&!b)
			A++;
		else if(b&&!a)	B++;
	}
	if(A==0)
		puts("-1");
	else cout<<B/A+1<<endl;
	return 0;
}