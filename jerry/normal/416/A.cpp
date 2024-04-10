#include <cstdio>

int lessSmall;
int greatBig;
int n;
char temp[8];
int a;
char boolean;

int max(int x, int y) { return ((x>y)?x:y); }
int min(int x, int y) { return ((x<y)?x:y); }

int main()
{
    lessSmall = 2000000000;
    greatBig = -2000000000;
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
    {
        scanf(" %s %d %c", temp, &a, &boolean);
        if (boolean == 'N')
        {
            temp[0] = (temp[0] == '>') ? '<' : '>';
            temp[1] = (temp[1] == 0) ? '=' : 0;
        }
        if (temp[0] == '>')
        {
            greatBig = max(a, greatBig);
            if (temp[1] == 0)
                greatBig = max(a+1, greatBig);
        } else
        {
            lessSmall = min(a, lessSmall);
            if (temp[1] == 0)
                lessSmall = min(a-1, lessSmall);
        }
    }
    if (greatBig > lessSmall)
        printf("Impossible\n");
    else    printf("%d\n", lessSmall);
    return 0;
}