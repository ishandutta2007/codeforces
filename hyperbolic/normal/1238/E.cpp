#include <stdio.h>
#define MAX 1234567890
int a,b;
int save[1100010][21],save2[21];
int temp[21];
int sum[21][21];
int check[21];
void func1(int k)
{
	if(k>b)
	{
		int C = 0;
		for(int i=b;i>=1;i--) C*=2, C+=check[i];
		for(int i=1;i<=b;i++) save[C][i] = temp[i];
		return;
	}
	
	//select
	check[k] = 1;
	for(int i=1;i<k;i++) if(check[i]==0) temp[k] += sum[k][i], temp[i] -= sum[k][i];
	func1(k+1);
	for(int i=1;i<k;i++) if(check[i]==0) temp[k] -= sum[k][i], temp[i] += sum[k][i];
	//not
	check[k] = 0;
	for(int i=1;i<k;i++) if(check[i]==1) temp[i] += sum[k][i], temp[k] -= sum[k][i];
	func1(k+1);
	for(int i=1;i<k;i++) if(check[i]==1) temp[i] -= sum[k][i], temp[k] += sum[k][i];
}

int check2[1100010][21];
int func2(int C, int k)
{
	if(k>b) return 0;
	if(check2[C][k]!=-1) return check2[C][k];
	
	int C2 = C;
	int ans = MAX;
	for(int i=1;i<=b;i++)
	{
		if(C2%2==1)
		{
			int S = func2(C-(1<<(i-1)),k+1) + (2*save[C][i]-save2[i])*k;
			ans = ans<S?ans:S;
		}
		C2/=2;
	}
	return check2[C][k] = ans;
}

char x[100010];
int main()
{
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	for(int i=1;i<a;i++)
	{
		if(x[i]==x[i+1]) continue;
		sum[x[i]-'a'+1][x[i+1]-'a'+1]++;
		sum[x[i+1]-'a'+1][x[i]-'a'+1]++;
	}
	for(int i=1;i<=b;i++) for(int j=1;j<=b;j++) save2[i] += sum[i][j];
	func1(1);
	int C = (1<<b);
	for(int i=1;i<C;i++) for(int j=1;j<=b;j++) check2[i][j] = -1;
	 
	printf("%d",func2((1<<b)-1,1));
}