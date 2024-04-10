#include<bits/stdc++.h>
using namespace std;
int X[110],P;
bool iss[110];
int main()
{
int T;
cin>>T;
while(T--)
{
    int N,K;
    cin>>N>>K;
P=0;
memset(iss,false,sizeof(iss));
for(int i=0;i<110;i++)
	X[i]=1;
    for(int i=0;i<N;i++)
{
int A;
cin>>A;
if(!iss[A])
{
iss[A]=true;
X[P++]=A;
}
}
if(P>K)
puts("-1");
else
{
cout<<N*K<<endl;
for(int i=0;i<N;i++)
for(int j=0;j<K;j++)
cout<<X[j]<<" ";
puts("");
}
}
return 0;
}