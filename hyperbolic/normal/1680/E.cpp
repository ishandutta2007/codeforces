#include <stdio.h>
#include <vector>
#include <algorithm>

struct str{
	int typeL;
	int left;
	int typeR;
	int right;
	int typeA;
};
bool operator<(str a, str b)
{
	return a.left<b.left;
}
std::vector<str> V;
int ans;
int direX[5]={1,0,-1,0},direY[5]={0,1,0,-1},a;

char x[3][200010];
int check[3][200010];
str func(int s, int t)
{
	check[s][t] = 1;
	str A = {s,t,s,t,s};
	for(int i=0;i<4;i++)
	{
		int s2 = s+direX[i], t2 = t+direY[i];
		if(1<=s2&&s2<=2&&1<=t2&&t2<=a&&x[s2][t2]=='*'&&check[s2][t2]==0)
		{
			ans++;
			str B = func(s2,t2);
			if(A.left>B.left) A.typeL = B.typeL, A.left = B.left;
			else if(A.left==B.left) A.typeL = 3;
			if(A.right<B.right) A.typeR = B.typeR, A.right = B.right;
			else if(A.right==B.right) A.typeR = 3;
			if(B.typeA==3) A.typeA = 3;
			else if(A.typeA+B.typeA==3) A.typeA = 3;
		}
	}
	return A;
}

int count1[200010],count2[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		ans = 0;
		scanf("%d",&a);
		for(int i=1;i<=2;i++) for(int j=1;j<=a;j++) check[i][j] = 0;
		
		scanf("%s%s",x[1]+1,x[2]+1);
		int L = 1;
		for(int i=1;i<=2;i++)
		{
			for(int j=1;j<=a;j++)
			{
				if(x[i][j]=='*'&&check[i][j]==0)
				{
					V.push_back(func(i,j));
				}
			}
		}
		
		std::sort(V.begin(),V.end());
		if(V.size()==1) printf("%d\n",ans);
		else
		{
			int n = V.size()-1;
			for(int i=1;i<=n;i++)
			{
				if(V[i-1].typeR+V[i].typeL==3)
				{
					ans += (V[i].left-V[i-1].right+1);
					if(V[i].left==V[i].right) V[i].typeR = 3;
				}
				else ans += (V[i].left-V[i-1].right);
			}
			printf("%d\n",ans);
		}
	}
}