#include <iostream>
#include <string>
std::string S[100010];
std::string T[100010];
int a,x[100010];
long long int check[100010][10];
long long int MAX = 1;
long long int func(int s, int t)
{
	long long int s1,s2;
	if(s==a) return 0;
	if(check[s][t]!=-1) return check[s][t];
	if(t==0)
	{
		if(S[s]<=S[s+1]) s1 = func(s+1,0);
		else s1 = MAX;
		if(S[s]<=T[s+1]) s2 = func(s+1,1)+x[s+1];
		else s2 = MAX;
		return check[s][t] = s1<s2?s1:s2;
	}
	if(t==1)
	{
		if(T[s]<=S[s+1]) s1 = func(s+1,0);
		else s1 = MAX;
		if(T[s]<=T[s+1]) s2 = func(s+1,1)+x[s+1];
		else s2 = MAX;
		return check[s][t] = s1<s2?s1:s2;
	}
}
int main()
{
	for(int i=1;i<=15;i++) MAX*=10;
	MAX++;
	std::cin>>a;
	for(int i=1;i<=a;i++) std::cin>>x[i];
	for(int i=1;i<=a;i++) std::cin>>S[i];
	for(int i=1;i<=a;i++) for(int j=S[i].size()-1;j>=0;j--) T[i]+=S[i][j];
	for(int i=0;i<=a;i++) check[i][0] = check[i][1] = -1;
	long long int s1 = func(1,0);
	long long int s2 = func(1,1)+x[1];
	long long int ans = s1<s2?s1:s2;
	if(ans>=MAX) std::cout<<"-1";
	else std::cout<<ans;
}