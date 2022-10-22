#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)

#define N 100000
#define infty 0x3f3f3f3f

#define pb push_back
#define mp make_pair
#define xx first
#define yy second

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;

//head

int main()
{
	int CAS; scanf("%d",&CAS);
	while(CAS--)
    {
        int a[3]; rep(i,0,2) scanf("%d",&a[i]);
        sort(a,a+3);
        if(a[2]>=a[0]+a[1]) printf("%d\n",a[0]+a[1]);
        else printf("%d\n",(a[0]+a[1]+a[2])/2);
    }
	return 0;
}