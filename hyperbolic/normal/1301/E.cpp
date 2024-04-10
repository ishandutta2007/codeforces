#include <stdio.h>
#include <vector>
#define SIZE 15

struct str{
	int x0;
	int y0;
	int value;
};
std::vector<str> V;

int a,b;
int R[510][510],G[510][510],B[510][510],Y[510][510];
int check[20][510][510],sum[20][510][510];
char x[510][510];
int area(char type, int l, int r, int u, int d)
{
	if(l<1||r>a||u<1||d>b) return -1;
	if(type=='R') return R[r][d] - R[l-1][d] - R[r][u-1] + R[l-1][u-1];
	if(type=='G') return G[r][d] - G[l-1][d] - G[r][u-1] + G[l-1][u-1];
	if(type=='B') return B[r][d] - B[l-1][d] - B[r][u-1] + B[l-1][u-1];
	if(type=='Y') return Y[r][d] - Y[l-1][d] - Y[r][u-1] + Y[l-1][u-1];
}

int area2(int type, int l, int r, int u, int d)
{
	if(l<1||r>a||u<1||d>b) return -1;
	if(l>r || u>d) return -1;
	return sum[type][r][d] - sum[type][l-1][d] - sum[type][r][u-1] + sum[type][l-1][u-1];
}
int main()
{
	int c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) R[i][j] = R[i][j-1]+ (x[i][j]=='R'?1:0);
	for(int j=1;j<=b;j++) for(int i=1;i<=a;i++) R[i][j] += R[i-1][j];
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) G[i][j] = G[i][j-1]+ (x[i][j]=='G'?1:0);
	for(int j=1;j<=b;j++) for(int i=1;i<=a;i++) G[i][j] += G[i-1][j];
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) B[i][j] = B[i][j-1]+ (x[i][j]=='B'?1:0);
	for(int j=1;j<=b;j++) for(int i=1;i<=a;i++) B[i][j] += B[i-1][j];
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) Y[i][j] = Y[i][j-1]+ (x[i][j]=='Y'?1:0);
	for(int j=1;j<=b;j++) for(int i=1;i<=a;i++) Y[i][j] += Y[i-1][j];
	
	
	for(int i=1;i<a;i++)
	{
		for(int j=1;j<b;j++)
		{
			int c = 0; //i~i+1 / j~j+1
			for(int h=1;h<=a;h++)
			{
				int R = area('R',i-h+1,i,j-h+1,j);
				int G = area('G',i-h+1,i,j+1,j+h);
				int B = area('B',i+1,i+h,j+1,j+h);
				int Y = area('Y',i+1,i+h,j-h+1,j);
				int C = h*h;
				
				if(R==C && G==C && B==C && Y==C);
				else
				{
					c = h-1;
					break;
				}
			}
			if(c>SIZE) V.push_back({i,j,c});
			else check[c][i][j] = 1;
		}
	}
	
	
	for(int i=1;i<=SIZE;i++)
	{
		for(int j=1;j<=a;j++) for(int k=1;k<=b;k++) sum[i][j][k] = sum[i][j][k-1] + check[i][j][k];
		for(int k=1;k<=b;k++) for(int j=1;j<=a;j++) sum[i][j][k] += sum[i][j-1][k];
	}
	
	
	for(int i=1;i<=c;i++)
	{
		int l,u,r,d;
		scanf("%d%d%d%d",&l,&u,&r,&d);
		l--,u--;
		int ans = 0;
		
		for(int j=0;j<V.size();j++)
		{
			int w1 = V[j].x0 - l;
			int w2 = r - V[j].x0;
			int h1 = V[j].y0 - u;
			int h2 = d - V[j].y0;
			int A = V[j].value;
			
			if(w1>=0 && w2>=0 && h1>=0 && h2>=0)
			{
				A = A<w1?A:w1;
				A = A<w2?A:w2;
				A = A<h1?A:h1;
				A = A<h2?A:h2;
				ans = ans>A?ans:A;
			}
		}
		if(ans>SIZE) printf("%d\n",4*ans*ans);
		else
		{
			for(int k=SIZE;k>ans;k--)
			{
				int w1 = l+k;
				int w2 = r-k;
				int h1 = u+k;
				int h2 = d-k;
				
				for(int j=SIZE;j>=k;j--)
				{
					int A = area2(j,w1,w2,h1,h2);
					//printf("%d %d %d %d %d !!\n",w1,w2,h1,h2,A);
					if(A>0)
					{
						printf("%d\n",4*k*k);
						goto u;
					}
				}
			}
			printf("%d\n",4*ans*ans);
			u:;
		}
	}
}