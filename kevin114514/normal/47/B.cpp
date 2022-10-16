#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
void die(string S){puts(S.c_str());exit(0);}
int cnt[3];
int main()
{
	string S;
	for(int i=0;i<3;i++)
	{
		cin>>S;
//		cout<<S[0]-'A'<<endl;
		if(S[1]=='>')
			cnt[S[0]-'A']++;
		else	cnt[S[2]-'A']++;
	}
	int ans[3];
	ans[0]=ans[1]=ans[2]=-1;
	for(int i=0;i<3;i++)
		ans[cnt[i]]=i;
	if(~ans[0]&&~ans[1]&&~ans[2])
	{
		printf("%c%c%c\n",(char)(ans[0]+'A'),(char)(ans[1]+'A'),(char)(ans[2]+'A'));
	}
	else	puts("Impossible");
	return 0;
}