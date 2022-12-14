#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#define MAX 12345678

std::vector<int> count[400010],V[400010];
int direX[6]={1,0,-1,0,0},direY[6]={0,1,0,-1,0};
std::vector< std::pair<int,int> > save, save2;
std::set< std::pair<int,int> > S;

int func(std::pair<int,int> A, std::pair<int,int> B)
{
	int C1 = count[A.first][A.second], C2 = count[B.first][B.second];
	
	for(int k=0;k<4;k++)
	{
		int s = A.first + direX[k], t = A.second + direY[k];
		if(V[A.first][A.second]>V[s][t]) count[s][t]--;
	}
	for(int k=0;k<4;k++)
	{
		int s = B.first + direX[k], t = B.second + direY[k];
		if(V[B.first][B.second]>V[s][t]) count[s][t]--;
	}
	
	int temp = V[A.first][A.second];
	V[A.first][A.second] = V[B.first][B.second];
	V[B.first][B.second] = temp;
	
	for(int k=0;k<4;k++)
	{
		int s = A.first + direX[k], t = A.second + direY[k];
		if(V[A.first][A.second]>V[s][t]) count[s][t]++;
	}
	for(int k=0;k<4;k++)
	{
		int s = B.first + direX[k], t = B.second + direY[k];
		if(V[B.first][B.second]>V[s][t]) count[s][t]++;
	}
	
	count[A.first][A.second] = count[B.first][B.second] = 0;
	for(int k=0;k<4;k++)
	{
		int s = A.first + direX[k], t = A.second + direY[k];
		if(V[s][t]>V[A.first][A.second]) count[A.first][A.second]++;
	}
	for(int k=0;k<4;k++)
	{
		int s = B.first + direX[k], t = B.second + direY[k];
		if(V[s][t]>V[B.first][B.second]) count[B.first][B.second]++;
	}
	
	
	int control = 0;
	for(int k=0;k<=4;k++)
	{
		if(control) break;
		int s = A.first + direX[k], t = A.second + direY[k];
		if(V[s][t]==1) continue;
		if(count[s][t]==4) control = 1;
	}
	for(int k=0;k<=4;k++)
	{
		if(control) break;
		int s = B.first + direX[k], t = B.second + direY[k];
		if(V[s][t]==1) continue;
		if(count[s][t]==4) control = 1;
	}
	
	for(int k=0;k<save.size();k++)
	{
		if(control) break;
		if(V[save[k].first][save[k].second]==1) continue;
		if(count[save[k].first][save[k].second]==4) control = 1;
	}
	
	for(int k=0;k<4;k++)
	{
		int s = A.first + direX[k], t = A.second + direY[k];
		if(V[A.first][A.second]>V[s][t]) count[s][t]--;
	}
	for(int k=0;k<4;k++)
	{
		int s = B.first + direX[k], t = B.second + direY[k];
		if(V[B.first][B.second]>V[s][t]) count[s][t]--;
	}
	
	temp = V[A.first][A.second];
	V[A.first][A.second] = V[B.first][B.second];
	V[B.first][B.second] = temp;
	
	for(int k=0;k<4;k++)
	{
		int s = A.first + direX[k], t = A.second + direY[k];
		if(V[A.first][A.second]>V[s][t]) count[s][t]++;
	}
	for(int k=0;k<4;k++)
	{
		int s = B.first + direX[k], t = B.second + direY[k];
		if(V[B.first][B.second]>V[s][t]) count[s][t]++;
	}
	count[A.first][A.second] = C1, count[B.first][B.second] = C2;
		
	if(control) return 0;
	else return 1;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<=a+1;i++) count[i].resize(b+2);
	
	for(int j=0;j<=b+1;j++) V[0].push_back(MAX);
	for(int j=0;j<=b+1;j++) V[a+1].push_back(MAX);
	for(int i=1;i<=a;i++)
	{
		V[i].push_back(MAX);
		for(int j=1;j<=b;j++)
		{
			int c;
			scanf("%d",&c);
			V[i].push_back(c);
		}
		V[i].push_back(MAX);
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			int C = 0;
			for(int k=0;k<4;k++)
			{
				int s = i+direX[k], t = j+direY[k];
				if(V[s][t]>V[i][j]) C++;
			}
			count[i][j] = C;
		}
	}
	
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(count[i][j]==4&&V[i][j]!=1) save.push_back(std::make_pair(i,j));
	if(save.size()==0)
	{
		printf("0");
		return 0;
	}
	if(save.size()>=11)
	{
		printf("2");
		return 0;
	}
	for(int i=0;i<save.size();i++)
	{
		for(int k=0;k<=4;k++)
		{
			int s = save[i].first + direX[k], t = save[i].second + direY[k];
			if(1<=s&&s<=a&1<=t&&t<=b) save2.push_back(std::make_pair(s,t));
		}
	}
	std::sort(save2.begin(),save2.end());
	save2.erase(std::unique(save2.begin(),save2.end()),save2.end());
	for(int i=0;i<save2.size();i++) S.insert(save2[i]);
	
	int ans = 0;
	for(int k=0;k<save2.size();k++)
	{
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				std::pair<int,int> P = std::make_pair(i,j);
				if(S.find(P)!=S.end()) continue;
				ans += func(save2[k],P);
			}
		}
	}
	for(int i=0;i<save2.size();i++)
	{
		for(int j=i+1;j<save2.size();j++)
		{
			ans += func(save2[i],save2[j]);
		}
	}
	
	if(ans==0) printf("2");
	else printf("1 %d",ans);
}