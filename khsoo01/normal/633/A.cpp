#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a,b,c,cur,sum,first[105];
bool flag[105];

int main()
{
    scanf("%lld%lld%lld",&a,&b,&c);
    flag[0] = 1; first[0] = 0;
    if(a<b) swap(a,b);
    cur = b%a; sum = b;
    while(!flag[cur]) {
        flag[cur] = 1;
        first[cur] = sum;
        cur = (cur+b)%a; sum += b;
    }
    if(!flag[c%a] || first[c%a]>c) puts("No");
    else puts("Yes");
}