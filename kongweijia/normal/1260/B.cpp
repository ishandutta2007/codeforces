#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)

#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int maxn=100000;
//head


int main()
{
    int CAS; scanf("%d",&CAS);
    while(CAS--)
    {
        ll a,b; scanf("%I64d%I64d",&a,&b);
        puts((a*2-b)%3==0 && (b*2-a)%3==0 && a*2>=b && b*2>=a? "YES" : "NO");
    }
	return 0;
}