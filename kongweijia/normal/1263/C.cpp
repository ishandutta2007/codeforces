#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)

#define MAXN 100000
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

int a[MAXN+5];

int main()
{
	int CAS; scanf("%d",&CAS);
	while(CAS--)
    {
        int n; scanf("%d",&n);
        VI ans;
        ans.pb(0);
        int l=1,r;
        while(l<=n)
        {
            int val=n/l;
            ans.pb(val);
            r=n/val;
            l=r+1;
        }
        sort(ans.begin(),ans.end());
        int N=ans.size();
        printf("%d\n",N);
        rep(i,0,N-1) printf("%d%c",ans[i]," \n"[i==N-1]);
    }
	return 0;
}