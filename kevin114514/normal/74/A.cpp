#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	int n;
	cin>>n;
	string champion;
	int score=-1e7;
	while(n--)
	{
		string name;
		cin>>name;
		int a,b,c,d,e,f,g;
		cin>>a>>b>>c>>d>>e>>f>>g;
		int Score=a*100-b*50+c+d+e+f+g;
		if(Score>score)
		{
			champion=name;
			score=Score;
		}
	}
	puts(champion.c_str());
	return 0;
}