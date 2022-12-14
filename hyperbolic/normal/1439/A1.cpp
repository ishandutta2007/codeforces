#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > ans,V;
char x[110][110];

void func(int s, int t)
{
	int count = 0;
	if(x[s][t]=='1') count++;
	if(x[s][t+1]=='1') count++;
	if(x[s+1][t]=='1') count++;
	if(x[s+1][t+1]=='1') count++;
	if(count==4)
	{
		V.clear();
		V.push_back(std::make_pair(s,t));
		V.push_back(std::make_pair(s,t+1));
		V.push_back(std::make_pair(s+1,t));
		for(int k=0;k<V.size();k++) ans.push_back(V[k]);
		for(int k=0;k<V.size();k++) x[V[k].first][V[k].second] = ('0'+'1'-x[V[k].first][V[k].second]);
		func(s,t);
	}
	else if(count==3)
	{
		V.clear();
		for(int i=0;i<=1;i++) for(int j=0;j<=1;j++) if(x[s+i][t+j]=='1') V.push_back(std::make_pair(s+i,t+j));
		for(int k=0;k<V.size();k++) ans.push_back(V[k]);
		for(int k=0;k<V.size();k++) x[V[k].first][V[k].second] = ('0'+'1'-x[V[k].first][V[k].second]);
		return;
	}
	else if(count==2)
	{
		V.clear();
		for(int i=0;i<=1;i++) for(int j=0;j<=1;j++) if(x[s+i][t+j]=='0') V.push_back(std::make_pair(s+i,t+j));
		for(int i=0;i<=1;i++)
		{
			for(int j=0;j<=1;j++)
			{
				if(x[s+i][t+j]=='1')
				{
					V.push_back(std::make_pair(s+i,t+j));
					for(int k=0;k<V.size();k++) ans.push_back(V[k]);
					for(int k=0;k<V.size();k++) x[V[k].first][V[k].second] = ('0'+'1'-x[V[k].first][V[k].second]);
					func(s,t);
					return;
				}
			}
		}
	}
	else if(count==1)
	{
		V.clear();
		for(int i=0;i<=1;i++) for(int j=0;j<=1;j++) if(x[s+i][t+j]=='1') V.push_back(std::make_pair(s+i,t+j));
		int C = 0;
		for(int i=0;i<=1;i++)
		{
			for(int j=0;j<=1;j++)
			{
				if(x[s+i][t+j]=='0')
				{
					C++;
					V.push_back(std::make_pair(s+i,t+j));
					if(C==2)
					{
						for(int k=0;k<V.size();k++) ans.push_back(V[k]);
						for(int k=0;k<V.size();k++) x[V[k].first][V[k].second] = ('0'+'1'-x[V[k].first][V[k].second]);
						func(s,t);
						return;
					}
				}
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		for(int i=1;i+1<=a;i++)
		{
			for(int j=1;j+1<b;j++)
			{
				V.clear();
				if(x[i][j]=='1') V.push_back(std::make_pair(i,j));
				if(x[i+1][j]=='1') V.push_back(std::make_pair(i+1,j));
				if(V.size()==0) continue;
				if(x[i][j+1]=='1'&&V.size()<3) V.push_back(std::make_pair(i,j+1));
				if(x[i+1][j+1]=='1'&&V.size()<3) V.push_back(std::make_pair(i+1,j+1));
				if(x[i][j+1]=='0'&&V.size()<3) V.push_back(std::make_pair(i,j+1));
				if(x[i+1][j+1]=='0'&&V.size()<3) V.push_back(std::make_pair(i+1,j+1));
				
				for(int k=0;k<V.size();k++) ans.push_back(V[k]);
				for(int k=0;k<V.size();k++) x[V[k].first][V[k].second] = ('0'+'1'-x[V[k].first][V[k].second]);
			}
		}
		for(int i=1;i+1<a;i++)
		{
			int j = b-1;
			V.clear();
			if(x[i][j]=='1') V.push_back(std::make_pair(i,j));
			if(x[i][j+1]=='1') V.push_back(std::make_pair(i,j+1));
			if(V.size()==0) continue;
			if(x[i+1][j]=='1'&&V.size()<3) V.push_back(std::make_pair(i+1,j));
			if(x[i+1][j+1]=='1'&&V.size()<3) V.push_back(std::make_pair(i+1,j+1));
			if(x[i+1][j]=='0'&&V.size()<3) V.push_back(std::make_pair(i+1,j));
			if(x[i+1][j+1]=='0'&&V.size()<3) V.push_back(std::make_pair(i+1,j+1));
			
			for(int k=0;k<V.size();k++) ans.push_back(V[k]);
			for(int k=0;k<V.size();k++) x[V[k].first][V[k].second] = ('0'+'1'-x[V[k].first][V[k].second]);
		}
		func(a-1,b-1);
		
		printf("%d\n",ans.size()/3);
		for(int i=0;i<ans.size();i+=3)
		{
			printf("%d %d ",ans[i].first,ans[i].second);
			printf("%d %d ",ans[i+1].first,ans[i+1].second);
			printf("%d %d\n",ans[i+2].first,ans[i+2].second);
		}
	}
}