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

int a[10+5];

int main()
{
	int CAS; scanf("%d",&CAS);
	while(CAS--)
    {
        int n; scanf("%d",&n);
        map<int,int> M;
        rep(i,1,n) scanf("%d",&a[i]),M[a[i]]++;
        int ans=0;
        rep(i,1,n)
        {
            if(M[a[i]]>1)
            {
                M[a[i]]--;
                a[i]=a[i]%1000;
                rep(j,0,9) if(M[a[i]+j*1000]==0)
                {
                    a[i]=a[i]+j*1000;
                    ans++;
                    M[a[i]]=1;
                    break;
                }
            }
        }
        printf("%d\n",ans);
        rep(i,1,n) printf("%04d\n",a[i]);
    }
	return 0;
}