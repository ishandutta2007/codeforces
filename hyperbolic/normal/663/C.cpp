#include <stdio.h>
#include <vector>
int R[100010],isRedOn[100010],numR=1,redSum;
int B[100010],isBlueOn[100010],numB=1,blueSum;
int check[100010],mode[100010],a;
int isPossible[5];
struct str{
    int node;
    int color;
};
str Str(int a, int b)
{
    str A;
    A.node = a;
    A.color = b;
    return A;
}
std::vector<str> V[100010];

int func(int s, int isChecked,int targetColor)
{
	int sum = 0;
    check[s] = isChecked;
    for(int i=0;i<V[s].size();i++)
    {
        if((mode[s]==2&&V[s][i].color==(3-targetColor))||(mode[s]==1&&V[s][i].color==targetColor))
        {
            if(check[V[s][i].node]==isChecked)
            {
                if(mode[V[s][i].node]==1);
                else isPossible[targetColor] = 1; // impossible
            }
            else
            {
                mode[V[s][i].node] = 1;
                sum+=func(V[s][i].node,isChecked,targetColor);
            }
        }
        else
        {
			if(check[V[s][i].node]==isChecked)
            {
                if(mode[V[s][i].node]==2);
                else isPossible[targetColor] = 1; // impossible
            }
            else
            {
                mode[V[s][i].node] = 2;
                sum+=func(V[s][i].node,isChecked,targetColor);
            }
        }
    }
    if(mode[s]==2) sum++;
    return sum;
}

void solve(int s, int targetColor)
{
    check[s] = 1;
    for(int i=0;i<V[s].size();i++)
    {
        if((mode[s]==2&&V[s][i].color==(3-targetColor))||(mode[s]==1&&V[s][i].color==targetColor))
        {
            if(check[V[s][i].node]==1);
            else
            {
                mode[V[s][i].node] = 1;
                solve(V[s][i].node,targetColor);
            }
        }
        else
        {
			if(check[V[s][i].node]==1);
            else
            {
                mode[V[s][i].node] = 2;
                solve(V[s][i].node,targetColor);
            }
        }
    }
    if(mode[s]==2) printf("%d ",s);
}
void solveRed();
void solveBlue();
int main()
{
    int b,c,d;
    char e;
    scanf("%d %d",&a,&b);
    for(int i=1;i<=b;i++)
    {
        scanf("\n%d %d %c",&c,&d,&e);
        if(e=='R')
        {
            V[c].push_back(Str(d,1));
            V[d].push_back(Str(c,1));
        }
        else
        {
            V[c].push_back(Str(d,2));
            V[d].push_back(Str(c,2));
        }
    }

    for(int i=1;i<=a;i++)
    {
        if(check[i]==0)
        {
            //Red
            mode[i] = 1;
            int s1 = func(i,1,1);
            mode[i] = 2;
            int s2 = func(i,2,1);
            if(s1<s2) isRedOn[numR] = 1;
            else isRedOn[numR] = 2;
            R[numR++] = s1<s2?s1:s2;

            //Blue
			mode[i] = 1;
            int s3 = func(i,3,2);
            mode[i] = 2;
            int s4 = func(i,4,2);
            if(s3<s4) isBlueOn[numB] = 1;
            else isBlueOn[numB] = 2;
            B[numB++] = s3<s4?s3:s4;
        }
    }
    for(int i=1;i<=a;i++) check[i] = 0;
    for(int i=1;i<numR;i++) redSum+=R[i];
    for(int i=1;i<numB;i++) blueSum+=B[i];
    if(isPossible[1]==1&&isPossible[2]==1)
    {
		printf("-1");
		return 0;
    }
    else if(isPossible[2]==1) solveRed();
    else if(isPossible[1]==1) solveBlue();
    else
    {
		if(redSum<blueSum) solveRed();
		else solveBlue();
    }
}
void solveRed()
{
	printf("%d\n",redSum);
	int s = 1;
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			mode[i] = isRedOn[s++];
			solve(i,1);
		}
	}
}
void solveBlue()
{
	printf("%d\n",blueSum);
	int s = 1;
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			mode[i] = isBlueOn[s++];
			solve(i,2);
		}
	}
}