// Hydro submission #616247ca3ce37e7f84c1dc93@1633830859860
// 24B F1 Champions 
#include <bits/stdc++.h>
#define var long long
using namespace std;

const int scoreTable[100]={0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
map<string, int> athleteNumber;

struct athlete
{
	string name;
	int times[51]={0};
	int score;
};
int total=1;

athlete a[10000];

bool cmp1(athlete x, athlete y)
{
	if(x.score!=y.score)
		return x.score>y.score;
	for(int i=1; i<=50; i++)
		if(x.times[i]!=y.times[i])
			return x.times[i]>y.times[i];
}

bool cmp2(athlete x, athlete y)
{
	if(x.times[1]!=y.times[1])
		return x.times[1]>y.times[1];
	if(x.score!=y.score) return x.score>y.score;
	for(int i=2; i<=50; i++)
		if(x.times[i]!=y.times[i])
			return x.times[i]>y.times[i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin>>T;
	int k=0;
	while(T--)
	{
		int n; cin>>n;
		cin.get();
		for(int i=1; i<=n; i++)
		{
			string name; cin>>name;
			if(athleteNumber[name]==0)
			{
				//cout<<1<<endl;
				total++;
				athleteNumber[name]=total;
				a[total].name=name;
			}				
			int k=athleteNumber[name];
			a[k].score+=scoreTable[i];
			a[k].times[i]++;
		}
	}
	
	sort(a+1, a+total+1, cmp1);
	cout<<a[1].name<<endl;
	sort(a+1, a+total+1, cmp2);
	/*
	for(int i=1; i<=total; i++)
	{
		cout<<a[i].name<<endl<<a[i].score<<endl;
		for(int j=1; j<51; j++)
			cout<<a[i].times[j]<<" ";
		cout<<endl;
	}
	*/
	cout<<a[1+1-1].name<<endl;
	
    return 0;
}